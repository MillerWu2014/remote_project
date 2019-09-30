#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <stdio.h>
#include <math.h>

/* 使用c++实现python下numpy的快速计算. 通过pybind11和numpy结合应用, 实现共享包, 编译后将该包导入到项目的目录下即可.
 * 编译: g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` SlopeAspect.cpp -o slope`python3-config --extension-suffix`
 * 环境依赖: pybind11, conda install -c conda-forge pybind11; 设置环境变量: export CPATH="PYTHON_INCLUDE_PATH:$CPATH"
 * gcc和g++环境依赖
 */
#define POW2(x) pow(x, 2)
#define RAD 57.29578

namespace py = pybind11;

typedef struct limit_size {
    int x;
    int y;
} LimitSize;

LimitSize *setSize(int v, int limit){
    LimitSize *data = (LimitSize *)malloc(sizeof(LimitSize));
    if (v == 0) {
        data->x = v, data->y = v + 1;;
    } else if (v == (limit-1)){
        data->x = v - 1, data->y = v;
    } else {
        data->x = v - 1, data->y = v + 1;
    }
    return data;
}

py::tuple comp_slope_xy(py::array_t<double> input_dem_array, int cell_size){
    /*计算在南北和东西方向上的高度差值, 计算公式参考arcgis中坡度和坡向的计算方式.具体可以参考设计文档中的arcgis引用.
    * 返回: dx, dy: 在东西(we)和南北(ns)上的高度差值*/
    py::buffer_info dem_array_buf = input_dem_array.request();

    if (dem_array_buf.ndim !=2){
        throw std::runtime_error("input numpy ndarray ndim is not equal 2.");
    }

    auto result1 = py::array_t<double>(dem_array_buf.size),
         result2 = py::array_t<double>(dem_array_buf.size);

    result1.resize({dem_array_buf.shape[0], dem_array_buf.shape[1]});
    py::buffer_info result1_buff = result1.request();

    result2.resize({dem_array_buf.shape[0], dem_array_buf.shape[1]});
    py::buffer_info result2_buff = result2.request();

    double *dem_ptr = (double *)dem_array_buf.ptr,
           *res1_ptr = (double *)result1_buff.ptr,
           *res2_ptr = (double *)result2_buff.ptr;

    py::tuple data(2);

    for (int i=0; i<dem_array_buf.shape[0]; i++){
        LimitSize *s1 = setSize(i, dem_array_buf.shape[0]);
        int m = s1->x, n = s1->y;
        for (int j=0; j<dem_array_buf.shape[1]; j++){
            LimitSize *s2 = setSize(j, dem_array_buf.shape[1]);
            int x = s2->x, y = s2->y;

            auto v1 = 2 * dem_ptr[i*dem_array_buf.shape[1]+y] + dem_ptr[m*dem_array_buf.shape[1]+y] + \
                      dem_ptr[n*dem_array_buf.shape[1]+y],
                    v2 = 2 * dem_ptr[i*dem_array_buf.shape[1]+x] + dem_ptr[m*dem_array_buf.shape[1]+x] + \
                      dem_ptr[n*dem_array_buf.shape[1]+x];
            res1_ptr[i*dem_array_buf.shape[1]+j] = (v1 - v2) / (8 * cell_size);

            auto v3 = 2 * dem_ptr[n*dem_array_buf.shape[1]+j] + dem_ptr[n*dem_array_buf.shape[1]+x] + \
                      dem_ptr[n*dem_array_buf.shape[1]+y],
                    v4 = 2 * dem_ptr[m*dem_array_buf.shape[1]+j] + dem_ptr[m*dem_array_buf.shape[1]+x] + \
                      dem_ptr[m*dem_array_buf.shape[1]+y];
            res2_ptr[i*dem_array_buf.shape[1]+j] = (v3 - v4) / (8 * cell_size);
            free(s2);
        }
        free(s1);
    }
    data[0] = result1, data[1] = result2;
    return data;
}


py::array_t<double> compute_slope(py::array_t<double> slope_x, py::array_t<double> slope_y){
    py::buffer_info slope_x_buff = slope_x.request(),
                    slope_y_buff = slope_y.request();

    if (slope_x_buff.size != slope_y_buff.size){
        throw std::runtime_error("The slope of x and y size is not equal!");
    }
    if (slope_x_buff.ndim != slope_y_buff.ndim){
        std::runtime_error("The slope of x and y n-dim is not equal!");
    }

    auto result = py::array_t<double>(slope_x_buff.size);
    result.resize({slope_x_buff.shape[0], slope_x_buff.shape[1]});
    py::buffer_info res_buff = result.request();

    double *x_buff_ptr = (double *)slope_x_buff.ptr,
           *y_buff_ptr = (double *)slope_y_buff.ptr,
           *res_buff_ptr = (double *)res_buff.ptr;
    for (int i=0; i<slope_x_buff.shape[0]; ++i){
        for (int j=0; j<slope_x_buff.shape[1]; ++j){
            int index = i * slope_x_buff.shape[1] + j;
            res_buff_ptr[index] = RAD * (double)atan(sqrt(POW2(x_buff_ptr[index]) + POW2(y_buff_ptr[index])));
        }
    }
    return result;
}

py::array_t<double> compute_aspect(py::array_t<double> slope_x, py::array_t<double> slope_y){
    py::buffer_info slope_x_buf = slope_x.request(),
                    slope_y_buf = slope_y.request();
    if ((slope_x_buf.size != slope_y_buf.size) || (slope_x_buf.ndim != slope_y_buf.ndim)){
        throw std::runtime_error("The input array size and ndim is not same.");
    }

    auto result = py::array_t<double>(slope_x_buf.size);
    result.resize({slope_x_buf.shape[0], slope_x_buf.shape[1]});
    py::buffer_info result_buf = result.request();
    double *r_buf_ptr = (double *)result_buf.ptr,
           *x_buf_ptr = (double *)slope_x_buf.ptr,
           *y_buf_ptr = (double *)slope_y_buf.ptr;

    for (int i=0; i<slope_x_buf.shape[0]; ++i){
        for (int j=0; j<slope_x_buf.shape[1]; ++j){
            int index = i * slope_x_buf.shape[1] + j;
            double _aspect = RAD * (double)atan2(y_buf_ptr[index], x_buf_ptr[index]);
            if (_aspect < 0){
                _aspect = 90 - _aspect;
            } else if (_aspect > 90.0){
                _aspect = 360.0 - _aspect + 90.0;
            } else {
                _aspect = 90.0 - _aspect;
            }
            r_buf_ptr[index] = _aspect;
        }
    }
    return result;
}

PYBIND11_MODULE(slope, m) {
    m.doc() = "complete slope and aspect!";
    m.def("compete_slope_xy", &comp_slope_xy);
    m.def("compute_slope", &compute_slope);
    m.def("compute_aspect", &compute_aspect);
}
