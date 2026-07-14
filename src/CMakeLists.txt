add_library(PiceaselLib)

target_sources(PiceaselLib
    PRIVATE
        core/Session.cpp
        util/Logger.cpp
    
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ../include
)

add_executable(Piceasel)

set_target_properties(Piceasel
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}
)

target_sources(Piceasel PRIVATE MainLauncher.cpp)

target_link_libraries(Piceasel
    PRIVATE
        PiceaselLib
)