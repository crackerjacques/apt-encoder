cmake_minimum_required(VERSION 3.10)
project(apt_encoder C)

set(CMAKE_C_STANDARD 99)
add_compile_options(-Wall)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_subdirectory(image)
add_subdirectory(aptcode)
add_subdirectory(apt-encoder)
add_subdirectory(apt-colorm)
add_subdirectory(img-table)
