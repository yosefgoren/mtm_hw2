# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/yosef/Matam/hw2/mtm_hw2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yosef/Matam/hw2/mtm_hw2/build

# Include any dependencies generated for this target.
include CMakeFiles/part_a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/part_a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/part_a.dir/flags.make

CMakeFiles/part_a.dir/part_a/part_a_test.o: CMakeFiles/part_a.dir/flags.make
CMakeFiles/part_a.dir/part_a/part_a_test.o: ../part_a/part_a_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/part_a.dir/part_a/part_a_test.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/part_a.dir/part_a/part_a_test.o -c /home/yosef/Matam/hw2/mtm_hw2/part_a/part_a_test.cpp

CMakeFiles/part_a.dir/part_a/part_a_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part_a.dir/part_a/part_a_test.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_a/part_a_test.cpp > CMakeFiles/part_a.dir/part_a/part_a_test.i

CMakeFiles/part_a.dir/part_a/part_a_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part_a.dir/part_a/part_a_test.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_a/part_a_test.cpp -o CMakeFiles/part_a.dir/part_a/part_a_test.s

CMakeFiles/part_a.dir/part_a/part_a_test.o.requires:

.PHONY : CMakeFiles/part_a.dir/part_a/part_a_test.o.requires

CMakeFiles/part_a.dir/part_a/part_a_test.o.provides: CMakeFiles/part_a.dir/part_a/part_a_test.o.requires
	$(MAKE) -f CMakeFiles/part_a.dir/build.make CMakeFiles/part_a.dir/part_a/part_a_test.o.provides.build
.PHONY : CMakeFiles/part_a.dir/part_a/part_a_test.o.provides

CMakeFiles/part_a.dir/part_a/part_a_test.o.provides.build: CMakeFiles/part_a.dir/part_a/part_a_test.o


CMakeFiles/part_a.dir/part_a/examDetails.o: CMakeFiles/part_a.dir/flags.make
CMakeFiles/part_a.dir/part_a/examDetails.o: ../part_a/examDetails.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/part_a.dir/part_a/examDetails.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/part_a.dir/part_a/examDetails.o -c /home/yosef/Matam/hw2/mtm_hw2/part_a/examDetails.cpp

CMakeFiles/part_a.dir/part_a/examDetails.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part_a.dir/part_a/examDetails.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_a/examDetails.cpp > CMakeFiles/part_a.dir/part_a/examDetails.i

CMakeFiles/part_a.dir/part_a/examDetails.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part_a.dir/part_a/examDetails.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_a/examDetails.cpp -o CMakeFiles/part_a.dir/part_a/examDetails.s

CMakeFiles/part_a.dir/part_a/examDetails.o.requires:

.PHONY : CMakeFiles/part_a.dir/part_a/examDetails.o.requires

CMakeFiles/part_a.dir/part_a/examDetails.o.provides: CMakeFiles/part_a.dir/part_a/examDetails.o.requires
	$(MAKE) -f CMakeFiles/part_a.dir/build.make CMakeFiles/part_a.dir/part_a/examDetails.o.provides.build
.PHONY : CMakeFiles/part_a.dir/part_a/examDetails.o.provides

CMakeFiles/part_a.dir/part_a/examDetails.o.provides.build: CMakeFiles/part_a.dir/part_a/examDetails.o


# Object files for target part_a
part_a_OBJECTS = \
"CMakeFiles/part_a.dir/part_a/part_a_test.o" \
"CMakeFiles/part_a.dir/part_a/examDetails.o"

# External object files for target part_a
part_a_EXTERNAL_OBJECTS =

part_a: CMakeFiles/part_a.dir/part_a/part_a_test.o
part_a: CMakeFiles/part_a.dir/part_a/examDetails.o
part_a: CMakeFiles/part_a.dir/build.make
part_a: CMakeFiles/part_a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable part_a"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/part_a.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/part_a.dir/build: part_a

.PHONY : CMakeFiles/part_a.dir/build

CMakeFiles/part_a.dir/requires: CMakeFiles/part_a.dir/part_a/part_a_test.o.requires
CMakeFiles/part_a.dir/requires: CMakeFiles/part_a.dir/part_a/examDetails.o.requires

.PHONY : CMakeFiles/part_a.dir/requires

CMakeFiles/part_a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/part_a.dir/cmake_clean.cmake
.PHONY : CMakeFiles/part_a.dir/clean

CMakeFiles/part_a.dir/depend:
	cd /home/yosef/Matam/hw2/mtm_hw2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yosef/Matam/hw2/mtm_hw2 /home/yosef/Matam/hw2/mtm_hw2 /home/yosef/Matam/hw2/mtm_hw2/build /home/yosef/Matam/hw2/mtm_hw2/build /home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles/part_a.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/part_a.dir/depend

