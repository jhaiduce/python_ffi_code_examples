# Passing arrays via the Python C API

This example shows how to create a Python extension module that accepts floating point numbers using the Numpy C API. The example wraps a function `square` that squares the elements of an input array and stores the result in an output array.

To build and install the example, run `python setup.py install` or `pip install .`.

To run the example after building, do `python test_square.py`
