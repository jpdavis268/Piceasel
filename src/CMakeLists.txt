add_executable(Piceasel)

if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    target_compile_options(Piceasel PRIVATE -Wall)
elseif((CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") OR (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    target_compile_options(Piceasel PRIVATE /W3)
endif()

# This ensures both the binary and data files are in a clear location.
set_target_properties(Piceasel
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

target_sources(Piceasel
    PRIVATE
        MainLauncher.cpp
)