# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /mnt/c/Users/15103/Desktop/251/work4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/15103/Desktop/251/work4/build

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/15103/Desktop/251/work4/build/CMakeFiles /mnt/c/Users/15103/Desktop/251/work4/build//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/15103/Desktop/251/work4/build/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named project4

# Build rule for target.
project4: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 project4
.PHONY : project4

# fast build rule for target.
project4/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/build
.PHONY : project4/fast

#=============================================================================
# Target rules for targets named graph_app

# Build rule for target.
graph_app: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 graph_app
.PHONY : graph_app

# fast build rule for target.
graph_app/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/graph_app.dir/build.make CMakeFiles/graph_app.dir/build
.PHONY : graph_app/fast

src/color_walk.o: src/color_walk.cpp.o
.PHONY : src/color_walk.o

# target to build an object file
src/color_walk.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/color_walk.cpp.o
.PHONY : src/color_walk.cpp.o

src/color_walk.i: src/color_walk.cpp.i
.PHONY : src/color_walk.i

# target to preprocess a source file
src/color_walk.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/color_walk.cpp.i
.PHONY : src/color_walk.cpp.i

src/color_walk.s: src/color_walk.cpp.s
.PHONY : src/color_walk.s

# target to generate assembly for a file
src/color_walk.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/color_walk.cpp.s
.PHONY : src/color_walk.cpp.s

src/graph.o: src/graph.cpp.o
.PHONY : src/graph.o

# target to build an object file
src/graph.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/graph.cpp.o
.PHONY : src/graph.cpp.o

src/graph.i: src/graph.cpp.i
.PHONY : src/graph.i

# target to preprocess a source file
src/graph.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/graph.cpp.i
.PHONY : src/graph.cpp.i

src/graph.s: src/graph.cpp.s
.PHONY : src/graph.s

# target to generate assembly for a file
src/graph.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/graph.cpp.s
.PHONY : src/graph.cpp.s

src/graph_app.o: src/graph_app.cpp.o
.PHONY : src/graph_app.o

# target to build an object file
src/graph_app.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/graph_app.cpp.o
	$(MAKE) $(MAKESILENT) -f CMakeFiles/graph_app.dir/build.make CMakeFiles/graph_app.dir/src/graph_app.cpp.o
.PHONY : src/graph_app.cpp.o

src/graph_app.i: src/graph_app.cpp.i
.PHONY : src/graph_app.i

# target to preprocess a source file
src/graph_app.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/graph_app.cpp.i
	$(MAKE) $(MAKESILENT) -f CMakeFiles/graph_app.dir/build.make CMakeFiles/graph_app.dir/src/graph_app.cpp.i
.PHONY : src/graph_app.cpp.i

src/graph_app.s: src/graph_app.cpp.s
.PHONY : src/graph_app.s

# target to generate assembly for a file
src/graph_app.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/graph_app.cpp.s
	$(MAKE) $(MAKESILENT) -f CMakeFiles/graph_app.dir/build.make CMakeFiles/graph_app.dir/src/graph_app.cpp.s
.PHONY : src/graph_app.cpp.s

src/max_height.o: src/max_height.cpp.o
.PHONY : src/max_height.o

# target to build an object file
src/max_height.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/max_height.cpp.o
.PHONY : src/max_height.cpp.o

src/max_height.i: src/max_height.cpp.i
.PHONY : src/max_height.i

# target to preprocess a source file
src/max_height.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/max_height.cpp.i
.PHONY : src/max_height.cpp.i

src/max_height.s: src/max_height.cpp.s
.PHONY : src/max_height.s

# target to generate assembly for a file
src/max_height.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/max_height.cpp.s
.PHONY : src/max_height.cpp.s

src/scc.o: src/scc.cpp.o
.PHONY : src/scc.o

# target to build an object file
src/scc.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/scc.cpp.o
.PHONY : src/scc.cpp.o

src/scc.i: src/scc.cpp.i
.PHONY : src/scc.i

# target to preprocess a source file
src/scc.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/scc.cpp.i
.PHONY : src/scc.cpp.i

src/scc.s: src/scc.cpp.s
.PHONY : src/scc.s

# target to generate assembly for a file
src/scc.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/project4.dir/build.make CMakeFiles/project4.dir/src/scc.cpp.s
.PHONY : src/scc.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... graph_app"
	@echo "... project4"
	@echo "... src/color_walk.o"
	@echo "... src/color_walk.i"
	@echo "... src/color_walk.s"
	@echo "... src/graph.o"
	@echo "... src/graph.i"
	@echo "... src/graph.s"
	@echo "... src/graph_app.o"
	@echo "... src/graph_app.i"
	@echo "... src/graph_app.s"
	@echo "... src/max_height.o"
	@echo "... src/max_height.i"
	@echo "... src/max_height.s"
	@echo "... src/scc.o"
	@echo "... src/scc.i"
	@echo "... src/scc.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

