cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

project(Imac1S2)

function(add_exercise FOLDER)
    file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS ${FOLDER}/*.cpp)
    set(PROJECT_INCLUDE ${FOLDER}/)

    add_executable(${FOLDER})
    target_sources(${FOLDER} PRIVATE ${PROJECT_SOURCES})
endfunction(add_exercise)


add_exercise(Exercice1)
add_exercise(Exercice2)


