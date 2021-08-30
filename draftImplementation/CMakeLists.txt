cmake_minimum_required(VERSION 3.2)

project(synspective-assignment3 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(LINKED_LIST_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(LINKED_LIST_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(LINKED_LIST_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(LINKED_LIST_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${LINKED_LIST_INSTALL_INCLUDE_DIR})
include_directories(${LINKED_LIST_HEADERS_DIR})

add_subdirectory(src)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Build Unit Test for Linux environment")
    add_subdirectory(test)
endif()
