enable_testing()

add_executable(PiceaselTests)

target_sources(PiceaselTests
    PRIVATE
        TestRunner.cpp
)

target_link_libraries(PiceaselTests
    PRIVATE
        PiceaselLib
)

function(unitTest name)
    add_test(
        NAME ${name}
        COMMAND PiceaselTests ${name}
    )
endfunction()

# Unit tests
unitTest(smokeTest)