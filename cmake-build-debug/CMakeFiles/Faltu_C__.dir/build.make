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
CMAKE_COMMAND = /opt/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/devesh/Desktop/Faltu C++"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/devesh/Desktop/Faltu C++/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Faltu_C__.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Faltu_C__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Faltu_C__.dir/flags.make

CMakeFiles/Faltu_C__.dir/main.cpp.o: CMakeFiles/Faltu_C__.dir/flags.make
CMakeFiles/Faltu_C__.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/devesh/Desktop/Faltu C++/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Faltu_C__.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Faltu_C__.dir/main.cpp.o -c "/home/devesh/Desktop/Faltu C++/main.cpp"

CMakeFiles/Faltu_C__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Faltu_C__.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/devesh/Desktop/Faltu C++/main.cpp" > CMakeFiles/Faltu_C__.dir/main.cpp.i

CMakeFiles/Faltu_C__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Faltu_C__.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/devesh/Desktop/Faltu C++/main.cpp" -o CMakeFiles/Faltu_C__.dir/main.cpp.s

CMakeFiles/Faltu_C__.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Faltu_C__.dir/main.cpp.o.requires

CMakeFiles/Faltu_C__.dir/main.cpp.o.provides: CMakeFiles/Faltu_C__.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Faltu_C__.dir/build.make CMakeFiles/Faltu_C__.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Faltu_C__.dir/main.cpp.o.provides

CMakeFiles/Faltu_C__.dir/main.cpp.o.provides.build: CMakeFiles/Faltu_C__.dir/main.cpp.o


CMakeFiles/Faltu_C__.dir/VM.cpp.o: CMakeFiles/Faltu_C__.dir/flags.make
CMakeFiles/Faltu_C__.dir/VM.cpp.o: ../VM.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/devesh/Desktop/Faltu C++/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Faltu_C__.dir/VM.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Faltu_C__.dir/VM.cpp.o -c "/home/devesh/Desktop/Faltu C++/VM.cpp"

CMakeFiles/Faltu_C__.dir/VM.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Faltu_C__.dir/VM.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/devesh/Desktop/Faltu C++/VM.cpp" > CMakeFiles/Faltu_C__.dir/VM.cpp.i

CMakeFiles/Faltu_C__.dir/VM.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Faltu_C__.dir/VM.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/devesh/Desktop/Faltu C++/VM.cpp" -o CMakeFiles/Faltu_C__.dir/VM.cpp.s

CMakeFiles/Faltu_C__.dir/VM.cpp.o.requires:

.PHONY : CMakeFiles/Faltu_C__.dir/VM.cpp.o.requires

CMakeFiles/Faltu_C__.dir/VM.cpp.o.provides: CMakeFiles/Faltu_C__.dir/VM.cpp.o.requires
	$(MAKE) -f CMakeFiles/Faltu_C__.dir/build.make CMakeFiles/Faltu_C__.dir/VM.cpp.o.provides.build
.PHONY : CMakeFiles/Faltu_C__.dir/VM.cpp.o.provides

CMakeFiles/Faltu_C__.dir/VM.cpp.o.provides.build: CMakeFiles/Faltu_C__.dir/VM.cpp.o


# Object files for target Faltu_C__
Faltu_C___OBJECTS = \
"CMakeFiles/Faltu_C__.dir/main.cpp.o" \
"CMakeFiles/Faltu_C__.dir/VM.cpp.o"

# External object files for target Faltu_C__
Faltu_C___EXTERNAL_OBJECTS =

Faltu_C__: CMakeFiles/Faltu_C__.dir/main.cpp.o
Faltu_C__: CMakeFiles/Faltu_C__.dir/VM.cpp.o
Faltu_C__: CMakeFiles/Faltu_C__.dir/build.make
Faltu_C__: CMakeFiles/Faltu_C__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/devesh/Desktop/Faltu C++/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Faltu_C__"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Faltu_C__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Faltu_C__.dir/build: Faltu_C__

.PHONY : CMakeFiles/Faltu_C__.dir/build

CMakeFiles/Faltu_C__.dir/requires: CMakeFiles/Faltu_C__.dir/main.cpp.o.requires
CMakeFiles/Faltu_C__.dir/requires: CMakeFiles/Faltu_C__.dir/VM.cpp.o.requires

.PHONY : CMakeFiles/Faltu_C__.dir/requires

CMakeFiles/Faltu_C__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Faltu_C__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Faltu_C__.dir/clean

CMakeFiles/Faltu_C__.dir/depend:
	cd "/home/devesh/Desktop/Faltu C++/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/devesh/Desktop/Faltu C++" "/home/devesh/Desktop/Faltu C++" "/home/devesh/Desktop/Faltu C++/cmake-build-debug" "/home/devesh/Desktop/Faltu C++/cmake-build-debug" "/home/devesh/Desktop/Faltu C++/cmake-build-debug/CMakeFiles/Faltu_C__.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Faltu_C__.dir/depend
