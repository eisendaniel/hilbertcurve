# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Daniel\projects\hilbertcurve

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Daniel\projects\hilbertcurve\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hilbertcurve.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hilbertcurve.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hilbertcurve.dir/flags.make

CMakeFiles/hilbertcurve.dir/main.cpp.obj: CMakeFiles/hilbertcurve.dir/flags.make
CMakeFiles/hilbertcurve.dir/main.cpp.obj: CMakeFiles/hilbertcurve.dir/includes_CXX.rsp
CMakeFiles/hilbertcurve.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Daniel\projects\hilbertcurve\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hilbertcurve.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hilbertcurve.dir\main.cpp.obj -c C:\Users\Daniel\projects\hilbertcurve\main.cpp

CMakeFiles/hilbertcurve.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hilbertcurve.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Daniel\projects\hilbertcurve\main.cpp > CMakeFiles\hilbertcurve.dir\main.cpp.i

CMakeFiles/hilbertcurve.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hilbertcurve.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Daniel\projects\hilbertcurve\main.cpp -o CMakeFiles\hilbertcurve.dir\main.cpp.s

# Object files for target hilbertcurve
hilbertcurve_OBJECTS = \
"CMakeFiles/hilbertcurve.dir/main.cpp.obj"

# External object files for target hilbertcurve
hilbertcurve_EXTERNAL_OBJECTS =

hilbertcurve.exe: CMakeFiles/hilbertcurve.dir/main.cpp.obj
hilbertcurve.exe: CMakeFiles/hilbertcurve.dir/build.make
hilbertcurve.exe: D:/lib/SFML/lib/libsfml-audio-s.a
hilbertcurve.exe: D:/lib/SFML/lib/libsfml-graphics-s.a
hilbertcurve.exe: D:/lib/SFML/lib/libsfml-network-s.a
hilbertcurve.exe: D:/lib/SFML/lib/libsfml-system-s.a
hilbertcurve.exe: D:/lib/SFML/lib/libsfml-window-s.a
hilbertcurve.exe: D:/lib/SFML/lib/libopenal32.a
hilbertcurve.exe: D:/lib/SFML/lib/libvorbisfile.a
hilbertcurve.exe: D:/lib/SFML/lib/libvorbisenc.a
hilbertcurve.exe: D:/lib/SFML/lib/libvorbis.a
hilbertcurve.exe: D:/lib/SFML/lib/libogg.a
hilbertcurve.exe: D:/lib/SFML/lib/libFLAC.a
hilbertcurve.exe: D:/lib/SFML/lib/libfreetype.a
hilbertcurve.exe: D:/lib/SFML/lib/libsfml-system-s.a
hilbertcurve.exe: CMakeFiles/hilbertcurve.dir/linklibs.rsp
hilbertcurve.exe: CMakeFiles/hilbertcurve.dir/objects1.rsp
hilbertcurve.exe: CMakeFiles/hilbertcurve.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Daniel\projects\hilbertcurve\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hilbertcurve.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hilbertcurve.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hilbertcurve.dir/build: hilbertcurve.exe

.PHONY : CMakeFiles/hilbertcurve.dir/build

CMakeFiles/hilbertcurve.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hilbertcurve.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hilbertcurve.dir/clean

CMakeFiles/hilbertcurve.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Daniel\projects\hilbertcurve C:\Users\Daniel\projects\hilbertcurve C:\Users\Daniel\projects\hilbertcurve\cmake-build-debug C:\Users\Daniel\projects\hilbertcurve\cmake-build-debug C:\Users\Daniel\projects\hilbertcurve\cmake-build-debug\CMakeFiles\hilbertcurve.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hilbertcurve.dir/depend

