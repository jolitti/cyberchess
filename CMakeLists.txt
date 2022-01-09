cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Cyberchess)
add_subdirectory(lib)
add_subdirectory(lib/point)
add_subdirectory(lib/piece)
add_subdirectory(lib/board)
add_subdirectory(lib/move)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC Point)
target_link_libraries(main PUBLIC Pawn)
target_link_libraries(main PUBLIC Move)