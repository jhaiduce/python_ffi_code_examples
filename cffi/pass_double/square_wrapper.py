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
    double square(double);
    """)

    ext=get_sharedlib_extension()
    libfile = './lib'+libname+ext
    lib=ffi.dlopen(libfile)

    return lib

# Wrapper for the C function 'square'
def square(lib,x):
    return lib.square(x)

if __name__=='__main__':
    

    for libname in 'square','square_f':
        lib=load_lib(libname)

        s=square(lib,2)
        assert s==4
        print("Success: s={}".format(s))
