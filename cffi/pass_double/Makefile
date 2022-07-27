# Linux
#LIB_EXT = so

# OSX
LIB_EXT = dylib

# Windows
#LIB_EXT = dll

all: libsquare.${LIB_EXT}

libsquare.${LIB_EXT}: square.c
	gcc -shared -fpic $< -o $@
