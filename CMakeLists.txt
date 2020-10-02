cmake_minimum_required(VERSION 3.14)
project(zyklon_profiler
    VERSION         1.0.0
    DESCRIPTION     "simple profiling library for Zyklon"
    LANGUAGES       CXX
)

option(ZYKLON_PROFILER_OUTPUT_LIBRARY "Output zyklon library to CMAKE_SOURCE_DIR/bin" OFF)

set(SOURCES
    src/Timer.cpp
    src/Track.cpp
)

#----------------------------------------------------------
# STATIC LIBRARY VERSION
#----------------------------------------------------------
add_library(zyklon_profiler STATIC ${SOURCES})

set(EXAMPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/examples)
set(TARGET_EXAMPLES
    zprof_example01
)

set_target_properties(zyklon_profiler PROPERTIES
    LINKER_LANGUAGE CXX

    SOVERSION   ${PROJECT_VERSION_MAJOR}
    VERSION     ${PROJECT_VERSION}
)

if(${ZYKLON_PROFILER_OUTPUT_BIN_DIR})
    message("you have overriden ZYKLON_OUTPUT_BIN_DIR")
else()
    set(ZYKLON_PROFILER_OUTPUT_BIN_DIR "${CMAKE_SOURCE_DIR}/bin")
endif()

if(${ZYKLON_PROFILER_OUTPUT_BIN_DIR})
    set_target_properties(zyklon_profiler PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${ZYKLON_PROFILER_OUTPUT_BIN_DIR}/bin/zyklon_profiler-${CMAKE_BUILD_TYPE}"
        ARCHIVE_OUTPUT_DIRECTORY "${ZYKLON_PROFILER_OUTPUT_BIN_DIR}/bin/zyklon_profiler-${CMAKE_BUILD_TYPE}"
    )
endif()

target_include_directories(zyklon_profiler
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE     ${CMAKE_CURRENT_SOURCE_DIR}/vendor
)

target_link_libraries(zyklon_profiler
    PRIVATE      -lstdc++
)

#----------------------------------------------------------
# HEADER ONLY VERSION
#----------------------------------------------------------
add_library(zyklon_profiler_header_only INTERFACE)

target_include_directories(zyklon_profiler_header_only INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#----------------------------------------------------------
# BUILD EXAMPLES
#----------------------------------------------------------
option(ZYKLON_PROFILER_BUILD_EXAMPLES "Build zyklon_profiler examples for some testing" OFF)
if(ZYKLON_PROFILER_BUILD_EXAMPLES)
    foreach(EXAMPLE ${TARGET_EXAMPLES})
        add_executable(${EXAMPLE} "${EXAMPLE_DIR}/${EXAMPLE}.cpp")
        target_link_libraries(${EXAMPLE} 
            PRIVATE     zyklon_profiler
            PRIVATE     -lstdc++
        )
        set_target_properties(${EXAMPLE} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY    "${CMAKE_CURRENT_SOURCE_DIR}/bin"
        )
    endforeach()
endif()