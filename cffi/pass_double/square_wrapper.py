from cffi import FFI

ffi=FFI()

ffi.cdef("""
double square(double);
""")

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

ext=get_sharedlib_extension()
lib=ffi.dlopen('./libsquare'+ext)

# Wrapper for the C function 'square'
def square(x):
    return lib.square(x)

if __name__=='__main__':
    
    print(square(2))
