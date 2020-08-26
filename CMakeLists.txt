cmake_minimum_required(VERSION 3.14)
project(Zyklon_Profiler
    VERSION         1.0.0
    DESCRIPTION     "simple profiling library for Zyklon"
    LANGUAGES       CXX
)

option(ZYKLON_PROFILER_BUILD_EXAMPLES   OFF)

set(SOURCES
    src/Timer.cpp
    src/Track.cpp
)

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)
set(TARGET_EXAMPLES
    zprof_example01
)

# build examples
if(ZYKLON_PROFILER_BUILD_EXAMPLES)
    foreach(EXAMPLE ${TARGET_EXAMPLES})
        add_executable(${EXAMPLE} "${EXAMPLE_DIR}/${EXAMPLE}.cpp")
        # set_target_properties(${EXAMPLE} PROPERTIES)
        target_link_libraries(${EXAMPLE} 
            PRIVATE ${PROJECT_NAME}
        )
    endforeach()
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY    "${ZYKLON_OUTPUT_BIN_DIR}/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"

    SOVERSION   ${PROJECT_VERSION_MAJOR}
    VERSION     ${PROJECT_VERSION}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/include
)