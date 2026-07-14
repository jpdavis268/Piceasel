enable_testing()

add_executable(PiceaselTests)

if((CMAKE_CXX_COMPILER_ID STREQUAL "GNU") OR (CMAKE_CXX_COMPILER_ID MATCHES "Clang"))
    target_compile_options(PiceaselTests PRIVATE -Wall)
elseif((CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") OR (CMAKE_CXX_COMPILER_FRONTEND_VARIANT STREQUAL "MSVC"))
    target_compile_options(PiceaselTests PRIVATE /W3)
endif()

target_sources(PiceaselTests
    PRIVATE
        TestRunner.cpp
)

function(unitTest name)
    add_test(
        NAME ${name}
        COMMAND PiceaselTests ${name}
    )
endfunction()

# Unit tests
unitTest(smokeTest)