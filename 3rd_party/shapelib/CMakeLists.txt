cmake_minimum_required(VERSION 3.20)

project(shapelib)

# Shapelib source files
set(SHAPELIB_SOURCES
    dbfopen.c
    shpopen.c
    safileio.c
)

# Create static library
add_library(shp STATIC ${SHAPELIB_SOURCES})

# Include current directory for headers
target_include_directories(shp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Set output properties
set_target_properties(shp PROPERTIES
    OUTPUT_NAME shp
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
