CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

PROJECT (libjk)
#SET (CMAKE_VERBOSE_MAKEFILE true)
# Define Project version
SET (PROJECT_VERSION_MAJOR 0)
SET (PROJECT_VERSION_MINOR 0)
SET (PROJECT_VERSION_PATCH 1)

MESSAGE (STATUS "Start CMAKE for" ${CMAKE_PROJECT_NAME})
# Generate version.h
CONFIGURE_FILE (../include/jk_version.h.in ../include/jk_version.h)

# Define build type - Debug or Release
SET (CMAKE_BUILD_TYPE Debug)
SET (CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}/../)
SET (CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/../../release)
MESSAGE ("Source directory" ${CMAKE_SOURCE_DIR})
MESSAGE ("Binary directory" ${CMAKE_BINARY_DIR})

# List up the source files
SET (SRC_FILES
        ${CMAKE_SOURCE_DIR}/jk_common.c
    )
INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/include)

# Compiler settings
SET (CMAKE_C_COMPILER "gcc")
ADD_COMPILE_OPTIONS(-Wall)
SET (CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
SET (CMAKE_C_FLAGS_RELEASE "-o3")

# Make library
ADD_LIBRARY (jk STATIC ${SRC_FILES})
INSTALL(TARGETS jk DESTINATION ${CMAKE_BINARY_DIR})
INSTALL(FILES ../include/libjk.h DESTINATION ${CMAKE_BINARY_DIR})

#build unit test
ADD_CUSTOM_COMMAND(
    TARGET jk
    POST_BUILD
    COMMENT "Build unit test"
    WORKING_DIRECTORY ../unit_test/
    COMMAND make
)