# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/sawert/qtprojects/Gauss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sawert/qtprojects/build-Gauss-unknown-Debug

# Utility rule file for Gauss_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/Gauss_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Gauss_autogen.dir/progress.make

CMakeFiles/Gauss_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/sawert/qtprojects/build-Gauss-unknown-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Gauss"
	/usr/bin/cmake -E cmake_autogen /home/sawert/qtprojects/build-Gauss-unknown-Debug/CMakeFiles/Gauss_autogen.dir/AutogenInfo.json Debug

Gauss_autogen: CMakeFiles/Gauss_autogen
Gauss_autogen: CMakeFiles/Gauss_autogen.dir/build.make
.PHONY : Gauss_autogen

# Rule to build all files generated by this target.
CMakeFiles/Gauss_autogen.dir/build: Gauss_autogen
.PHONY : CMakeFiles/Gauss_autogen.dir/build

CMakeFiles/Gauss_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Gauss_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Gauss_autogen.dir/clean

CMakeFiles/Gauss_autogen.dir/depend:
	cd /home/sawert/qtprojects/build-Gauss-unknown-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sawert/qtprojects/Gauss /home/sawert/qtprojects/Gauss /home/sawert/qtprojects/build-Gauss-unknown-Debug /home/sawert/qtprojects/build-Gauss-unknown-Debug /home/sawert/qtprojects/build-Gauss-unknown-Debug/CMakeFiles/Gauss_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Gauss_autogen.dir/depend

