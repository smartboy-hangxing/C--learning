cmake_minimum_required(VERSION 3.0.0)
project(test1 VERSION 0.1.0)

include_directories(./include/)

aux_source_directory(./src hello_src)
# add_executable(${PROJECT_NAME} ./src/main.cpp)
add_executable(test1 ${hello_src})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
