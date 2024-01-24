cmake_minimum_required(VERSION 3.5)
cmake_path(GET CMAKE_CURRENT_LIST_DIR FILENAME PROJ)
project(${PROJ} LANGUAGES C)


add_library(${PROJ} ${LIB_BUILD_TYPE} ${PROJ}.c)

