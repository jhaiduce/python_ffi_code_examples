cmake_minimum_required(VERSION 3.9.5)

project(square)

find_package(Python 3.5 COMPONENTS Development REQUIRED)

add_library(square MODULE square.c)

set_target_properties(
  square
  PROPERTIES
      PREFIX ""
      OUTPUT_NAME "square"
      LINKER_LANGUAGE C
  )

target_link_libraries(square Python::Module)

enable_testing()
add_test(test_square ${PYTHON_EXECUTABLE} -c
  "from square import square; \
   y=square(2.0); \
   assert y==4.0")


add_custom_target(run_tests ALL DEPENDS square)
add_custom_command(
     TARGET run_tests
     POST_BUILD
     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
     COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -C $<CONFIGURATION>
)
