cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-fPIC")
set(CMAKE_C_FLAGS "-fPIC")

project(Cyberchess)
add_subdirectory(lib)

add_executable(scacchiera mainScacchiera.cpp)

target_link_libraries(scacchiera PUBLIC Point)
target_link_libraries(scacchiera PUBLIC Board)

#Add moves libraries as they get written
target_link_libraries(scacchiera PUBLIC Move)
target_link_libraries(scacchiera PUBLIC Capture)
target_link_libraries(scacchiera PUBLIC EnPassant)
target_link_libraries(scacchiera PUBLIC Promotion)

target_link_libraries(scacchiera PUBLIC History)
target_link_libraries(scacchiera PUBLIC Movecalc)

target_link_libraries(scacchiera PUBLIC Bot)
target_link_libraries(scacchiera PUBLIC Human)
