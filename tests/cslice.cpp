#include <iostream>
#include "Python.h"
#include "pybind11/pybind11.h"
#include "pybind11/numpy.h"


namespace py = pybind11;

py::array_t<double> crop_sub_array(py::array_t<double> input_tensor, 
                                   py::array_t<double> input_pad_tensor, 
                                   int filter_size)
{
    py::buffer_info buf1 = input_tensor.request(), pad_buf = input_pad_tensor.request();
    if (buf1.ndim != 2 || pad_buf.ndim != 2){
        throw std::runtime_error("inpute array ndim is not equal 2.");
    }

    int m = buf1.shape[0], n = buf1.shape[1], height = 2 * filter_size + 1;
    // define output numpy array 
    py::array_t<double> out = py::array_t<double>(buf1.size * height * height);
    out.resize({m * n, height, height});
    py::buffer_info out_buff = out.request();
    if (m < filter_size || m < filter_size){
        throw std::logic_error("filter size must less than input array shape.");
    }
    int i =0, j = 0, new_pos_x = 0, new_pos_y = 0, k =0, w = 0;
    double *pad_buff_ptr = (double *)pad_buf.ptr,
           *out_ptr = (double *)out_buff.ptr;
    Py_BEGIN_ALLOW_THREADS
    for (i=0; i<m; i++){
        for (j=0; j<n; j++){
            int axis_1_pos = i * n + j;
            new_pos_x = i + filter_size;
            new_pos_y = j + filter_size;
            for (k = new_pos_x - filter_size; k < new_pos_x + filter_size + 1; k++){
                for (w = new_pos_y - filter_size; w < new_pos_y + filter_size + 1; w++){
                    int p = k - new_pos_x + filter_size;
                    int q = w - new_pos_y + filter_size;
                    out_ptr[axis_1_pos * height * height + p * height + q] = pad_buff_ptr[k * (n + 2 * filter_size) + w];
                }
            }
        }
    }
    Py_END_ALLOW_THREADS
    return out;
}


PYBIND11_MODULE(cslice, m){
    m.doc() = "using c++ and numpy combine slice sub-array.";
    m.def("crop_sub_array", &crop_sub_array, "crop sub-array from input 2d-array and size.");
 }

// g++ -O3 -Wall -shared -pthread -std=c++11 -fPIC `python3 -m pybind11 --includes` cslice.cpp -o cslice`python3-config --extension-suffix`
