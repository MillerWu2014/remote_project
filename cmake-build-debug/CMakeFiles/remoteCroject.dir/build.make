# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /opt/workspace/project/remoteCropject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /opt/workspace/project/remoteCropject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/remoteCroject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/remoteCroject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/remoteCroject.dir/flags.make

CMakeFiles/remoteCroject.dir/main.cpp.o: CMakeFiles/remoteCroject.dir/flags.make
CMakeFiles/remoteCroject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/workspace/project/remoteCropject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/remoteCroject.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/remoteCroject.dir/main.cpp.o -c /opt/workspace/project/remoteCropject/main.cpp

CMakeFiles/remoteCroject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/remoteCroject.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/workspace/project/remoteCropject/main.cpp > CMakeFiles/remoteCroject.dir/main.cpp.i

CMakeFiles/remoteCroject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/remoteCroject.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/workspace/project/remoteCropject/main.cpp -o CMakeFiles/remoteCroject.dir/main.cpp.s

CMakeFiles/remoteCroject.dir/multhreading.c.o: CMakeFiles/remoteCroject.dir/flags.make
CMakeFiles/remoteCroject.dir/multhreading.c.o: ../multhreading.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/workspace/project/remoteCropject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/remoteCroject.dir/multhreading.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/remoteCroject.dir/multhreading.c.o   -c /opt/workspace/project/remoteCropject/multhreading.c

CMakeFiles/remoteCroject.dir/multhreading.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/remoteCroject.dir/multhreading.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /opt/workspace/project/remoteCropject/multhreading.c > CMakeFiles/remoteCroject.dir/multhreading.c.i

CMakeFiles/remoteCroject.dir/multhreading.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/remoteCroject.dir/multhreading.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /opt/workspace/project/remoteCropject/multhreading.c -o CMakeFiles/remoteCroject.dir/multhreading.c.s

CMakeFiles/remoteCroject.dir/mix_thread.cpp.o: CMakeFiles/remoteCroject.dir/flags.make
CMakeFiles/remoteCroject.dir/mix_thread.cpp.o: ../mix_thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/opt/workspace/project/remoteCropject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/remoteCroject.dir/mix_thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/remoteCroject.dir/mix_thread.cpp.o -c /opt/workspace/project/remoteCropject/mix_thread.cpp

CMakeFiles/remoteCroject.dir/mix_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/remoteCroject.dir/mix_thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /opt/workspace/project/remoteCropject/mix_thread.cpp > CMakeFiles/remoteCroject.dir/mix_thread.cpp.i

CMakeFiles/remoteCroject.dir/mix_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/remoteCroject.dir/mix_thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /opt/workspace/project/remoteCropject/mix_thread.cpp -o CMakeFiles/remoteCroject.dir/mix_thread.cpp.s

# Object files for target remoteCroject
remoteCroject_OBJECTS = \
"CMakeFiles/remoteCroject.dir/main.cpp.o" \
"CMakeFiles/remoteCroject.dir/multhreading.c.o" \
"CMakeFiles/remoteCroject.dir/mix_thread.cpp.o"

# External object files for target remoteCroject
remoteCroject_EXTERNAL_OBJECTS =

remoteCroject: CMakeFiles/remoteCroject.dir/main.cpp.o
remoteCroject: CMakeFiles/remoteCroject.dir/multhreading.c.o
remoteCroject: CMakeFiles/remoteCroject.dir/mix_thread.cpp.o
remoteCroject: CMakeFiles/remoteCroject.dir/build.make
remoteCroject: CMakeFiles/remoteCroject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/opt/workspace/project/remoteCropject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable remoteCroject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/remoteCroject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/remoteCroject.dir/build: remoteCroject

.PHONY : CMakeFiles/remoteCroject.dir/build

CMakeFiles/remoteCroject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/remoteCroject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/remoteCroject.dir/clean

CMakeFiles/remoteCroject.dir/depend:
	cd /opt/workspace/project/remoteCropject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /opt/workspace/project/remoteCropject /opt/workspace/project/remoteCropject /opt/workspace/project/remoteCropject/cmake-build-debug /opt/workspace/project/remoteCropject/cmake-build-debug /opt/workspace/project/remoteCropject/cmake-build-debug/CMakeFiles/remoteCroject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/remoteCroject.dir/depend

