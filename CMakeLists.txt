cmake_minimum_required(VERSION 4.3.4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Piceasel)

if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    add_compile_options(-Wall)
elseif((CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") OR (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    add_compile_options(/W3)
endif()

# Third Party Libraries
add_subdirectory(thirdparty/glfw)
include_directories(thirdparty/glfw/include)

add_subdirectory(src)
add_subdirectory(tests)