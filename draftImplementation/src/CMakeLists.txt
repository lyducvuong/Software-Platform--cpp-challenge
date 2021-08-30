cmake_minimum_required(VERSION 3.2)
project(word_parser CXX)

set(SOURCE_FILES
	word.h
	word_parser.h
	word_parser.cpp
)

add_library(word_parser word_parser.cpp)
install(TARGETS word_parser DESTINATION ${WORDS_TRACKING_INSTALL_LIB_DIR})
install(FILES word_parser.h DESTINATION ${WORDS_TRACKING_INSTALL_INCLUDE_DIR})
install(FILES word.h DESTINATION ${WORDS_TRACKING_INSTALL_INCLUDE_DIR})
find_package (Threads)
target_link_libraries(word_parser ${CMAKE_THREAD_LIBS_INIT})
add_executable (word_monitor word_parser.cpp)
