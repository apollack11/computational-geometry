# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/adam/github/computational-geometry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/github/computational-geometry

# Include any dependencies generated for this target.
include CMakeFiles/geofunctions.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/geofunctions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/geofunctions.dir/flags.make

CMakeFiles/geofunctions.dir/geofunctions.cpp.o: CMakeFiles/geofunctions.dir/flags.make
CMakeFiles/geofunctions.dir/geofunctions.cpp.o: geofunctions.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adam/github/computational-geometry/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/geofunctions.dir/geofunctions.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/geofunctions.dir/geofunctions.cpp.o -c /home/adam/github/computational-geometry/geofunctions.cpp

CMakeFiles/geofunctions.dir/geofunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/geofunctions.dir/geofunctions.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adam/github/computational-geometry/geofunctions.cpp > CMakeFiles/geofunctions.dir/geofunctions.cpp.i

CMakeFiles/geofunctions.dir/geofunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/geofunctions.dir/geofunctions.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adam/github/computational-geometry/geofunctions.cpp -o CMakeFiles/geofunctions.dir/geofunctions.cpp.s

CMakeFiles/geofunctions.dir/geofunctions.cpp.o.requires:
.PHONY : CMakeFiles/geofunctions.dir/geofunctions.cpp.o.requires

CMakeFiles/geofunctions.dir/geofunctions.cpp.o.provides: CMakeFiles/geofunctions.dir/geofunctions.cpp.o.requires
	$(MAKE) -f CMakeFiles/geofunctions.dir/build.make CMakeFiles/geofunctions.dir/geofunctions.cpp.o.provides.build
.PHONY : CMakeFiles/geofunctions.dir/geofunctions.cpp.o.provides

CMakeFiles/geofunctions.dir/geofunctions.cpp.o.provides.build: CMakeFiles/geofunctions.dir/geofunctions.cpp.o

# Object files for target geofunctions
geofunctions_OBJECTS = \
"CMakeFiles/geofunctions.dir/geofunctions.cpp.o"

# External object files for target geofunctions
geofunctions_EXTERNAL_OBJECTS =

libgeofunctions.a: CMakeFiles/geofunctions.dir/geofunctions.cpp.o
libgeofunctions.a: CMakeFiles/geofunctions.dir/build.make
libgeofunctions.a: CMakeFiles/geofunctions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgeofunctions.a"
	$(CMAKE_COMMAND) -P CMakeFiles/geofunctions.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/geofunctions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/geofunctions.dir/build: libgeofunctions.a
.PHONY : CMakeFiles/geofunctions.dir/build

CMakeFiles/geofunctions.dir/requires: CMakeFiles/geofunctions.dir/geofunctions.cpp.o.requires
.PHONY : CMakeFiles/geofunctions.dir/requires

CMakeFiles/geofunctions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/geofunctions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/geofunctions.dir/clean

CMakeFiles/geofunctions.dir/depend:
	cd /home/adam/github/computational-geometry && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/github/computational-geometry /home/adam/github/computational-geometry /home/adam/github/computational-geometry /home/adam/github/computational-geometry /home/adam/github/computational-geometry/CMakeFiles/geofunctions.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/geofunctions.dir/depend

