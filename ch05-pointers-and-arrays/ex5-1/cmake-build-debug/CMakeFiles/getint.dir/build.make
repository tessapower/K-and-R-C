# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/getint.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/getint.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/getint.dir/flags.make

CMakeFiles/getint.dir/bin/main.c.o: CMakeFiles/getint.dir/flags.make
CMakeFiles/getint.dir/bin/main.c.o: ../bin/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/getint.dir/bin/main.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/getint.dir/bin/main.c.o -c /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/bin/main.c

CMakeFiles/getint.dir/bin/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/getint.dir/bin/main.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/bin/main.c > CMakeFiles/getint.dir/bin/main.c.i

CMakeFiles/getint.dir/bin/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/getint.dir/bin/main.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/bin/main.c -o CMakeFiles/getint.dir/bin/main.c.s

CMakeFiles/getint.dir/src/getint.c.o: CMakeFiles/getint.dir/flags.make
CMakeFiles/getint.dir/src/getint.c.o: ../src/getint.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/getint.dir/src/getint.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/getint.dir/src/getint.c.o -c /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/src/getint.c

CMakeFiles/getint.dir/src/getint.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/getint.dir/src/getint.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/src/getint.c > CMakeFiles/getint.dir/src/getint.c.i

CMakeFiles/getint.dir/src/getint.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/getint.dir/src/getint.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/src/getint.c -o CMakeFiles/getint.dir/src/getint.c.s

# Object files for target getint
getint_OBJECTS = \
"CMakeFiles/getint.dir/bin/main.c.o" \
"CMakeFiles/getint.dir/src/getint.c.o"

# External object files for target getint
getint_EXTERNAL_OBJECTS =

getint: CMakeFiles/getint.dir/bin/main.c.o
getint: CMakeFiles/getint.dir/src/getint.c.o
getint: CMakeFiles/getint.dir/build.make
getint: CMakeFiles/getint.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable getint"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/getint.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/getint.dir/build: getint
.PHONY : CMakeFiles/getint.dir/build

CMakeFiles/getint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/getint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/getint.dir/clean

CMakeFiles/getint.dir/depend:
	cd /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1 /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1 /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug /home/tessa/Developer/K-and-R/ch05-pointers-and-arrays/ex5-1/cmake-build-debug/CMakeFiles/getint.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/getint.dir/depend

