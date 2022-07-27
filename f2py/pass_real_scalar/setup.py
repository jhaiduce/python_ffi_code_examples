from numpy.distutils.core import setup, Extension

square = Extension('square',
                    sources = ['square.f90'])

setup (name = 'square',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [square])
