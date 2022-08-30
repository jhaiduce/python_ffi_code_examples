cmake_minimum_required(VERSION 3.9.5)

project(square)

add_library(square SHARED square.c)

add_library(square_f SHARED square.f90)

configure_file(square_wrapper.py square_wrapper.py COPYONLY)
