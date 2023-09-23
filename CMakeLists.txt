cmake_minimum_required(VERSION 3.5)

project(conway)

file(GLOB SOURCES
    *.h
    *.cpp
)

add_executable(conway ${SOURCES})

target_compile_features(conway PRIVATE cxx_std_23)
target_compile_options(conway PRIVATE -Wall -pedantic)
target_link_options(conway PRIVATE -Wl,-ld_classic) 
