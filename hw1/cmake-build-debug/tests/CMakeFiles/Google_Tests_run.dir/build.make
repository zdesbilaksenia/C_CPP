# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/cmake/580/bin/cmake

# The command to remove a file.
RM = /snap/cmake/580/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ksenia/C_C++/hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ksenia/C_C++/hw1/cmake-build-debug

# Include any dependencies generated for this target.
include tests/CMakeFiles/Google_Tests_run.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/Google_Tests_run.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/Google_Tests_run.dir/flags.make

tests/CMakeFiles/Google_Tests_run.dir/tests.cpp.o: tests/CMakeFiles/Google_Tests_run.dir/flags.make
tests/CMakeFiles/Google_Tests_run.dir/tests.cpp.o: ../tests/tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ksenia/C_C++/hw1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/Google_Tests_run.dir/tests.cpp.o"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Google_Tests_run.dir/tests.cpp.o -c /home/ksenia/C_C++/hw1/tests/tests.cpp

tests/CMakeFiles/Google_Tests_run.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Google_Tests_run.dir/tests.cpp.i"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ksenia/C_C++/hw1/tests/tests.cpp > CMakeFiles/Google_Tests_run.dir/tests.cpp.i

tests/CMakeFiles/Google_Tests_run.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Google_Tests_run.dir/tests.cpp.s"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ksenia/C_C++/hw1/tests/tests.cpp -o CMakeFiles/Google_Tests_run.dir/tests.cpp.s

# Object files for target Google_Tests_run
Google_Tests_run_OBJECTS = \
"CMakeFiles/Google_Tests_run.dir/tests.cpp.o"

# External object files for target Google_Tests_run
Google_Tests_run_EXTERNAL_OBJECTS =

tests/Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/tests.cpp.o
tests/Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/build.make
tests/Google_Tests_run: lib/libgtestd.a
tests/Google_Tests_run: lib/libgtest_maind.a
tests/Google_Tests_run: lib/libgtestd.a
tests/Google_Tests_run: tests/CMakeFiles/Google_Tests_run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ksenia/C_C++/hw1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Google_Tests_run"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Google_Tests_run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/Google_Tests_run.dir/build: tests/Google_Tests_run

.PHONY : tests/CMakeFiles/Google_Tests_run.dir/build

tests/CMakeFiles/Google_Tests_run.dir/clean:
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests && $(CMAKE_COMMAND) -P CMakeFiles/Google_Tests_run.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/Google_Tests_run.dir/clean

tests/CMakeFiles/Google_Tests_run.dir/depend:
	cd /home/ksenia/C_C++/hw1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ksenia/C_C++/hw1 /home/ksenia/C_C++/hw1/tests /home/ksenia/C_C++/hw1/cmake-build-debug /home/ksenia/C_C++/hw1/cmake-build-debug/tests /home/ksenia/C_C++/hw1/cmake-build-debug/tests/CMakeFiles/Google_Tests_run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/Google_Tests_run.dir/depend

