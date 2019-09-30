from distutils.core import setup, Extension

from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
from Cython.Build import cythonize

setup(
    name='haversion haversin extension module',
    cmdclass={'build_ext': build_ext},
    ext_modules=cythonize(
        [
            Extension('cy_thread', ['cy_thread.pyx'], library_dirs=['.'])
        ],
        compiler_directives={'language_level': "3"}
    )
)