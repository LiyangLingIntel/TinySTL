
cmake_minimum_required(VERSION 3.9)
PROJECT(TinySTL_RBTree)

INCLUDE_DIRECTORIES(include)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(extern/googletest)
ADD_SUBDIRECTORY(tests)
