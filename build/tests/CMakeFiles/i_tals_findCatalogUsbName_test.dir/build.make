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
CMAKE_SOURCE_DIR = /home/uba/projects/libglScreenshotHelper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uba/projects/libglScreenshotHelper/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/flags.make

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/flags.make
tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o: ../tests/testMain.cpp
tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uba/projects/libglScreenshotHelper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o"
	cd /home/uba/projects/libglScreenshotHelper/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o -MF CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o.d -o CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o -c /home/uba/projects/libglScreenshotHelper/tests/testMain.cpp

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.i"
	cd /home/uba/projects/libglScreenshotHelper/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uba/projects/libglScreenshotHelper/tests/testMain.cpp > CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.i

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.s"
	cd /home/uba/projects/libglScreenshotHelper/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uba/projects/libglScreenshotHelper/tests/testMain.cpp -o CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.s

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/flags.make
tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o: ../tests/testFindCatalogUsbName.cpp
tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uba/projects/libglScreenshotHelper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o"
	cd /home/uba/projects/libglScreenshotHelper/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o -MF CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o.d -o CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o -c /home/uba/projects/libglScreenshotHelper/tests/testFindCatalogUsbName.cpp

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.i"
	cd /home/uba/projects/libglScreenshotHelper/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uba/projects/libglScreenshotHelper/tests/testFindCatalogUsbName.cpp > CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.i

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.s"
	cd /home/uba/projects/libglScreenshotHelper/build/tests && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uba/projects/libglScreenshotHelper/tests/testFindCatalogUsbName.cpp -o CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.s

# Object files for target i_tals_findCatalogUsbName_test
i_tals_findCatalogUsbName_test_OBJECTS = \
"CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o" \
"CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o"

# External object files for target i_tals_findCatalogUsbName_test
i_tals_findCatalogUsbName_test_EXTERNAL_OBJECTS =

tests/i_tals_findCatalogUsbName_test: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testMain.cpp.o
tests/i_tals_findCatalogUsbName_test: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/testFindCatalogUsbName.cpp.o
tests/i_tals_findCatalogUsbName_test: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/build.make
tests/i_tals_findCatalogUsbName_test: libglScreenshotHelper.a
tests/i_tals_findCatalogUsbName_test: tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uba/projects/libglScreenshotHelper/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable i_tals_findCatalogUsbName_test"
	cd /home/uba/projects/libglScreenshotHelper/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/i_tals_findCatalogUsbName_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/build: tests/i_tals_findCatalogUsbName_test
.PHONY : tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/build

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/clean:
	cd /home/uba/projects/libglScreenshotHelper/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/i_tals_findCatalogUsbName_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/clean

tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/depend:
	cd /home/uba/projects/libglScreenshotHelper/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uba/projects/libglScreenshotHelper /home/uba/projects/libglScreenshotHelper/tests /home/uba/projects/libglScreenshotHelper/build /home/uba/projects/libglScreenshotHelper/build/tests /home/uba/projects/libglScreenshotHelper/build/tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/i_tals_findCatalogUsbName_test.dir/depend

