# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rizoma/dev/cyberchess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rizoma/dev/cyberchess/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/Board.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/Board.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/Board.dir/flags.make

lib/CMakeFiles/Board.dir/board/Board.cpp.o: lib/CMakeFiles/Board.dir/flags.make
lib/CMakeFiles/Board.dir/board/Board.cpp.o: ../lib/board/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rizoma/dev/cyberchess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/Board.dir/board/Board.cpp.o"
	cd /home/rizoma/dev/cyberchess/build/lib && /bin/x86_64-linux-gnu-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Board.dir/board/Board.cpp.o -c /home/rizoma/dev/cyberchess/lib/board/Board.cpp

lib/CMakeFiles/Board.dir/board/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Board.dir/board/Board.cpp.i"
	cd /home/rizoma/dev/cyberchess/build/lib && /bin/x86_64-linux-gnu-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rizoma/dev/cyberchess/lib/board/Board.cpp > CMakeFiles/Board.dir/board/Board.cpp.i

lib/CMakeFiles/Board.dir/board/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Board.dir/board/Board.cpp.s"
	cd /home/rizoma/dev/cyberchess/build/lib && /bin/x86_64-linux-gnu-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rizoma/dev/cyberchess/lib/board/Board.cpp -o CMakeFiles/Board.dir/board/Board.cpp.s

# Object files for target Board
Board_OBJECTS = \
"CMakeFiles/Board.dir/board/Board.cpp.o"

# External object files for target Board
Board_EXTERNAL_OBJECTS =

lib/libBoard.a: lib/CMakeFiles/Board.dir/board/Board.cpp.o
lib/libBoard.a: lib/CMakeFiles/Board.dir/build.make
lib/libBoard.a: lib/CMakeFiles/Board.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rizoma/dev/cyberchess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libBoard.a"
	cd /home/rizoma/dev/cyberchess/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/Board.dir/cmake_clean_target.cmake
	cd /home/rizoma/dev/cyberchess/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Board.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/Board.dir/build: lib/libBoard.a

.PHONY : lib/CMakeFiles/Board.dir/build

lib/CMakeFiles/Board.dir/clean:
	cd /home/rizoma/dev/cyberchess/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/Board.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/Board.dir/clean

lib/CMakeFiles/Board.dir/depend:
	cd /home/rizoma/dev/cyberchess/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rizoma/dev/cyberchess /home/rizoma/dev/cyberchess/lib /home/rizoma/dev/cyberchess/build /home/rizoma/dev/cyberchess/build/lib /home/rizoma/dev/cyberchess/build/lib/CMakeFiles/Board.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/Board.dir/depend

