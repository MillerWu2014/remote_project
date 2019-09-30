#include <thread>
#include "pybind11/pybind11.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#define NUM_THREADS 50

using namespace std;
namespace py = pybind11;

void f(){
    while(1){
        continue;
    }
}

py::none nothing(){
    std::thread threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        threads[i] = std::thread(f);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads[i].join();

    }
    return py::none();
}

PYBIND11_MODULE(example, m){
    m.def("nothing", &nothing, "do nothing");
}


