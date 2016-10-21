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
include CMakeFiles/PolygonUnion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PolygonUnion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PolygonUnion.dir/flags.make

CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o: CMakeFiles/PolygonUnion.dir/flags.make
CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o: geofunctions.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adam/github/computational-geometry/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o -c /home/adam/github/computational-geometry/geofunctions.cpp

CMakeFiles/PolygonUnion.dir/geofunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PolygonUnion.dir/geofunctions.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adam/github/computational-geometry/geofunctions.cpp > CMakeFiles/PolygonUnion.dir/geofunctions.cpp.i

CMakeFiles/PolygonUnion.dir/geofunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PolygonUnion.dir/geofunctions.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adam/github/computational-geometry/geofunctions.cpp -o CMakeFiles/PolygonUnion.dir/geofunctions.cpp.s

CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.requires:
.PHONY : CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.requires

CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.provides: CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.requires
	$(MAKE) -f CMakeFiles/PolygonUnion.dir/build.make CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.provides.build
.PHONY : CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.provides

CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.provides.build: CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o

CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o: CMakeFiles/PolygonUnion.dir/flags.make
CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o: polygon_union.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/adam/github/computational-geometry/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o -c /home/adam/github/computational-geometry/polygon_union.cpp

CMakeFiles/PolygonUnion.dir/polygon_union.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PolygonUnion.dir/polygon_union.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/adam/github/computational-geometry/polygon_union.cpp > CMakeFiles/PolygonUnion.dir/polygon_union.cpp.i

CMakeFiles/PolygonUnion.dir/polygon_union.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PolygonUnion.dir/polygon_union.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/adam/github/computational-geometry/polygon_union.cpp -o CMakeFiles/PolygonUnion.dir/polygon_union.cpp.s

CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.requires:
.PHONY : CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.requires

CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.provides: CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.requires
	$(MAKE) -f CMakeFiles/PolygonUnion.dir/build.make CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.provides.build
.PHONY : CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.provides

CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.provides.build: CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o

# Object files for target PolygonUnion
PolygonUnion_OBJECTS = \
"CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o" \
"CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o"

# External object files for target PolygonUnion
PolygonUnion_EXTERNAL_OBJECTS =

PolygonUnion: CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o
PolygonUnion: CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o
PolygonUnion: CMakeFiles/PolygonUnion.dir/build.make
PolygonUnion: /usr/local/lib/libopencv_viz.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_videostab.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_videoio.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_video.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_superres.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_stitching.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_shape.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_photo.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_objdetect.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_ml.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_imgproc.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_highgui.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_flann.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_features2d.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_core.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_calib3d.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_viz.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_videostab.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_videoio.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_video.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_superres.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_stitching.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_shape.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_photo.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_objdetect.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_ml.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_imgproc.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_highgui.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_flann.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_features2d.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_core.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_calib3d.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_features2d.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_ml.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_highgui.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_videoio.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_flann.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_video.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_imgproc.so.3.1.0
PolygonUnion: /usr/local/lib/libopencv_core.so.3.1.0
PolygonUnion: CMakeFiles/PolygonUnion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable PolygonUnion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PolygonUnion.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PolygonUnion.dir/build: PolygonUnion
.PHONY : CMakeFiles/PolygonUnion.dir/build

CMakeFiles/PolygonUnion.dir/requires: CMakeFiles/PolygonUnion.dir/geofunctions.cpp.o.requires
CMakeFiles/PolygonUnion.dir/requires: CMakeFiles/PolygonUnion.dir/polygon_union.cpp.o.requires
.PHONY : CMakeFiles/PolygonUnion.dir/requires

CMakeFiles/PolygonUnion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PolygonUnion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PolygonUnion.dir/clean

CMakeFiles/PolygonUnion.dir/depend:
	cd /home/adam/github/computational-geometry && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/github/computational-geometry /home/adam/github/computational-geometry /home/adam/github/computational-geometry /home/adam/github/computational-geometry /home/adam/github/computational-geometry/CMakeFiles/PolygonUnion.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PolygonUnion.dir/depend

