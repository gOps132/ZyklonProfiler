cmake_minimum_required(VERSION 3.14)
project(zyklon_profiler
    VERSION         1.0.0
    DESCRIPTION     "simple profiling library for Zyklon"
    LANGUAGES       CXX
)

option(ZYKLON_PROFILER_BUILD_EXAMPLES   OFF)

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

# build examples
if(ZYKLON_PROFILER_BUILD_EXAMPLES)
    foreach(EXAMPLE ${TARGET_EXAMPLES})
        add_executable(${EXAMPLE} "${EXAMPLE_DIR}/${EXAMPLE}.cpp")
        # set_target_properties(${EXAMPLE} PROPERTIES)
        target_link_libraries(${EXAMPLE} 
            PRIVATE zyklon_profiler
        )
    endforeach()
endif()

set_target_properties(zyklon_profiler PROPERTIES
    LINKER_LANGUAGE CXX

    SOVERSION   ${PROJECT_VERSION_MAJOR}
    VERSION     ${PROJECT_VERSION}

    LIBRARY_OUTPUT_DIRECTORY    "${ZYKLON_OUTPUT_BIN_DIR}/zyklon_profiler-${CMAKE_BUILD_TYPE}"
    ARCHIVE_OUTPUT_DIRECTORY    "${ZYKLON_OUTPUT_BIN_DIR}/zyklon_profiler-${CMAKE_BUILD_TYPE}"
)

target_include_directories(zyklon_profiler
    PUBLIC      ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE      ${CMAKE_CURRENT_SOURCE_DIR}/vendor
)

#----------------------------------------------------------
# HEADER ONLY VERSION
#----------------------------------------------------------
add_library(zyklon_profiler_header_only INTERFACE)

target_include_directories(zyklon_profiler_header_only INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
