cmake_minimum_required(VERSION 3.0.0)
project(awesome_demo VERSION 0.1.0)

include(CTest)
enable_testing()

set(source 
    src/Awesome.cpp
    src/main.cpp)

add_executable(awesome_demo ${source})

target_include_directories(awesome_demo
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
