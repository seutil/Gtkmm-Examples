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
CMAKE_SOURCE_DIR = /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build

# Include any dependencies generated for this target.
include src/CMakeFiles/personalCrm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/personalCrm.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/personalCrm.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/personalCrm.dir/flags.make

src/gresources.c: ../resources/main-window.glade
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating gresources.c"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/glib-compile-resources --target=/home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src/gresources.c --sourcedir=/home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/../resources --generate-source /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/../resources/gresources.xml

src/CMakeFiles/personalCrm.dir/main.cpp.o: src/CMakeFiles/personalCrm.dir/flags.make
src/CMakeFiles/personalCrm.dir/main.cpp.o: ../src/main.cpp
src/CMakeFiles/personalCrm.dir/main.cpp.o: src/CMakeFiles/personalCrm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/personalCrm.dir/main.cpp.o"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/personalCrm.dir/main.cpp.o -MF CMakeFiles/personalCrm.dir/main.cpp.o.d -o CMakeFiles/personalCrm.dir/main.cpp.o -c /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/main.cpp

src/CMakeFiles/personalCrm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/personalCrm.dir/main.cpp.i"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/main.cpp > CMakeFiles/personalCrm.dir/main.cpp.i

src/CMakeFiles/personalCrm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/personalCrm.dir/main.cpp.s"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/main.cpp -o CMakeFiles/personalCrm.dir/main.cpp.s

src/CMakeFiles/personalCrm.dir/main-window.cpp.o: src/CMakeFiles/personalCrm.dir/flags.make
src/CMakeFiles/personalCrm.dir/main-window.cpp.o: ../src/main-window.cpp
src/CMakeFiles/personalCrm.dir/main-window.cpp.o: src/CMakeFiles/personalCrm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/personalCrm.dir/main-window.cpp.o"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/personalCrm.dir/main-window.cpp.o -MF CMakeFiles/personalCrm.dir/main-window.cpp.o.d -o CMakeFiles/personalCrm.dir/main-window.cpp.o -c /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/main-window.cpp

src/CMakeFiles/personalCrm.dir/main-window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/personalCrm.dir/main-window.cpp.i"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/main-window.cpp > CMakeFiles/personalCrm.dir/main-window.cpp.i

src/CMakeFiles/personalCrm.dir/main-window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/personalCrm.dir/main-window.cpp.s"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src/main-window.cpp -o CMakeFiles/personalCrm.dir/main-window.cpp.s

src/CMakeFiles/personalCrm.dir/gresources.c.o: src/CMakeFiles/personalCrm.dir/flags.make
src/CMakeFiles/personalCrm.dir/gresources.c.o: src/gresources.c
src/CMakeFiles/personalCrm.dir/gresources.c.o: src/CMakeFiles/personalCrm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/personalCrm.dir/gresources.c.o"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/personalCrm.dir/gresources.c.o -MF CMakeFiles/personalCrm.dir/gresources.c.o.d -o CMakeFiles/personalCrm.dir/gresources.c.o -c /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src/gresources.c

src/CMakeFiles/personalCrm.dir/gresources.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/personalCrm.dir/gresources.c.i"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src/gresources.c > CMakeFiles/personalCrm.dir/gresources.c.i

src/CMakeFiles/personalCrm.dir/gresources.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/personalCrm.dir/gresources.c.s"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src/gresources.c -o CMakeFiles/personalCrm.dir/gresources.c.s

# Object files for target personalCrm
personalCrm_OBJECTS = \
"CMakeFiles/personalCrm.dir/main.cpp.o" \
"CMakeFiles/personalCrm.dir/main-window.cpp.o" \
"CMakeFiles/personalCrm.dir/gresources.c.o"

# External object files for target personalCrm
personalCrm_EXTERNAL_OBJECTS =

src/personalCrm: src/CMakeFiles/personalCrm.dir/main.cpp.o
src/personalCrm: src/CMakeFiles/personalCrm.dir/main-window.cpp.o
src/personalCrm: src/CMakeFiles/personalCrm.dir/gresources.c.o
src/personalCrm: src/CMakeFiles/personalCrm.dir/build.make
src/personalCrm: lib/libpersonalCrmLib.a
src/personalCrm: src/CMakeFiles/personalCrm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable personalCrm"
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/personalCrm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/personalCrm.dir/build: src/personalCrm
.PHONY : src/CMakeFiles/personalCrm.dir/build

src/CMakeFiles/personalCrm.dir/clean:
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src && $(CMAKE_COMMAND) -P CMakeFiles/personalCrm.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/personalCrm.dir/clean

src/CMakeFiles/personalCrm.dir/depend: src/gresources.c
	cd /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/src /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src /home/vilya/Programming/C++/GtkmmExamples/PersonalCRM/build/src/CMakeFiles/personalCrm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/personalCrm.dir/depend
