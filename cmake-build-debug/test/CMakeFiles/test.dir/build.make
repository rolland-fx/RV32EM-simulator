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
include test/CMakeFiles/test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/test.dir/flags.make

test/CMakeFiles/test.dir/__/src/decoder.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/src/decoder.c.obj: ../src/decoder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/test.dir/__/src/decoder.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\src\decoder.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\src\decoder.c

test/CMakeFiles/test.dir/__/src/decoder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/src/decoder.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\src\decoder.c > CMakeFiles\test.dir\__\src\decoder.c.i

test/CMakeFiles/test.dir/__/src/decoder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/src/decoder.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\src\decoder.c -o CMakeFiles\test.dir\__\src\decoder.c.s

test/CMakeFiles/test.dir/__/src/executer.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/src/executer.c.obj: ../src/executer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test/CMakeFiles/test.dir/__/src/executer.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\src\executer.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\src\executer.c

test/CMakeFiles/test.dir/__/src/executer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/src/executer.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\src\executer.c > CMakeFiles\test.dir\__\src\executer.c.i

test/CMakeFiles/test.dir/__/src/executer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/src/executer.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\src\executer.c -o CMakeFiles\test.dir\__\src\executer.c.s

test/CMakeFiles/test.dir/__/src/interface.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/src/interface.c.obj: ../src/interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object test/CMakeFiles/test.dir/__/src/interface.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\src\interface.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\src\interface.c

test/CMakeFiles/test.dir/__/src/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/src/interface.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\src\interface.c > CMakeFiles\test.dir\__\src\interface.c.i

test/CMakeFiles/test.dir/__/src/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/src/interface.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\src\interface.c -o CMakeFiles\test.dir\__\src\interface.c.s

test/CMakeFiles/test.dir/__/src/memory.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/src/memory.c.obj: ../src/memory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object test/CMakeFiles/test.dir/__/src/memory.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\src\memory.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\src\memory.c

test/CMakeFiles/test.dir/__/src/memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/src/memory.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\src\memory.c > CMakeFiles\test.dir\__\src\memory.c.i

test/CMakeFiles/test.dir/__/src/memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/src/memory.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\src\memory.c -o CMakeFiles\test.dir\__\src\memory.c.s

test/CMakeFiles/test.dir/main_test.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/main_test.c.obj: ../test/main_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object test/CMakeFiles/test.dir/main_test.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\main_test.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\main_test.c

test/CMakeFiles/test.dir/main_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/main_test.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\main_test.c > CMakeFiles\test.dir\main_test.c.i

test/CMakeFiles/test.dir/main_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/main_test.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\main_test.c -o CMakeFiles\test.dir\main_test.c.s

test/CMakeFiles/test.dir/memory_test.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/memory_test.c.obj: ../test/memory_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object test/CMakeFiles/test.dir/memory_test.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\memory_test.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\memory_test.c

test/CMakeFiles/test.dir/memory_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/memory_test.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\memory_test.c > CMakeFiles\test.dir\memory_test.c.i

test/CMakeFiles/test.dir/memory_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/memory_test.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\memory_test.c -o CMakeFiles\test.dir\memory_test.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/__/src/decoder.c.obj" \
"CMakeFiles/test.dir/__/src/executer.c.obj" \
"CMakeFiles/test.dir/__/src/interface.c.obj" \
"CMakeFiles/test.dir/__/src/memory.c.obj" \
"CMakeFiles/test.dir/main_test.c.obj" \
"CMakeFiles/test.dir/memory_test.c.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

test/test.exe: test/CMakeFiles/test.dir/__/src/decoder.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/src/executer.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/src/interface.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/src/memory.c.obj
test/test.exe: test/CMakeFiles/test.dir/main_test.c.obj
test/test.exe: test/CMakeFiles/test.dir/memory_test.c.obj
test/test.exe: test/CMakeFiles/test.dir/build.make
test/test.exe: test/unity/libunity.a
test/test.exe: test/CMakeFiles/test.dir/linklibs.rsp
test/test.exe: test/CMakeFiles/test.dir/objects1.rsp
test/test.exe: test/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable test.exe"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/test.dir/build: test/test.exe

.PHONY : test/CMakeFiles/test.dir/build

test/CMakeFiles/test.dir/clean:
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && $(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/test.dir/clean

test/CMakeFiles/test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\alexa\CLionProjects\RV32EM-simulator C:\Users\alexa\CLionProjects\RV32EM-simulator\test C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test\CMakeFiles\test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/test.dir/depend

