cmake_minimum_required(VERSION 3.20)

project(LAStools)

# Find all source files from both LASlib and LASzip
file(GLOB LASLIB_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/LASlib/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LASlib/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/LASlib/src/*.cxx"
)

file(GLOB LASZIP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/LASzip/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/LASzip/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/LASzip/src/*.cxx"
)

# Combine all sources
set(ALL_SOURCES ${LASLIB_SOURCES} ${LASZIP_SOURCES})

# Create a single library
add_library(LASlib STATIC ${ALL_SOURCES})

# Include directories for both LASlib and LASzip
target_include_directories(LASlib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/LASlib/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/LASzip/src
)

# Set output properties
set_target_properties(LASlib PROPERTIES
    OUTPUT_NAME LASlib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

#message(STATUS "Building combined LAStools library with ${ALL_SOURCES}")
