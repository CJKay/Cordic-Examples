################################################################################
# Build the Cordic usage examples.                                             #
################################################################################

cmake_minimum_required(VERSION "3.0")

project("Cordic Examples" VERSION 1.0.0.0)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include("AddPrefix")

find_package("Cordic" 1.0 EXACT REQUIRED)

file(GLOB examples "examples/*")
foreach(example ${examples})
    if(IS_DIRECTORY "${example}")
        get_filename_component(name "${example}" NAME)

        unset(sources)

        add_subdirectory("${example}")
        add_prefix(sources "${example}/" ${sources})
        add_executable("${name}" ${sources})
        target_include_directories("${name}" PUBLIC ${CORDIC_INCLUDE_DIRS})
        target_link_libraries("${name}" ${CORDIC_LIBRARIES})
    endif()
endforeach()
