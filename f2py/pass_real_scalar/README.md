# Passing scalars with f2py

This example shows how to create a Python extension module that accepts scalars by wrapping Fortran code using f2py. The example wraps a procedure `square` that computes the square of its input.

To build and install the example, run `python setup.py install` or `pip install .`.

The extension module can also be compiled directly using f2py:

`f2py -m square -c square.f90`

To run the example after building, do `python test_square.py`
