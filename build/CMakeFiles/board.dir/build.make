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
include CMakeFiles/board.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/board.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/board.dir/flags.make

CMakeFiles/board.dir/part_b/board_test.obj: CMakeFiles/board.dir/flags.make
CMakeFiles/board.dir/part_b/board_test.obj: ../part_b/board_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/board.dir/part_b/board_test.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\board.dir\part_b\board_test.obj -c C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_b\board_test.cpp

CMakeFiles/board.dir/part_b/board_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board.dir/part_b/board_test.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_b\board_test.cpp > CMakeFiles\board.dir\part_b\board_test.i

CMakeFiles/board.dir/part_b/board_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board.dir/part_b/board_test.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_b\board_test.cpp -o CMakeFiles\board.dir\part_b\board_test.s

CMakeFiles/board.dir/part_b/Auxiliaries.obj: CMakeFiles/board.dir/flags.make
CMakeFiles/board.dir/part_b/Auxiliaries.obj: ../part_b/Auxiliaries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/board.dir/part_b/Auxiliaries.obj"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\board.dir\part_b\Auxiliaries.obj -c C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_b\Auxiliaries.cpp

CMakeFiles/board.dir/part_b/Auxiliaries.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board.dir/part_b/Auxiliaries.i"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_b\Auxiliaries.cpp > CMakeFiles\board.dir\part_b\Auxiliaries.i

CMakeFiles/board.dir/part_b/Auxiliaries.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board.dir/part_b/Auxiliaries.s"
	C:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\part_b\Auxiliaries.cpp -o CMakeFiles\board.dir\part_b\Auxiliaries.s

# Object files for target board
board_OBJECTS = \
"CMakeFiles/board.dir/part_b/board_test.obj" \
"CMakeFiles/board.dir/part_b/Auxiliaries.obj"

# External object files for target board
board_EXTERNAL_OBJECTS =

board.exe: CMakeFiles/board.dir/part_b/board_test.obj
board.exe: CMakeFiles/board.dir/part_b/Auxiliaries.obj
board.exe: CMakeFiles/board.dir/build.make
board.exe: CMakeFiles/board.dir/linklibs.rsp
board.exe: CMakeFiles/board.dir/objects1.rsp
board.exe: CMakeFiles/board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable board.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\board.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/board.dir/build: board.exe

.PHONY : CMakeFiles/board.dir/build

CMakeFiles/board.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\board.dir\cmake_clean.cmake
.PHONY : CMakeFiles/board.dir/clean

CMakeFiles/board.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2 C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2 C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build C:\Users\pc\Desktop\S4.5\Matam_Take2\hw2\mtm_hw2\build\CMakeFiles\board.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/board.dir/depend

