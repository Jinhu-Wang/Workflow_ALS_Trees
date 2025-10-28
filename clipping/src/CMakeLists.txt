cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})

# Add executable
add_executable(ClipLas
    main.cpp 
    clip_las.cpp
)

# Include directories
target_include_directories(ClipLas PRIVATE
    ${THIRD_PARTY_DIR}/LAStools/LASlib/inc
    ${THIRD_PARTY_DIR}/LAStools/LASzip/src
    ${THIRD_PARTY_DIR}/shapelib
)

# Link directories
target_link_directories(ClipLas PRIVATE
    ${CMAKE_BINARY_DIR}/third_party/lib
)

# Link libraries - now only LASlib and shp
target_link_libraries(ClipLas
    LASlib
    shp
)

# Set output directory
set_target_properties(ClipLas PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)