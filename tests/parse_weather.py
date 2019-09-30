#!/opt/anaconda3/bin/python3
# -*- coding: utf-8 -*-
# --------------------------------------------------------------------------------
# 主要目的 :解析"中国天气网"的天气数据
#
# 输出    :天气信息的字典
# 作者    :pengyu
# 日期    :2017/11/20
# 记录    :包含修改时间、修改人、修改line及原因
# --------------------------------------------------------------------------------
from lxml import etree
from datetime import datetime
from selenium import webdriver
from selenium.webdriver.firefox.options import Options
import json


def weather_parse(html):
    tree = etree.HTML(html)
    currentweather = {}

    s = tree.xpath('//div[@class="weather_location"]/div/a/text()')
    name = '-'.join([i for i in s if '\n' not in i])

    _curr_date = datetime.now().date()
    update_time = "{0}{1}{2}".format(_curr_date.year, _curr_date.month, _curr_date.day)

    script = tree.xpath('//div[@class="weather_7d"]//script')  # 获取scripts中的值
    r = []
    for s in script[0].text.split("var "):
        if "=" not in s:
            continue
        v = s.split("=")[-1].strip().strip(";")
        r.append(eval(v))  # 解析scripts中的值
    res_dict = dict(zip(["forecast_seven_days", 'event_day', 'event_might'], r))

    # 获取当前日期后的气象预报日期
    weather_7d_uls = tree.xpath('//div[@class="weather_7d"]//ul[@class="date-container"]/li/p')
    date_array, date_labels = list(), list()
    i = 1
    for day in weather_7d_uls:
        if i % 2 == 0:
            date_labels.append(day.text)
        else:
            date_array.append(day.text)
        i += 1

    result_dict = dict()
    for d, s in zip(date_array, date_labels):
        result_dict["{:0>2}".format(d[:-1])] = {'label': s}

    # 获取天气情况和风力等级
    weather_7d_backccc = tree.xpath('//div[@class="weather_7d"]//ul[@class="blue-container backccc"]/li//p')
    day_weather_info, one_day_weahter = [], []
    k = 1
    for li in weather_7d_backccc:
        string = li.text
        if string is None or string.strip() == '':
            continue
        else:
            one_day_weahter.append(string.strip())
            if k % 2 == 0:
                day_weather_info.append(one_day_weahter)
                one_day_weahter = []
            k += 1

    # 获取两个风向值
    wind_xPath = '//div[@class="weather_7d"]//ul[@class="blue-container backccc"]/li//div/i'
    weather_7d_wind_dir = tree.xpath(wind_xPath)

    wind_info_list = None
    if (len(weather_7d_wind_dir)/2) == len(date_array):
        wind_info_list = [
            "/".join(list(map(lambda w: w.xpath('@title')[0], weather_7d_wind_dir[i: i+2]))) 
            for i in range(0, len(weather_7d_wind_dir), 2)
        ]

    if wind_info_list is not None:
        if len(day_weather_info) == len(date_array):
            # 将风向和天气情况,风力情况进行合并
            for index, weather, wind in zip(range(len(date_array)), day_weather_info, wind_info_list):
                weather.append(wind)
                result_dict["{:0>2}".format(date_array[index][:-1])]["summary"] = weather
    elif len(day_weather_info) == len(date_array):
        for i, weather_v in enumerate(day_weather_info):
            weather_v.appen("")
            result_dict["{:0>2}".format(date_array[index][:-1])]["summary"] = weather_v

    # 获取白天温度和晚上温度值
    event_temp = res_dict.get('event_day', None)
    night_temp = res_dict.get('event_might', None)
    if event_temp and len(event_temp)==len(date_array):
        for d, s1, s2 in zip(date_array, event_temp, night_temp):
            result_dict["{:0>2}".format(d[:-1])]["summary"].append(s1)
            result_dict["{:0>2}".format(d[:-1])]["summary"].append(s2)

    if len(res_dict.get('forecast_seven_days')) == (len(date_array)-1):
        for i, day_forecast in enumerate(res_dict.get('forecast_seven_days')):
            result_dict["{:0>2}".format(date_array[i + 1][:-1])]['forecast'] = {}
            for t_dict in day_forecast:
                result_dict["{:0>2}".format(date_array[i + 1][:-1])]['forecast'][t_dict["jf"]] = t_dict['jb']
    else:
        for i, day_forecast in enumerate(res_dict.get('forecast_seven_days')):
            result_dict["{:0>2}".format(date_array[i + 1][:-1])]['forecast'] = ''
    currentweather.update(result_dict)

    # 获取气象的适宜环境情况
    life_title = []
    life = {}
    for i in tree.xpath('//div[@class="weather_shzs"]/ul/li'):
        life_title += i.xpath('./h2/text()')
    results = tree.xpath('//div[@class="lv"]/dl')
    for i in range(len(life_title)):
        life[life_title[i]] = results[i].xpath('.//em/text()')+results[i].xpath('./dd/text()')
    return json.dumps({'name': name, 'date': update_time, 'weather': currentweather, 'life_assistant': life})


if __name__ == '__main__':
    url = 'http://forecast.weather.com.cn/town/weathern/101270503.shtml'
    
    options = Options()
    options.headless = True
    options.set_preference('permissions.default.image', 2)
    # options.set_preference("general.useragent.override", user_agent)
    driver = webdriver.Firefox(options=options, executable_path="/opt/sihan/geckodriver")
    driver.set_page_load_timeout(5)
    driver.set_script_timeout(5)
    driver.get(url)
    page = driver.page_source
    # print(page)
    with open("./page.html", "w") as writer:
        writer.write(page)
    results = weather_parse(page)
    print(results)
