# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anshu/CLionProjects/os-hw2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anshu/CLionProjects/os-hw2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/os_hw2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/os_hw2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/os_hw2.dir/flags.make

CMakeFiles/os_hw2.dir/main.c.o: CMakeFiles/os_hw2.dir/flags.make
CMakeFiles/os_hw2.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anshu/CLionProjects/os-hw2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/os_hw2.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/os_hw2.dir/main.c.o   -c /Users/anshu/CLionProjects/os-hw2/main.c

CMakeFiles/os_hw2.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/os_hw2.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/anshu/CLionProjects/os-hw2/main.c > CMakeFiles/os_hw2.dir/main.c.i

CMakeFiles/os_hw2.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/os_hw2.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/anshu/CLionProjects/os-hw2/main.c -o CMakeFiles/os_hw2.dir/main.c.s

# Object files for target os_hw2
os_hw2_OBJECTS = \
"CMakeFiles/os_hw2.dir/main.c.o"

# External object files for target os_hw2
os_hw2_EXTERNAL_OBJECTS =

os_hw2: CMakeFiles/os_hw2.dir/main.c.o
os_hw2: CMakeFiles/os_hw2.dir/build.make
os_hw2: CMakeFiles/os_hw2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anshu/CLionProjects/os-hw2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable os_hw2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/os_hw2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/os_hw2.dir/build: os_hw2

.PHONY : CMakeFiles/os_hw2.dir/build

CMakeFiles/os_hw2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/os_hw2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/os_hw2.dir/clean

CMakeFiles/os_hw2.dir/depend:
	cd /Users/anshu/CLionProjects/os-hw2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anshu/CLionProjects/os-hw2 /Users/anshu/CLionProjects/os-hw2 /Users/anshu/CLionProjects/os-hw2/cmake-build-debug /Users/anshu/CLionProjects/os-hw2/cmake-build-debug /Users/anshu/CLionProjects/os-hw2/cmake-build-debug/CMakeFiles/os_hw2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/os_hw2.dir/depend
