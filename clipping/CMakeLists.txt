cmake_minimum_required(VERSION 3.20)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME})

# Set the 3rd party directories relative to project root
get_filename_component(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/.. ABSOLUTE)
set(THIRD_PARTY_DIR ${PROJECT_ROOT}/3rd_party)

# Build third-party libraries first
add_subdirectory(${THIRD_PARTY_DIR} ${CMAKE_BINARY_DIR}/third_party)

# Add compile definitions
add_compile_definitions("DATA_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}/data\"")

# Add subdirectory for source code
add_subdirectory(src)