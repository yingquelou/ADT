cmake_minimum_required(VERSION 3.5)

cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME PROJ)
project(${PROJ} LANGUAGES C)

file(GLOB SRCLIST RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.c)
# 测试约定:命名约定——<库名>Test[..].c
foreach(curFile ${SRCLIST})
string(REGEX REPLACE "(.*)Test.*" \\1 item ${curFile})
cmake_path(GET curFile STEM curTarget)
include_directories(../${item})
add_executable(${curTarget} ${curFile})
target_link_libraries(${curTarget} ${item})
add_test(NAME ${curTarget} COMMAND ${curTarget})
endforeach(curFile)
