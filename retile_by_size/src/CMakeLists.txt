
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_NAME})

add_executable(RetileBySize
    retile_by_size.cpp
    retile_las.h
    retile_las.cpp)

# Include directories
target_include_directories(RetileBySize PRIVATE
    ${THIRD_PARTY_DIR}/LAStools/LASlib/inc
    ${THIRD_PARTY_DIR}/LAStools/LASzip/src
)

# Link directories
target_link_directories(RetileBySize PRIVATE
    ${CMAKE_BINARY_DIR}/third_party/lib
)


target_link_libraries(RetileBySize
    LASlib)



# Set output directory
set_target_properties(RetileBySize PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
