cmake_minimum_required(VERSION 3.2)

project(TRIADD_Assignment VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread")

set(WORDS_TRACKING_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(WORDS_TRACKING_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(WORDS_TRACKING_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)
set(WORDS_TRACKING_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src)

include_directories(${WORDS_TRACKING_INSTALL_INCLUDE_DIR})
include_directories(${WORDS_TRACKING_HEADERS_DIR})

add_subdirectory(src)

