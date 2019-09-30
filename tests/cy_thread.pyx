cimport cython

cdef int f() nogil:
    cdef int i = 0, j = 0
    while 1:
        continue
    return i

def thread():
    cdef int x
    with nogil:
        x = f()
    return x