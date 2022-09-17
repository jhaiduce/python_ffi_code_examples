# Passing arrays with f2py

This example shows how to create a Python extension module that accepts arrays by wrapping Fortran code using f2py. The example wraps a procedure `square` that squares the elements of an input array and stores the result in an output array.

To build and install the example, run `python setup.py install` or `pip install .`.

The extension module can also be compiled directly using f2py:

`f2py -m square -c square.f90`

To run the example after building, do `python test_square.py`