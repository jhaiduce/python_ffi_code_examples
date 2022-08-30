

def get_sharedlib_extension():
    import os
    import sys

    is_windows = os.name == "nt"
    is_apple = sys.platform == "darwin"
    if is_windows:
        ext = ".dll"
    elif is_apple:
        ext = ".dylib"
    else:
        ext = ".so"

    return ext

def load_lib(libname):
    from cffi import FFI

    ffi=FFI()

    ffi.cdef("""
    double square(double*, double*, int);
    """)

    ext=get_sharedlib_extension()
    lib=ffi.dlopen('./lib'+libname+ext)

    return lib

# Wrapper for the C function 'square'
def square(lib,x):

    from cffi import FFI

    ffi=FFI()

    import numpy as np

    input_arr = np.ascontiguousarray(
                    x,
                    dtype=np.double)
    output_arr = np.ascontiguousarray(
                    np.empty(input_arr.shape),
                    dtype=np.double)

    input_ptr = ffi.cast(
                    'double*',
                    input_arr.ctypes.data)
    output_ptr = ffi.cast(
                    'double*', output_arr.ctypes.data)

    lib.square(input_ptr, output_ptr, input_arr.size)

    return output_arr

if __name__=='__main__':

    for libname in 'square','square_f':

        lib=load_lib(libname)

        s = square(lib,[2,3,4])

        assert list(s)==[4,9,16]
        print("Success: s={}".format(s))
