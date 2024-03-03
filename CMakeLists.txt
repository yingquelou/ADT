cmake_minimum_required(VERSION 3.5)

function(add_subs)
    file(GLOB DIRS LIST_DIRECTORIES TRUE *)
    foreach(dir ${DIRS})
        if(EXISTS ${dir}/CMakeLists.txt)
            add_subdirectory(${dir})
        endif()
    endforeach()
endfunction(add_subs)
function(add_clib)
    cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME PROJ)
    file(GLOB SRCLIST *.c)
    file(GLOB HEADLIST *.h)
    add_library(${PROJ} ${SRCLIST})
    install(TARGETS ${PROJ})
    install(FILES ${HEADLIST} TYPE INCLUDE)
endfunction(add_clib)


cmake_path(GET CMAKE_SOURCE_DIR FILENAME PROJ)
project(${PROJ} LANGUAGES C)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH})
set(BUILD_SHARED_LIBS ON)

enable_testing()

add_subs()
