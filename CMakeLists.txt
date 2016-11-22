cmake_minimum_required(VERSION 2.8)
project(Bit_Plane_Slicing_Practic2)

find_package( OpenCV REQUIRED )
add_executable( main main.cpp )
target_link_libraries( main ${OpenCV_LIBS} )