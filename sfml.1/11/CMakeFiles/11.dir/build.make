# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\programs\C++\CppDistro\cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\programs\C++\CppDistro\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\programs\C++\LabsC++\sfml.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\programs\C++\LabsC++\sfml.1

# Include any dependencies generated for this target.
include 11/CMakeFiles/11.dir/depend.make

# Include the progress variables for this target.
include 11/CMakeFiles/11.dir/progress.make

# Include the compile flags for this target's objects.
include 11/CMakeFiles/11.dir/flags.make

11/CMakeFiles/11.dir/main.cpp.obj: 11/CMakeFiles/11.dir/flags.make
11/CMakeFiles/11.dir/main.cpp.obj: 11/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\programs\C++\LabsC++\sfml.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 11/CMakeFiles/11.dir/main.cpp.obj"
	cd /d D:\programs\C++\LabsC++\sfml.1\11 && D:\programs\C++\CppDistro\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\11.dir\main.cpp.obj -c D:\programs\C++\LabsC++\sfml.1\11\main.cpp

11/CMakeFiles/11.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11.dir/main.cpp.i"
	cd /d D:\programs\C++\LabsC++\sfml.1\11 && D:\programs\C++\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\programs\C++\LabsC++\sfml.1\11\main.cpp > CMakeFiles\11.dir\main.cpp.i

11/CMakeFiles/11.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11.dir/main.cpp.s"
	cd /d D:\programs\C++\LabsC++\sfml.1\11 && D:\programs\C++\CppDistro\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\programs\C++\LabsC++\sfml.1\11\main.cpp -o CMakeFiles\11.dir\main.cpp.s

11/CMakeFiles/11.dir/main.cpp.obj.requires:

.PHONY : 11/CMakeFiles/11.dir/main.cpp.obj.requires

11/CMakeFiles/11.dir/main.cpp.obj.provides: 11/CMakeFiles/11.dir/main.cpp.obj.requires
	$(MAKE) -f 11\CMakeFiles\11.dir\build.make 11/CMakeFiles/11.dir/main.cpp.obj.provides.build
.PHONY : 11/CMakeFiles/11.dir/main.cpp.obj.provides

11/CMakeFiles/11.dir/main.cpp.obj.provides.build: 11/CMakeFiles/11.dir/main.cpp.obj


# Object files for target 11
11_OBJECTS = \
"CMakeFiles/11.dir/main.cpp.obj"

# External object files for target 11
11_EXTERNAL_OBJECTS =

11/11.exe: 11/CMakeFiles/11.dir/main.cpp.obj
11/11.exe: 11/CMakeFiles/11.dir/build.make
11/11.exe: D:/programs/C++/CppDistro/MinGW/lib/libsfml-window-s.a
11/11.exe: D:/programs/C++/CppDistro/MinGW/lib/libsfml-graphics-s.a
11/11.exe: D:/programs/C++/CppDistro/MinGW/lib/libsfml-system-s.a
11/11.exe: D:/programs/C++/CppDistro/MinGW/lib/libfreetype.a
11/11.exe: D:/programs/C++/CppDistro/MinGW/lib/libjpeg.a
11/11.exe: 11/CMakeFiles/11.dir/linklibs.rsp
11/11.exe: 11/CMakeFiles/11.dir/objects1.rsp
11/11.exe: 11/CMakeFiles/11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\programs\C++\LabsC++\sfml.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 11.exe"
	cd /d D:\programs\C++\LabsC++\sfml.1\11 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
11/CMakeFiles/11.dir/build: 11/11.exe

.PHONY : 11/CMakeFiles/11.dir/build

11/CMakeFiles/11.dir/requires: 11/CMakeFiles/11.dir/main.cpp.obj.requires

.PHONY : 11/CMakeFiles/11.dir/requires

11/CMakeFiles/11.dir/clean:
	cd /d D:\programs\C++\LabsC++\sfml.1\11 && $(CMAKE_COMMAND) -P CMakeFiles\11.dir\cmake_clean.cmake
.PHONY : 11/CMakeFiles/11.dir/clean

11/CMakeFiles/11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\programs\C++\LabsC++\sfml.1 D:\programs\C++\LabsC++\sfml.1\11 D:\programs\C++\LabsC++\sfml.1 D:\programs\C++\LabsC++\sfml.1\11 D:\programs\C++\LabsC++\sfml.1\11\CMakeFiles\11.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : 11/CMakeFiles/11.dir/depend

