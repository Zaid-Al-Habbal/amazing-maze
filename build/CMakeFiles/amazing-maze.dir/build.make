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
CMAKE_SOURCE_DIR = /home/zaidalhabbal/Documents/OpenGL/amazing-maze

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zaidalhabbal/Documents/OpenGL/amazing-maze/build

# Include any dependencies generated for this target.
include CMakeFiles/amazing-maze.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/amazing-maze.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/amazing-maze.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/amazing-maze.dir/flags.make

CMakeFiles/amazing-maze.dir/src/main.cpp.o: CMakeFiles/amazing-maze.dir/flags.make
CMakeFiles/amazing-maze.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/amazing-maze.dir/src/main.cpp.o: CMakeFiles/amazing-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/amazing-maze.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/amazing-maze.dir/src/main.cpp.o -MF CMakeFiles/amazing-maze.dir/src/main.cpp.o.d -o CMakeFiles/amazing-maze.dir/src/main.cpp.o -c /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/main.cpp

CMakeFiles/amazing-maze.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amazing-maze.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/main.cpp > CMakeFiles/amazing-maze.dir/src/main.cpp.i

CMakeFiles/amazing-maze.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amazing-maze.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/main.cpp -o CMakeFiles/amazing-maze.dir/src/main.cpp.s

CMakeFiles/amazing-maze.dir/src/glad.c.o: CMakeFiles/amazing-maze.dir/flags.make
CMakeFiles/amazing-maze.dir/src/glad.c.o: ../src/glad.c
CMakeFiles/amazing-maze.dir/src/glad.c.o: CMakeFiles/amazing-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/amazing-maze.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/amazing-maze.dir/src/glad.c.o -MF CMakeFiles/amazing-maze.dir/src/glad.c.o.d -o CMakeFiles/amazing-maze.dir/src/glad.c.o -c /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/glad.c

CMakeFiles/amazing-maze.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/amazing-maze.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/glad.c > CMakeFiles/amazing-maze.dir/src/glad.c.i

CMakeFiles/amazing-maze.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/amazing-maze.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/glad.c -o CMakeFiles/amazing-maze.dir/src/glad.c.s

CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o: CMakeFiles/amazing-maze.dir/flags.make
CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o: ../src/stb_image.cpp
CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o: CMakeFiles/amazing-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o -MF CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o.d -o CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o -c /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/stb_image.cpp

CMakeFiles/amazing-maze.dir/src/stb_image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amazing-maze.dir/src/stb_image.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/stb_image.cpp > CMakeFiles/amazing-maze.dir/src/stb_image.cpp.i

CMakeFiles/amazing-maze.dir/src/stb_image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amazing-maze.dir/src/stb_image.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/stb_image.cpp -o CMakeFiles/amazing-maze.dir/src/stb_image.cpp.s

CMakeFiles/amazing-maze.dir/src/VAO.cpp.o: CMakeFiles/amazing-maze.dir/flags.make
CMakeFiles/amazing-maze.dir/src/VAO.cpp.o: ../src/VAO.cpp
CMakeFiles/amazing-maze.dir/src/VAO.cpp.o: CMakeFiles/amazing-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/amazing-maze.dir/src/VAO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/amazing-maze.dir/src/VAO.cpp.o -MF CMakeFiles/amazing-maze.dir/src/VAO.cpp.o.d -o CMakeFiles/amazing-maze.dir/src/VAO.cpp.o -c /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/VAO.cpp

CMakeFiles/amazing-maze.dir/src/VAO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amazing-maze.dir/src/VAO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/VAO.cpp > CMakeFiles/amazing-maze.dir/src/VAO.cpp.i

CMakeFiles/amazing-maze.dir/src/VAO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amazing-maze.dir/src/VAO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/VAO.cpp -o CMakeFiles/amazing-maze.dir/src/VAO.cpp.s

CMakeFiles/amazing-maze.dir/src/VBO.cpp.o: CMakeFiles/amazing-maze.dir/flags.make
CMakeFiles/amazing-maze.dir/src/VBO.cpp.o: ../src/VBO.cpp
CMakeFiles/amazing-maze.dir/src/VBO.cpp.o: CMakeFiles/amazing-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/amazing-maze.dir/src/VBO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/amazing-maze.dir/src/VBO.cpp.o -MF CMakeFiles/amazing-maze.dir/src/VBO.cpp.o.d -o CMakeFiles/amazing-maze.dir/src/VBO.cpp.o -c /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/VBO.cpp

CMakeFiles/amazing-maze.dir/src/VBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amazing-maze.dir/src/VBO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/VBO.cpp > CMakeFiles/amazing-maze.dir/src/VBO.cpp.i

CMakeFiles/amazing-maze.dir/src/VBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amazing-maze.dir/src/VBO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/VBO.cpp -o CMakeFiles/amazing-maze.dir/src/VBO.cpp.s

CMakeFiles/amazing-maze.dir/src/EBO.cpp.o: CMakeFiles/amazing-maze.dir/flags.make
CMakeFiles/amazing-maze.dir/src/EBO.cpp.o: ../src/EBO.cpp
CMakeFiles/amazing-maze.dir/src/EBO.cpp.o: CMakeFiles/amazing-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/amazing-maze.dir/src/EBO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/amazing-maze.dir/src/EBO.cpp.o -MF CMakeFiles/amazing-maze.dir/src/EBO.cpp.o.d -o CMakeFiles/amazing-maze.dir/src/EBO.cpp.o -c /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/EBO.cpp

CMakeFiles/amazing-maze.dir/src/EBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amazing-maze.dir/src/EBO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/EBO.cpp > CMakeFiles/amazing-maze.dir/src/EBO.cpp.i

CMakeFiles/amazing-maze.dir/src/EBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amazing-maze.dir/src/EBO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/EBO.cpp -o CMakeFiles/amazing-maze.dir/src/EBO.cpp.s

CMakeFiles/amazing-maze.dir/src/Texture.cpp.o: CMakeFiles/amazing-maze.dir/flags.make
CMakeFiles/amazing-maze.dir/src/Texture.cpp.o: ../src/Texture.cpp
CMakeFiles/amazing-maze.dir/src/Texture.cpp.o: CMakeFiles/amazing-maze.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/amazing-maze.dir/src/Texture.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/amazing-maze.dir/src/Texture.cpp.o -MF CMakeFiles/amazing-maze.dir/src/Texture.cpp.o.d -o CMakeFiles/amazing-maze.dir/src/Texture.cpp.o -c /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/Texture.cpp

CMakeFiles/amazing-maze.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/amazing-maze.dir/src/Texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/Texture.cpp > CMakeFiles/amazing-maze.dir/src/Texture.cpp.i

CMakeFiles/amazing-maze.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/amazing-maze.dir/src/Texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zaidalhabbal/Documents/OpenGL/amazing-maze/src/Texture.cpp -o CMakeFiles/amazing-maze.dir/src/Texture.cpp.s

# Object files for target amazing-maze
amazing__maze_OBJECTS = \
"CMakeFiles/amazing-maze.dir/src/main.cpp.o" \
"CMakeFiles/amazing-maze.dir/src/glad.c.o" \
"CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o" \
"CMakeFiles/amazing-maze.dir/src/VAO.cpp.o" \
"CMakeFiles/amazing-maze.dir/src/VBO.cpp.o" \
"CMakeFiles/amazing-maze.dir/src/EBO.cpp.o" \
"CMakeFiles/amazing-maze.dir/src/Texture.cpp.o"

# External object files for target amazing-maze
amazing__maze_EXTERNAL_OBJECTS =

amazing-maze: CMakeFiles/amazing-maze.dir/src/main.cpp.o
amazing-maze: CMakeFiles/amazing-maze.dir/src/glad.c.o
amazing-maze: CMakeFiles/amazing-maze.dir/src/stb_image.cpp.o
amazing-maze: CMakeFiles/amazing-maze.dir/src/VAO.cpp.o
amazing-maze: CMakeFiles/amazing-maze.dir/src/VBO.cpp.o
amazing-maze: CMakeFiles/amazing-maze.dir/src/EBO.cpp.o
amazing-maze: CMakeFiles/amazing-maze.dir/src/Texture.cpp.o
amazing-maze: CMakeFiles/amazing-maze.dir/build.make
amazing-maze: /usr/lib/x86_64-linux-gnu/libGLX.so
amazing-maze: /usr/lib/x86_64-linux-gnu/libOpenGL.so
amazing-maze: CMakeFiles/amazing-maze.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable amazing-maze"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/amazing-maze.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/amazing-maze.dir/build: amazing-maze
.PHONY : CMakeFiles/amazing-maze.dir/build

CMakeFiles/amazing-maze.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/amazing-maze.dir/cmake_clean.cmake
.PHONY : CMakeFiles/amazing-maze.dir/clean

CMakeFiles/amazing-maze.dir/depend:
	cd /home/zaidalhabbal/Documents/OpenGL/amazing-maze/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zaidalhabbal/Documents/OpenGL/amazing-maze /home/zaidalhabbal/Documents/OpenGL/amazing-maze /home/zaidalhabbal/Documents/OpenGL/amazing-maze/build /home/zaidalhabbal/Documents/OpenGL/amazing-maze/build /home/zaidalhabbal/Documents/OpenGL/amazing-maze/build/CMakeFiles/amazing-maze.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/amazing-maze.dir/depend

