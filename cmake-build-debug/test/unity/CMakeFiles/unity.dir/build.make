# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\alexa\CLionProjects\RV32EM-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug

# Include any dependencies generated for this target.
include test/unity/CMakeFiles/unity.dir/depend.make

# Include the progress variables for this target.
include test/unity/CMakeFiles/unity.dir/progress.make

# Include the compile flags for this target's objects.
include test/unity/CMakeFiles/unity.dir/flags.make

test/unity/CMakeFiles/unity.dir/unity.c.obj: test/unity/CMakeFiles/unity.dir/flags.make
test/unity/CMakeFiles/unity.dir/unity.c.obj: ../test/unity/unity.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/unity/CMakeFiles/unity.dir/unity.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\unity.dir\unity.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\unity\unity.c

test/unity/CMakeFiles/unity.dir/unity.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/unity.dir/unity.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\unity\unity.c > CMakeFiles\unity.dir\unity.c.i

test/unity/CMakeFiles/unity.dir/unity.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/unity.dir/unity.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\unity\unity.c -o CMakeFiles\unity.dir\unity.c.s

# Object files for target unity
unity_OBJECTS = \
"CMakeFiles/unity.dir/unity.c.obj"

# External object files for target unity
unity_EXTERNAL_OBJECTS =

test/unity/libunity.a: test/unity/CMakeFiles/unity.dir/unity.c.obj
test/unity/libunity.a: test/unity/CMakeFiles/unity.dir/build.make
test/unity/libunity.a: test/unity/CMakeFiles/unity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libunity.a"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity && $(CMAKE_COMMAND) -P CMakeFiles\unity.dir\cmake_clean_target.cmake
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\unity.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unity/CMakeFiles/unity.dir/build: test/unity/libunity.a

.PHONY : test/unity/CMakeFiles/unity.dir/build

test/unity/CMakeFiles/unity.dir/clean:
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity && $(CMAKE_COMMAND) -P CMakeFiles\unity.dir\cmake_clean.cmake
.PHONY : test/unity/CMakeFiles/unity.dir/clean

test/unity/CMakeFiles/unity.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\alexa\CLionProjects\RV32EM-simulator C:\Users\alexa\CLionProjects\RV32EM-simulator\test\unity C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\unity\CMakeFiles\unity.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/unity/CMakeFiles/unity.dir/depend

