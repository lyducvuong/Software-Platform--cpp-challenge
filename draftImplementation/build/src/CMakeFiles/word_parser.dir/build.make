# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build

# Include any dependencies generated for this target.
include src/CMakeFiles/word_parser.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/word_parser.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/word_parser.dir/flags.make

src/CMakeFiles/word_parser.dir/word_parser.cpp.o: src/CMakeFiles/word_parser.dir/flags.make
src/CMakeFiles/word_parser.dir/word_parser.cpp.o: ../src/word_parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/word_parser.dir/word_parser.cpp.o"
	cd /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/word_parser.dir/word_parser.cpp.o -c /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/src/word_parser.cpp

src/CMakeFiles/word_parser.dir/word_parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/word_parser.dir/word_parser.cpp.i"
	cd /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/src/word_parser.cpp > CMakeFiles/word_parser.dir/word_parser.cpp.i

src/CMakeFiles/word_parser.dir/word_parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/word_parser.dir/word_parser.cpp.s"
	cd /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/src/word_parser.cpp -o CMakeFiles/word_parser.dir/word_parser.cpp.s

# Object files for target word_parser
word_parser_OBJECTS = \
"CMakeFiles/word_parser.dir/word_parser.cpp.o"

# External object files for target word_parser
word_parser_EXTERNAL_OBJECTS =

src/libword_parser.a: src/CMakeFiles/word_parser.dir/word_parser.cpp.o
src/libword_parser.a: src/CMakeFiles/word_parser.dir/build.make
src/libword_parser.a: src/CMakeFiles/word_parser.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libword_parser.a"
	cd /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src && $(CMAKE_COMMAND) -P CMakeFiles/word_parser.dir/cmake_clean_target.cmake
	cd /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/word_parser.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/word_parser.dir/build: src/libword_parser.a

.PHONY : src/CMakeFiles/word_parser.dir/build

src/CMakeFiles/word_parser.dir/clean:
	cd /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src && $(CMAKE_COMMAND) -P CMakeFiles/word_parser.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/word_parser.dir/clean

src/CMakeFiles/word_parser.dir/depend:
	cd /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/src /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src /home/vuongld/work/Software-Platform--cpp-challenge/draftImplementation/build/src/CMakeFiles/word_parser.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/word_parser.dir/depend

