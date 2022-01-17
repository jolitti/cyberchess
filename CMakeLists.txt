cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS "-fPIC")
#set(CMAKE_C_FLAGS "-fPIC")

project(Cyberchess)
add_subdirectory(lib)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC Point)
target_link_libraries(main PUBLIC Board)
target_link_libraries(main PUBLIC Move)
target_link_libraries(main PUBLIC History)
target_link_libraries(main PUBLIC Movecalc)
