# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build

# Include any dependencies generated for this target.
include CMakeFiles/part_a.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/part_a.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/part_a.dir/flags.make

CMakeFiles/part_a.dir/part_a/part_a_test.obj: CMakeFiles/part_a.dir/flags.make
CMakeFiles/part_a.dir/part_a/part_a_test.obj: ../part_a/part_a_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/part_a.dir/part_a/part_a_test.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\part_a.dir\part_a\part_a_test.obj -c C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_a\part_a_test.cpp

CMakeFiles/part_a.dir/part_a/part_a_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part_a.dir/part_a/part_a_test.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_a\part_a_test.cpp > CMakeFiles\part_a.dir\part_a\part_a_test.i

CMakeFiles/part_a.dir/part_a/part_a_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part_a.dir/part_a/part_a_test.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_a\part_a_test.cpp -o CMakeFiles\part_a.dir\part_a\part_a_test.s

CMakeFiles/part_a.dir/part_a/examDetails.obj: CMakeFiles/part_a.dir/flags.make
CMakeFiles/part_a.dir/part_a/examDetails.obj: ../part_a/examDetails.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/part_a.dir/part_a/examDetails.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\part_a.dir\part_a\examDetails.obj -c C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_a\examDetails.cpp

CMakeFiles/part_a.dir/part_a/examDetails.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/part_a.dir/part_a/examDetails.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_a\examDetails.cpp > CMakeFiles\part_a.dir\part_a\examDetails.i

CMakeFiles/part_a.dir/part_a/examDetails.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/part_a.dir/part_a/examDetails.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_a\examDetails.cpp -o CMakeFiles\part_a.dir\part_a\examDetails.s

# Object files for target part_a
part_a_OBJECTS = \
"CMakeFiles/part_a.dir/part_a/part_a_test.obj" \
"CMakeFiles/part_a.dir/part_a/examDetails.obj"

# External object files for target part_a
part_a_EXTERNAL_OBJECTS =

part_a.exe: CMakeFiles/part_a.dir/part_a/part_a_test.obj
part_a.exe: CMakeFiles/part_a.dir/part_a/examDetails.obj
part_a.exe: CMakeFiles/part_a.dir/build.make
part_a.exe: CMakeFiles/part_a.dir/linklibs.rsp
part_a.exe: CMakeFiles/part_a.dir/objects1.rsp
part_a.exe: CMakeFiles/part_a.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable part_a.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\part_a.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/part_a.dir/build: part_a.exe

.PHONY : CMakeFiles/part_a.dir/build

CMakeFiles/part_a.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\part_a.dir\cmake_clean.cmake
.PHONY : CMakeFiles/part_a.dir/clean

CMakeFiles/part_a.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2 C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2 C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles\part_a.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/part_a.dir/depend

