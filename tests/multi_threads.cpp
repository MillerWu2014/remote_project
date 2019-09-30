#include <iostream>
#include <Python.h>
#include "pybind11/pybind11.h"

namespace py = pybind11;

unsigned long loop_add(void){
    int i = 0, j = 0;
    unsigned long r = 0;
    while (true){

    }
    return r;
}

py::int_ thread(){
    int i = 0, j = 0;
    unsigned long r = 0;
    // py::gil_scoped_release release;
    while (true){

    }
    // py::gil_scoped_acquire acquire;
    return py::int_(r);
}


PYBIND11_MODULE(multi_threads, m){
    m.attr("__version__") = "0.0.1_rc01";
    m.def("thread", &thread, py::call_guard<py::gil_scoped_release>(), "release gil scope by pybind11.");
}

// g++ -O3 -Wall -shared -pthread -std=c++11 -fPIC `python3 -m pybind11 --includes` multi_threads.cpp -o multi_threads`python3-config --extension-suffix`