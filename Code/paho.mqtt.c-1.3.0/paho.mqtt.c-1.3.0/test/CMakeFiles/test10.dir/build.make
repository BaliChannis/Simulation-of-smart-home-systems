# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/hq/paho.mqtt.c-1.3.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hq/paho.mqtt.c-1.3.0

# Include any dependencies generated for this target.
include test/CMakeFiles/test10.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test10.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test10.dir/flags.make

test/CMakeFiles/test10.dir/test10.c.o: test/CMakeFiles/test10.dir/flags.make
test/CMakeFiles/test10.dir/test10.c.o: test/test10.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hq/paho.mqtt.c-1.3.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/test10.dir/test10.c.o"
	cd /home/hq/paho.mqtt.c-1.3.0/test && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test10.dir/test10.c.o   -c /home/hq/paho.mqtt.c-1.3.0/test/test10.c

test/CMakeFiles/test10.dir/test10.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test10.dir/test10.c.i"
	cd /home/hq/paho.mqtt.c-1.3.0/test && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hq/paho.mqtt.c-1.3.0/test/test10.c > CMakeFiles/test10.dir/test10.c.i

test/CMakeFiles/test10.dir/test10.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test10.dir/test10.c.s"
	cd /home/hq/paho.mqtt.c-1.3.0/test && /usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hq/paho.mqtt.c-1.3.0/test/test10.c -o CMakeFiles/test10.dir/test10.c.s

test/CMakeFiles/test10.dir/test10.c.o.requires:

.PHONY : test/CMakeFiles/test10.dir/test10.c.o.requires

test/CMakeFiles/test10.dir/test10.c.o.provides: test/CMakeFiles/test10.dir/test10.c.o.requires
	$(MAKE) -f test/CMakeFiles/test10.dir/build.make test/CMakeFiles/test10.dir/test10.c.o.provides.build
.PHONY : test/CMakeFiles/test10.dir/test10.c.o.provides

test/CMakeFiles/test10.dir/test10.c.o.provides.build: test/CMakeFiles/test10.dir/test10.c.o


# Object files for target test10
test10_OBJECTS = \
"CMakeFiles/test10.dir/test10.c.o"

# External object files for target test10
test10_EXTERNAL_OBJECTS =

test/test10: test/CMakeFiles/test10.dir/test10.c.o
test/test10: test/CMakeFiles/test10.dir/build.make
test/test10: src/libpaho-mqtt3c.so.1.3.0
test/test10: test/CMakeFiles/test10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hq/paho.mqtt.c-1.3.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test10"
	cd /home/hq/paho.mqtt.c-1.3.0/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test10.dir/build: test/test10

.PHONY : test/CMakeFiles/test10.dir/build

test/CMakeFiles/test10.dir/requires: test/CMakeFiles/test10.dir/test10.c.o.requires

.PHONY : test/CMakeFiles/test10.dir/requires

test/CMakeFiles/test10.dir/clean:
	cd /home/hq/paho.mqtt.c-1.3.0/test && $(CMAKE_COMMAND) -P CMakeFiles/test10.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/test10.dir/clean

test/CMakeFiles/test10.dir/depend:
	cd /home/hq/paho.mqtt.c-1.3.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hq/paho.mqtt.c-1.3.0 /home/hq/paho.mqtt.c-1.3.0/test /home/hq/paho.mqtt.c-1.3.0 /home/hq/paho.mqtt.c-1.3.0/test /home/hq/paho.mqtt.c-1.3.0/test/CMakeFiles/test10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test10.dir/depend

