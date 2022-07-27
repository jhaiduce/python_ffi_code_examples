cmake_minimum_required(VERSION 3.9.5)

project(square)

add_library(square SHARED square.c)

configure_file(square_wrapper.py square_wrapper.py COPYONLY)
