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
include tests/lib/googletest/CMakeFiles/gtest.dir/depend.make

# Include the progress variables for this target.
include tests/lib/googletest/CMakeFiles/gtest.dir/progress.make

# Include the compile flags for this target's objects.
include tests/lib/googletest/CMakeFiles/gtest.dir/flags.make

tests/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: tests/lib/googletest/CMakeFiles/gtest.dir/flags.make
tests/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o: ../tests/lib/googletest/src/gtest-all.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ksenia/C_C++/hw1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gtest.dir/src/gtest-all.cc.o -c /home/ksenia/C_C++/hw1/tests/lib/googletest/src/gtest-all.cc

tests/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest.dir/src/gtest-all.cc.i"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ksenia/C_C++/hw1/tests/lib/googletest/src/gtest-all.cc > CMakeFiles/gtest.dir/src/gtest-all.cc.i

tests/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest.dir/src/gtest-all.cc.s"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ksenia/C_C++/hw1/tests/lib/googletest/src/gtest-all.cc -o CMakeFiles/gtest.dir/src/gtest-all.cc.s

# Object files for target gtest
gtest_OBJECTS = \
"CMakeFiles/gtest.dir/src/gtest-all.cc.o"

# External object files for target gtest
gtest_EXTERNAL_OBJECTS =

lib/libgtest.a: tests/lib/googletest/CMakeFiles/gtest.dir/src/gtest-all.cc.o
lib/libgtest.a: tests/lib/googletest/CMakeFiles/gtest.dir/build.make
lib/libgtest.a: tests/lib/googletest/CMakeFiles/gtest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ksenia/C_C++/hw1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgtest.a"
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean_target.cmake
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/lib/googletest/CMakeFiles/gtest.dir/build: lib/libgtest.a

.PHONY : tests/lib/googletest/CMakeFiles/gtest.dir/build

tests/lib/googletest/CMakeFiles/gtest.dir/clean:
	cd /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest.dir/cmake_clean.cmake
.PHONY : tests/lib/googletest/CMakeFiles/gtest.dir/clean

tests/lib/googletest/CMakeFiles/gtest.dir/depend:
	cd /home/ksenia/C_C++/hw1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ksenia/C_C++/hw1 /home/ksenia/C_C++/hw1/tests/lib/googletest /home/ksenia/C_C++/hw1/cmake-build-debug /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest /home/ksenia/C_C++/hw1/cmake-build-debug/tests/lib/googletest/CMakeFiles/gtest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/lib/googletest/CMakeFiles/gtest.dir/depend

