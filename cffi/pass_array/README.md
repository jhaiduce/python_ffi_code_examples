# Passing doubles with CFFI

This example shows how to call C and Fortran procedures from a previously-compiled shared library using the CFFI module. The example consists of two shared libraries, one in C and one in Fortran. The C and Fortran libraries both contain a function `square` which accepts a double-precision float and computes the square of its input. The python script `square_wrapper.py` loads each of these libraries in turn and tests that they work.

## To build the examples using CMake (recommended)

In most cases, CMake automatically detects the OS and compilers, in which case the following commands will be enough to build the examples and check that they work:

```
mkdir build
cd build
cmake ..
make
python square_wrapper.py
```

If successful, the last command should output `Success: s=4.0` twice (once for each shared library).

##To build the examples using Make

The libraries can also be built using Make directly instead of CMake, but this is less portable because Make lacks the ability to automatically detect the operating system and compiler.

First, hand edit the Makefile by making sure the correct value of LIB_EXT is specified for the operating system.

The Makefile assumes that gcc and gfortran are installed and in $PATH. If the compiler commands are different from this, hand editing of the compiler commands will be necessary.

After editing the Makefile, the libraries can be built anad tested by running the following from the source directory:

```
make
python square_wraapper.py
```
