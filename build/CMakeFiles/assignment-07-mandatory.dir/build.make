# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrebrahin/Downloads/assignment-07-mandatory-files

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrebrahin/Downloads/assignment-07-mandatory-files/build

# Include any dependencies generated for this target.
include CMakeFiles/assignment-07-mandatory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/assignment-07-mandatory.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/assignment-07-mandatory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assignment-07-mandatory.dir/flags.make

CMakeFiles/assignment-07-mandatory.dir/main.cpp.o: CMakeFiles/assignment-07-mandatory.dir/flags.make
CMakeFiles/assignment-07-mandatory.dir/main.cpp.o: /Users/andrebrahin/Downloads/assignment-07-mandatory-files/main.cpp
CMakeFiles/assignment-07-mandatory.dir/main.cpp.o: CMakeFiles/assignment-07-mandatory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/andrebrahin/Downloads/assignment-07-mandatory-files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/assignment-07-mandatory.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/assignment-07-mandatory.dir/main.cpp.o -MF CMakeFiles/assignment-07-mandatory.dir/main.cpp.o.d -o CMakeFiles/assignment-07-mandatory.dir/main.cpp.o -c /Users/andrebrahin/Downloads/assignment-07-mandatory-files/main.cpp

CMakeFiles/assignment-07-mandatory.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/assignment-07-mandatory.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrebrahin/Downloads/assignment-07-mandatory-files/main.cpp > CMakeFiles/assignment-07-mandatory.dir/main.cpp.i

CMakeFiles/assignment-07-mandatory.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/assignment-07-mandatory.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrebrahin/Downloads/assignment-07-mandatory-files/main.cpp -o CMakeFiles/assignment-07-mandatory.dir/main.cpp.s

# Object files for target assignment-07-mandatory
assignment__07__mandatory_OBJECTS = \
"CMakeFiles/assignment-07-mandatory.dir/main.cpp.o"

# External object files for target assignment-07-mandatory
assignment__07__mandatory_EXTERNAL_OBJECTS =

main: CMakeFiles/assignment-07-mandatory.dir/main.cpp.o
main: CMakeFiles/assignment-07-mandatory.dir/build.make
main: CMakeFiles/assignment-07-mandatory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/andrebrahin/Downloads/assignment-07-mandatory-files/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/assignment-07-mandatory.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Copying files to output directory"
	/opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E copy_directory /Users/andrebrahin/Downloads/assignment-07-mandatory-files/files/ /Users/andrebrahin/Downloads/assignment-07-mandatory-files/build

# Rule to build all files generated by this target.
CMakeFiles/assignment-07-mandatory.dir/build: main
.PHONY : CMakeFiles/assignment-07-mandatory.dir/build

CMakeFiles/assignment-07-mandatory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/assignment-07-mandatory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/assignment-07-mandatory.dir/clean

CMakeFiles/assignment-07-mandatory.dir/depend:
	cd /Users/andrebrahin/Downloads/assignment-07-mandatory-files/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrebrahin/Downloads/assignment-07-mandatory-files /Users/andrebrahin/Downloads/assignment-07-mandatory-files /Users/andrebrahin/Downloads/assignment-07-mandatory-files/build /Users/andrebrahin/Downloads/assignment-07-mandatory-files/build /Users/andrebrahin/Downloads/assignment-07-mandatory-files/build/CMakeFiles/assignment-07-mandatory.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/assignment-07-mandatory.dir/depend

