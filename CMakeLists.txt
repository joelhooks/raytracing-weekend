cmake_minimum_required(VERSION 3.20)
project(imagezoo)

set(CMAKE_CXX_STANDARD 23)

add_executable(imagezoo main.cpp vec3.h color.h ray.h hittable.h sphere.h hittable_list.h utils.h)
