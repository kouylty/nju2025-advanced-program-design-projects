# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /media/sf_apd/PA-1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/sf_apd/PA-1/build

# Include any dependencies generated for this target.
include CMakeFiles/FileSimulator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FileSimulator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FileSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FileSimulator.dir/flags.make

CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o: CMakeFiles/FileSimulator.dir/flags.make
CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o: /media/sf_apd/PA-1/src/ClientInterface.cpp
CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o: CMakeFiles/FileSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o -MF CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o.d -o CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o -c /media/sf_apd/PA-1/src/ClientInterface.cpp

CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_apd/PA-1/src/ClientInterface.cpp > CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.i

CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_apd/PA-1/src/ClientInterface.cpp -o CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.s

CMakeFiles/FileSimulator.dir/src/Directory.cpp.o: CMakeFiles/FileSimulator.dir/flags.make
CMakeFiles/FileSimulator.dir/src/Directory.cpp.o: /media/sf_apd/PA-1/src/Directory.cpp
CMakeFiles/FileSimulator.dir/src/Directory.cpp.o: CMakeFiles/FileSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FileSimulator.dir/src/Directory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSimulator.dir/src/Directory.cpp.o -MF CMakeFiles/FileSimulator.dir/src/Directory.cpp.o.d -o CMakeFiles/FileSimulator.dir/src/Directory.cpp.o -c /media/sf_apd/PA-1/src/Directory.cpp

CMakeFiles/FileSimulator.dir/src/Directory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSimulator.dir/src/Directory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_apd/PA-1/src/Directory.cpp > CMakeFiles/FileSimulator.dir/src/Directory.cpp.i

CMakeFiles/FileSimulator.dir/src/Directory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSimulator.dir/src/Directory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_apd/PA-1/src/Directory.cpp -o CMakeFiles/FileSimulator.dir/src/Directory.cpp.s

CMakeFiles/FileSimulator.dir/src/File.cpp.o: CMakeFiles/FileSimulator.dir/flags.make
CMakeFiles/FileSimulator.dir/src/File.cpp.o: /media/sf_apd/PA-1/src/File.cpp
CMakeFiles/FileSimulator.dir/src/File.cpp.o: CMakeFiles/FileSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FileSimulator.dir/src/File.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSimulator.dir/src/File.cpp.o -MF CMakeFiles/FileSimulator.dir/src/File.cpp.o.d -o CMakeFiles/FileSimulator.dir/src/File.cpp.o -c /media/sf_apd/PA-1/src/File.cpp

CMakeFiles/FileSimulator.dir/src/File.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSimulator.dir/src/File.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_apd/PA-1/src/File.cpp > CMakeFiles/FileSimulator.dir/src/File.cpp.i

CMakeFiles/FileSimulator.dir/src/File.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSimulator.dir/src/File.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_apd/PA-1/src/File.cpp -o CMakeFiles/FileSimulator.dir/src/File.cpp.s

CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o: CMakeFiles/FileSimulator.dir/flags.make
CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o: /media/sf_apd/PA-1/src/FileObj.cpp
CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o: CMakeFiles/FileSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o -MF CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o.d -o CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o -c /media/sf_apd/PA-1/src/FileObj.cpp

CMakeFiles/FileSimulator.dir/src/FileObj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSimulator.dir/src/FileObj.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_apd/PA-1/src/FileObj.cpp > CMakeFiles/FileSimulator.dir/src/FileObj.cpp.i

CMakeFiles/FileSimulator.dir/src/FileObj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSimulator.dir/src/FileObj.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_apd/PA-1/src/FileObj.cpp -o CMakeFiles/FileSimulator.dir/src/FileObj.cpp.s

CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o: CMakeFiles/FileSimulator.dir/flags.make
CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o: /media/sf_apd/PA-1/src/FileSystem.cpp
CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o: CMakeFiles/FileSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o -MF CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o.d -o CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o -c /media/sf_apd/PA-1/src/FileSystem.cpp

CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_apd/PA-1/src/FileSystem.cpp > CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.i

CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_apd/PA-1/src/FileSystem.cpp -o CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.s

CMakeFiles/FileSimulator.dir/src/VFS.cpp.o: CMakeFiles/FileSimulator.dir/flags.make
CMakeFiles/FileSimulator.dir/src/VFS.cpp.o: /media/sf_apd/PA-1/src/VFS.cpp
CMakeFiles/FileSimulator.dir/src/VFS.cpp.o: CMakeFiles/FileSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FileSimulator.dir/src/VFS.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSimulator.dir/src/VFS.cpp.o -MF CMakeFiles/FileSimulator.dir/src/VFS.cpp.o.d -o CMakeFiles/FileSimulator.dir/src/VFS.cpp.o -c /media/sf_apd/PA-1/src/VFS.cpp

CMakeFiles/FileSimulator.dir/src/VFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSimulator.dir/src/VFS.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_apd/PA-1/src/VFS.cpp > CMakeFiles/FileSimulator.dir/src/VFS.cpp.i

CMakeFiles/FileSimulator.dir/src/VFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSimulator.dir/src/VFS.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_apd/PA-1/src/VFS.cpp -o CMakeFiles/FileSimulator.dir/src/VFS.cpp.s

CMakeFiles/FileSimulator.dir/src/main.cpp.o: CMakeFiles/FileSimulator.dir/flags.make
CMakeFiles/FileSimulator.dir/src/main.cpp.o: /media/sf_apd/PA-1/src/main.cpp
CMakeFiles/FileSimulator.dir/src/main.cpp.o: CMakeFiles/FileSimulator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/FileSimulator.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FileSimulator.dir/src/main.cpp.o -MF CMakeFiles/FileSimulator.dir/src/main.cpp.o.d -o CMakeFiles/FileSimulator.dir/src/main.cpp.o -c /media/sf_apd/PA-1/src/main.cpp

CMakeFiles/FileSimulator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FileSimulator.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/sf_apd/PA-1/src/main.cpp > CMakeFiles/FileSimulator.dir/src/main.cpp.i

CMakeFiles/FileSimulator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FileSimulator.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/sf_apd/PA-1/src/main.cpp -o CMakeFiles/FileSimulator.dir/src/main.cpp.s

# Object files for target FileSimulator
FileSimulator_OBJECTS = \
"CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o" \
"CMakeFiles/FileSimulator.dir/src/Directory.cpp.o" \
"CMakeFiles/FileSimulator.dir/src/File.cpp.o" \
"CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o" \
"CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o" \
"CMakeFiles/FileSimulator.dir/src/VFS.cpp.o" \
"CMakeFiles/FileSimulator.dir/src/main.cpp.o"

# External object files for target FileSimulator
FileSimulator_EXTERNAL_OBJECTS =

bin/FileSimulator: CMakeFiles/FileSimulator.dir/src/ClientInterface.cpp.o
bin/FileSimulator: CMakeFiles/FileSimulator.dir/src/Directory.cpp.o
bin/FileSimulator: CMakeFiles/FileSimulator.dir/src/File.cpp.o
bin/FileSimulator: CMakeFiles/FileSimulator.dir/src/FileObj.cpp.o
bin/FileSimulator: CMakeFiles/FileSimulator.dir/src/FileSystem.cpp.o
bin/FileSimulator: CMakeFiles/FileSimulator.dir/src/VFS.cpp.o
bin/FileSimulator: CMakeFiles/FileSimulator.dir/src/main.cpp.o
bin/FileSimulator: CMakeFiles/FileSimulator.dir/build.make
bin/FileSimulator: CMakeFiles/FileSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/media/sf_apd/PA-1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable bin/FileSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FileSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FileSimulator.dir/build: bin/FileSimulator
.PHONY : CMakeFiles/FileSimulator.dir/build

CMakeFiles/FileSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FileSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FileSimulator.dir/clean

CMakeFiles/FileSimulator.dir/depend:
	cd /media/sf_apd/PA-1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/sf_apd/PA-1 /media/sf_apd/PA-1 /media/sf_apd/PA-1/build /media/sf_apd/PA-1/build /media/sf_apd/PA-1/build/CMakeFiles/FileSimulator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FileSimulator.dir/depend

