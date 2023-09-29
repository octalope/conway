cmake_minimum_required(VERSION 3.5)

project(conway)

add_executable(conway main.cpp point.cpp cell.cpp board.cpp)

target_compile_features(conway PRIVATE cxx_std_23)
target_compile_options(conway PRIVATE -Wall -pedantic)

target_include_directories(conway PRIVATE include)
target_link_options(conway PRIVATE -Wl,-ld_classic)
target_link_libraries(conway -lncurses)
