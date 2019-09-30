#include "pybind11/pybind11.h"
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <vector>


namespace py = pybind11;
using namespace std;

vector<double> to_array(const vector<double> &input){
    return input;
}


PYBIND11_MODULE(example, m){
    m.def("to_array", &to_array, "transform vector to array!");
    py::object x = py::int_(10);
    m.attr("x") = x;
}

//g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example_vector_array.cpp -o example`python3-config --extension-suffix`
