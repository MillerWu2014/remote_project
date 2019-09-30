import pickle

file_path = "/opt/workspace/project/OptimizerDataForecast-v1.2.1/source/tmp/all_variables_date.index"
with open(file_path, "rb") as buff:
    data = pickle.load(buff)

print(data.columns)
print(data[['evi', 'lai', 'lc', 'lst', 'nvdi', 'refl', 'noaa']].tail(10))

