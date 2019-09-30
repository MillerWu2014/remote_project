#include "Python.h"

int func(int size){
    int  k = size;
    while (k > 0){
        printf("%d\n", k++);
    }
    return 0;
}

void test(int size, int *y){
    Py_BEGIN_ALLOW_THREADS
    int x = func(size);
    *y = x;
    Py_END_ALLOW_THREADS
}

PyObject* wapper_func(PyObject *self, PyObject *args){

    int size;
    if(!PyArg_ParseTuple(args, "i", &size))
        return NULL;
    int *y = (int *)malloc(sizeof(int));

    test(size, y);
    PyObject *object = Py_BuildValue("i", *y);
    return object;
}

static char docs[] =
        "wapper_func(size: int): add all elements of the list\n";

static PyMethodDef funcs[] = {
        {"wapper_func", (PyCFunction)wapper_func, METH_VARARGS, docs},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "multhreading",
        NULL,
        -1,
        funcs,
        NULL,
        NULL,
        NULL,
        NULL
};

static PyObject *SpamError = NULL;


PyMODINIT_FUNC PyInit_multhreading(void){
    PyObject *m;
    m = PyModule_Create(&moduledef);
    if (m == NULL)
        return NULL;
    SpamError = PyErr_NewException("multhreading.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
    return m;
}
