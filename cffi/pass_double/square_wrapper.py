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
libfile = './libsquare'+ext
lib=ffi.dlopen(libfile)

# Wrapper for the C function 'square'
def square(x):
    return lib.square(x)

if __name__=='__main__':
    
    s=square(2)
    assert s==4
    print("Success: s={}".format(s))
