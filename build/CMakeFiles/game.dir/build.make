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
include CMakeFiles/game.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/part_b/game_test.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/game_test.o: ../part_b/game_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/part_b/game_test.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/game_test.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/game_test.cpp

CMakeFiles/game.dir/part_b/game_test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/game_test.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/game_test.cpp > CMakeFiles/game.dir/part_b/game_test.i

CMakeFiles/game.dir/part_b/game_test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/game_test.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/game_test.cpp -o CMakeFiles/game.dir/part_b/game_test.s

CMakeFiles/game.dir/part_b/game_test.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/game_test.o.requires

CMakeFiles/game.dir/part_b/game_test.o.provides: CMakeFiles/game.dir/part_b/game_test.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/game_test.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/game_test.o.provides

CMakeFiles/game.dir/part_b/game_test.o.provides.build: CMakeFiles/game.dir/part_b/game_test.o


CMakeFiles/game.dir/part_b/Auxiliaries.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/Auxiliaries.o: ../part_b/Auxiliaries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/part_b/Auxiliaries.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/Auxiliaries.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/Auxiliaries.cpp

CMakeFiles/game.dir/part_b/Auxiliaries.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/Auxiliaries.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/Auxiliaries.cpp > CMakeFiles/game.dir/part_b/Auxiliaries.i

CMakeFiles/game.dir/part_b/Auxiliaries.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/Auxiliaries.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/Auxiliaries.cpp -o CMakeFiles/game.dir/part_b/Auxiliaries.s

CMakeFiles/game.dir/part_b/Auxiliaries.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/Auxiliaries.o.requires

CMakeFiles/game.dir/part_b/Auxiliaries.o.provides: CMakeFiles/game.dir/part_b/Auxiliaries.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/Auxiliaries.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/Auxiliaries.o.provides

CMakeFiles/game.dir/part_b/Auxiliaries.o.provides.build: CMakeFiles/game.dir/part_b/Auxiliaries.o


CMakeFiles/game.dir/part_b/Game.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/Game.o: ../part_b/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/part_b/Game.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/Game.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/Game.cpp

CMakeFiles/game.dir/part_b/Game.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/Game.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/Game.cpp > CMakeFiles/game.dir/part_b/Game.i

CMakeFiles/game.dir/part_b/Game.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/Game.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/Game.cpp -o CMakeFiles/game.dir/part_b/Game.s

CMakeFiles/game.dir/part_b/Game.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/Game.o.requires

CMakeFiles/game.dir/part_b/Game.o.provides: CMakeFiles/game.dir/part_b/Game.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/Game.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/Game.o.provides

CMakeFiles/game.dir/part_b/Game.o.provides.build: CMakeFiles/game.dir/part_b/Game.o


CMakeFiles/game.dir/part_b/TileItem.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/TileItem.o: ../part_b/TileItem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/part_b/TileItem.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/TileItem.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/TileItem.cpp

CMakeFiles/game.dir/part_b/TileItem.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/TileItem.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/TileItem.cpp > CMakeFiles/game.dir/part_b/TileItem.i

CMakeFiles/game.dir/part_b/TileItem.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/TileItem.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/TileItem.cpp -o CMakeFiles/game.dir/part_b/TileItem.s

CMakeFiles/game.dir/part_b/TileItem.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/TileItem.o.requires

CMakeFiles/game.dir/part_b/TileItem.o.provides: CMakeFiles/game.dir/part_b/TileItem.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/TileItem.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/TileItem.o.provides

CMakeFiles/game.dir/part_b/TileItem.o.provides.build: CMakeFiles/game.dir/part_b/TileItem.o


CMakeFiles/game.dir/part_b/Character.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/Character.o: ../part_b/Character.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/part_b/Character.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/Character.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/Character.cpp

CMakeFiles/game.dir/part_b/Character.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/Character.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/Character.cpp > CMakeFiles/game.dir/part_b/Character.i

CMakeFiles/game.dir/part_b/Character.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/Character.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/Character.cpp -o CMakeFiles/game.dir/part_b/Character.s

CMakeFiles/game.dir/part_b/Character.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/Character.o.requires

CMakeFiles/game.dir/part_b/Character.o.provides: CMakeFiles/game.dir/part_b/Character.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/Character.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/Character.o.provides

CMakeFiles/game.dir/part_b/Character.o.provides.build: CMakeFiles/game.dir/part_b/Character.o


CMakeFiles/game.dir/part_b/Soldier.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/Soldier.o: ../part_b/Soldier.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/part_b/Soldier.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/Soldier.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/Soldier.cpp

CMakeFiles/game.dir/part_b/Soldier.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/Soldier.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/Soldier.cpp > CMakeFiles/game.dir/part_b/Soldier.i

CMakeFiles/game.dir/part_b/Soldier.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/Soldier.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/Soldier.cpp -o CMakeFiles/game.dir/part_b/Soldier.s

CMakeFiles/game.dir/part_b/Soldier.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/Soldier.o.requires

CMakeFiles/game.dir/part_b/Soldier.o.provides: CMakeFiles/game.dir/part_b/Soldier.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/Soldier.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/Soldier.o.provides

CMakeFiles/game.dir/part_b/Soldier.o.provides.build: CMakeFiles/game.dir/part_b/Soldier.o


CMakeFiles/game.dir/part_b/Medic.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/Medic.o: ../part_b/Medic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/game.dir/part_b/Medic.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/Medic.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/Medic.cpp

CMakeFiles/game.dir/part_b/Medic.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/Medic.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/Medic.cpp > CMakeFiles/game.dir/part_b/Medic.i

CMakeFiles/game.dir/part_b/Medic.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/Medic.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/Medic.cpp -o CMakeFiles/game.dir/part_b/Medic.s

CMakeFiles/game.dir/part_b/Medic.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/Medic.o.requires

CMakeFiles/game.dir/part_b/Medic.o.provides: CMakeFiles/game.dir/part_b/Medic.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/Medic.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/Medic.o.provides

CMakeFiles/game.dir/part_b/Medic.o.provides.build: CMakeFiles/game.dir/part_b/Medic.o


CMakeFiles/game.dir/part_b/Sniper.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/part_b/Sniper.o: ../part_b/Sniper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/game.dir/part_b/Sniper.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/game.dir/part_b/Sniper.o -c /home/yosef/Matam/hw2/mtm_hw2/part_b/Sniper.cpp

CMakeFiles/game.dir/part_b/Sniper.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/game.dir/part_b/Sniper.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yosef/Matam/hw2/mtm_hw2/part_b/Sniper.cpp > CMakeFiles/game.dir/part_b/Sniper.i

CMakeFiles/game.dir/part_b/Sniper.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/game.dir/part_b/Sniper.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yosef/Matam/hw2/mtm_hw2/part_b/Sniper.cpp -o CMakeFiles/game.dir/part_b/Sniper.s

CMakeFiles/game.dir/part_b/Sniper.o.requires:

.PHONY : CMakeFiles/game.dir/part_b/Sniper.o.requires

CMakeFiles/game.dir/part_b/Sniper.o.provides: CMakeFiles/game.dir/part_b/Sniper.o.requires
	$(MAKE) -f CMakeFiles/game.dir/build.make CMakeFiles/game.dir/part_b/Sniper.o.provides.build
.PHONY : CMakeFiles/game.dir/part_b/Sniper.o.provides

CMakeFiles/game.dir/part_b/Sniper.o.provides.build: CMakeFiles/game.dir/part_b/Sniper.o


# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/part_b/game_test.o" \
"CMakeFiles/game.dir/part_b/Auxiliaries.o" \
"CMakeFiles/game.dir/part_b/Game.o" \
"CMakeFiles/game.dir/part_b/TileItem.o" \
"CMakeFiles/game.dir/part_b/Character.o" \
"CMakeFiles/game.dir/part_b/Soldier.o" \
"CMakeFiles/game.dir/part_b/Medic.o" \
"CMakeFiles/game.dir/part_b/Sniper.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/part_b/game_test.o
game: CMakeFiles/game.dir/part_b/Auxiliaries.o
game: CMakeFiles/game.dir/part_b/Game.o
game: CMakeFiles/game.dir/part_b/TileItem.o
game: CMakeFiles/game.dir/part_b/Character.o
game: CMakeFiles/game.dir/part_b/Soldier.o
game: CMakeFiles/game.dir/part_b/Medic.o
game: CMakeFiles/game.dir/part_b/Sniper.o
game: CMakeFiles/game.dir/build.make
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game

.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/game_test.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/Auxiliaries.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/Game.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/TileItem.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/Character.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/Soldier.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/Medic.o.requires
CMakeFiles/game.dir/requires: CMakeFiles/game.dir/part_b/Sniper.o.requires

.PHONY : CMakeFiles/game.dir/requires

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /home/yosef/Matam/hw2/mtm_hw2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yosef/Matam/hw2/mtm_hw2 /home/yosef/Matam/hw2/mtm_hw2 /home/yosef/Matam/hw2/mtm_hw2/build /home/yosef/Matam/hw2/mtm_hw2/build /home/yosef/Matam/hw2/mtm_hw2/build/CMakeFiles/game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/game.dir/depend

