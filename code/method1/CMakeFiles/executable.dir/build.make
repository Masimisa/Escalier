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
CMAKE_SOURCE_DIR = /home/masimisa/Documents/Projet/Escalier/code/method1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/masimisa/Documents/Projet/Escalier/code/method1

# Include any dependencies generated for this target.
include CMakeFiles/executable.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/executable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/executable.dir/flags.make

CMakeFiles/executable.dir/final.cpp.o: CMakeFiles/executable.dir/flags.make
CMakeFiles/executable.dir/final.cpp.o: final.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masimisa/Documents/Projet/Escalier/code/method1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/executable.dir/final.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executable.dir/final.cpp.o -c /home/masimisa/Documents/Projet/Escalier/code/method1/final.cpp

CMakeFiles/executable.dir/final.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/final.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masimisa/Documents/Projet/Escalier/code/method1/final.cpp > CMakeFiles/executable.dir/final.cpp.i

CMakeFiles/executable.dir/final.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/final.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masimisa/Documents/Projet/Escalier/code/method1/final.cpp -o CMakeFiles/executable.dir/final.cpp.s

CMakeFiles/executable.dir/final.cpp.o.requires:

.PHONY : CMakeFiles/executable.dir/final.cpp.o.requires

CMakeFiles/executable.dir/final.cpp.o.provides: CMakeFiles/executable.dir/final.cpp.o.requires
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/final.cpp.o.provides.build
.PHONY : CMakeFiles/executable.dir/final.cpp.o.provides

CMakeFiles/executable.dir/final.cpp.o.provides.build: CMakeFiles/executable.dir/final.cpp.o


CMakeFiles/executable.dir/print.cpp.o: CMakeFiles/executable.dir/flags.make
CMakeFiles/executable.dir/print.cpp.o: print.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/masimisa/Documents/Projet/Escalier/code/method1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/executable.dir/print.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executable.dir/print.cpp.o -c /home/masimisa/Documents/Projet/Escalier/code/method1/print.cpp

CMakeFiles/executable.dir/print.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executable.dir/print.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/masimisa/Documents/Projet/Escalier/code/method1/print.cpp > CMakeFiles/executable.dir/print.cpp.i

CMakeFiles/executable.dir/print.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executable.dir/print.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/masimisa/Documents/Projet/Escalier/code/method1/print.cpp -o CMakeFiles/executable.dir/print.cpp.s

CMakeFiles/executable.dir/print.cpp.o.requires:

.PHONY : CMakeFiles/executable.dir/print.cpp.o.requires

CMakeFiles/executable.dir/print.cpp.o.provides: CMakeFiles/executable.dir/print.cpp.o.requires
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/print.cpp.o.provides.build
.PHONY : CMakeFiles/executable.dir/print.cpp.o.provides

CMakeFiles/executable.dir/print.cpp.o.provides.build: CMakeFiles/executable.dir/print.cpp.o


# Object files for target executable
executable_OBJECTS = \
"CMakeFiles/executable.dir/final.cpp.o" \
"CMakeFiles/executable.dir/print.cpp.o"

# External object files for target executable
executable_EXTERNAL_OBJECTS =

executable: CMakeFiles/executable.dir/final.cpp.o
executable: CMakeFiles/executable.dir/print.cpp.o
executable: CMakeFiles/executable.dir/build.make
executable: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
executable: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
executable: CMakeFiles/executable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/masimisa/Documents/Projet/Escalier/code/method1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable executable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/executable.dir/build: executable

.PHONY : CMakeFiles/executable.dir/build

CMakeFiles/executable.dir/requires: CMakeFiles/executable.dir/final.cpp.o.requires
CMakeFiles/executable.dir/requires: CMakeFiles/executable.dir/print.cpp.o.requires

.PHONY : CMakeFiles/executable.dir/requires

CMakeFiles/executable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/executable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/executable.dir/clean

CMakeFiles/executable.dir/depend:
	cd /home/masimisa/Documents/Projet/Escalier/code/method1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/masimisa/Documents/Projet/Escalier/code/method1 /home/masimisa/Documents/Projet/Escalier/code/method1 /home/masimisa/Documents/Projet/Escalier/code/method1 /home/masimisa/Documents/Projet/Escalier/code/method1 /home/masimisa/Documents/Projet/Escalier/code/method1/CMakeFiles/executable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/executable.dir/depend

