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
include lib/CMakeFiles/Promotion.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/Promotion.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/Promotion.dir/flags.make

lib/CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.o: lib/CMakeFiles/Promotion.dir/flags.make
lib/CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.o: ../lib/move/promotion/Promotion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rizoma/dev/cyberchess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.o"
	cd /home/rizoma/dev/cyberchess/build/lib && /bin/x86_64-linux-gnu-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.o -c /home/rizoma/dev/cyberchess/lib/move/promotion/Promotion.cpp

lib/CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.i"
	cd /home/rizoma/dev/cyberchess/build/lib && /bin/x86_64-linux-gnu-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rizoma/dev/cyberchess/lib/move/promotion/Promotion.cpp > CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.i

lib/CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.s"
	cd /home/rizoma/dev/cyberchess/build/lib && /bin/x86_64-linux-gnu-g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rizoma/dev/cyberchess/lib/move/promotion/Promotion.cpp -o CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.s

# Object files for target Promotion
Promotion_OBJECTS = \
"CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.o"

# External object files for target Promotion
Promotion_EXTERNAL_OBJECTS =

lib/libPromotion.a: lib/CMakeFiles/Promotion.dir/move/promotion/Promotion.cpp.o
lib/libPromotion.a: lib/CMakeFiles/Promotion.dir/build.make
lib/libPromotion.a: lib/CMakeFiles/Promotion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rizoma/dev/cyberchess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libPromotion.a"
	cd /home/rizoma/dev/cyberchess/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/Promotion.dir/cmake_clean_target.cmake
	cd /home/rizoma/dev/cyberchess/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Promotion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/Promotion.dir/build: lib/libPromotion.a

.PHONY : lib/CMakeFiles/Promotion.dir/build

lib/CMakeFiles/Promotion.dir/clean:
	cd /home/rizoma/dev/cyberchess/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/Promotion.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/Promotion.dir/clean

lib/CMakeFiles/Promotion.dir/depend:
	cd /home/rizoma/dev/cyberchess/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rizoma/dev/cyberchess /home/rizoma/dev/cyberchess/lib /home/rizoma/dev/cyberchess/build /home/rizoma/dev/cyberchess/build/lib /home/rizoma/dev/cyberchess/build/lib/CMakeFiles/Promotion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/Promotion.dir/depend

