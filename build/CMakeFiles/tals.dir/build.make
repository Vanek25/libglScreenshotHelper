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
CMAKE_SOURCE_DIR = /home/neon/projects/tals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neon/projects/tals/build

# Include any dependencies generated for this target.
include CMakeFiles/tals.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tals.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tals.dir/flags.make

CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o: CMakeFiles/tals.dir/flags.make
CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o: ../libglScreenshotHelper/src/main.cpp
CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o: CMakeFiles/tals.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neon/projects/tals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o -MF CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o.d -o CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o -c /home/neon/projects/tals/libglScreenshotHelper/src/main.cpp

CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neon/projects/tals/libglScreenshotHelper/src/main.cpp > CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.i

CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neon/projects/tals/libglScreenshotHelper/src/main.cpp -o CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.s

CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o: CMakeFiles/tals.dir/flags.make
CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o: ../libglScreenshotHelper/src/glScreenshotHelper.cpp
CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o: CMakeFiles/tals.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neon/projects/tals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o -MF CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o.d -o CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o -c /home/neon/projects/tals/libglScreenshotHelper/src/glScreenshotHelper.cpp

CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neon/projects/tals/libglScreenshotHelper/src/glScreenshotHelper.cpp > CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.i

CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neon/projects/tals/libglScreenshotHelper/src/glScreenshotHelper.cpp -o CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.s

# Object files for target tals
tals_OBJECTS = \
"CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o" \
"CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o"

# External object files for target tals
tals_EXTERNAL_OBJECTS =

tals: CMakeFiles/tals.dir/libglScreenshotHelper/src/main.cpp.o
tals: CMakeFiles/tals.dir/libglScreenshotHelper/src/glScreenshotHelper.cpp.o
tals: CMakeFiles/tals.dir/build.make
tals: libglScreenshotHelper.a
tals: /usr/lib/x86_64-linux-gnu/libOpenGL.so
tals: /usr/lib/x86_64-linux-gnu/libGLX.so
tals: /usr/lib/x86_64-linux-gnu/libGLU.so
tals: /usr/local/lib/libglfw3.a
tals: /usr/lib/x86_64-linux-gnu/librt.a
tals: /usr/lib/x86_64-linux-gnu/libm.so
tals: CMakeFiles/tals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neon/projects/tals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable tals"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tals.dir/build: tals
.PHONY : CMakeFiles/tals.dir/build

CMakeFiles/tals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tals.dir/clean

CMakeFiles/tals.dir/depend:
	cd /home/neon/projects/tals/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neon/projects/tals /home/neon/projects/tals /home/neon/projects/tals/build /home/neon/projects/tals/build /home/neon/projects/tals/build/CMakeFiles/tals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tals.dir/depend

