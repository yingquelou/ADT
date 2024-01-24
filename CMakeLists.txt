cmake_minimum_required(VERSION 3.5)
cmake_path(GET CMAKE_SOURCE_DIR FILENAME PROJ)
project(${PROJ} LANGUAGES C)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${EXECUTABLE_OUTPUT_PATH}) 

if(${CMAKE_BUILD_TYPE} MATCHES Debug|RelWithDebInfo)
    message(${CMAKE_BUILD_TYPE})
    set(LIB_BUILD_TYPE STATIC)
else()
    set(LIB_BUILD_TYPE SHARED)
endif()

include_directories(list)
add_executable(${PROJ} test.c)
target_link_libraries(${PROJ} list)
add_subdirectory(list)
add_subdirectory(tree)