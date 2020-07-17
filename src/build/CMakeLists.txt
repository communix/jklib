CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

PROJECT (libjk)
#SET (CMAKE_VERBOSE_MAKEFILE true)
# Define Project version
SET (PROJECT_VERSION_MAJOR 0)
SET (PROJECT_VERSION_MINOR 0)
SET (PROJECT_VERSION_PATCH 1)

MESSAGE (STATUS "Start CMAKE for" ${CMAKE_PROJECT_NAME})

# Define build type - Debug or Release
SET (CMAKE_BUILD_TYPE Debug)

# List up the source files
SET (SRC_FILES
        ../jk_common.c
    )
INCLUDE_DIRECTORIES (../include)

# Compiler settings
SET (CMAKE_C_COMPILER "gcc")
ADD_COMPILE_OPTIONS(-Wall)
SET (CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
SET (CMAKE_C_FLAGS_RELEASE "-o3")

# Make library
ADD_LIBRARY (jk STATIC ${SRC_FILES})
ADD_CUSTOM_COMMAND(
    TARGET jk
    POST_BUILD
    COMMENT "Copy hederfiles to release"
    WORKING_DIRECTORY ./
    COMMAND cp ./libjk.a ../../release/
    COMMAND cp ../include/libjk.h ../../release/
)