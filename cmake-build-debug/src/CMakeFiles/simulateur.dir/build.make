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
CMAKE_SOURCE_DIR = C:\Users\rolla\CLionProjects\RV32EM-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/simulateur.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/simulateur.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/simulateur.dir/flags.make

src/CMakeFiles/simulateur.dir/decoder.c.obj: src/CMakeFiles/simulateur.dir/flags.make
src/CMakeFiles/simulateur.dir/decoder.c.obj: src/CMakeFiles/simulateur.dir/includes_C.rsp
src/CMakeFiles/simulateur.dir/decoder.c.obj: ../src/decoder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/simulateur.dir/decoder.c.obj"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simulateur.dir\decoder.c.obj   -c C:\Users\rolla\CLionProjects\RV32EM-simulator\src\decoder.c

src/CMakeFiles/simulateur.dir/decoder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simulateur.dir/decoder.c.i"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\rolla\CLionProjects\RV32EM-simulator\src\decoder.c > CMakeFiles\simulateur.dir\decoder.c.i

src/CMakeFiles/simulateur.dir/decoder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simulateur.dir/decoder.c.s"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\rolla\CLionProjects\RV32EM-simulator\src\decoder.c -o CMakeFiles\simulateur.dir\decoder.c.s

src/CMakeFiles/simulateur.dir/executer.c.obj: src/CMakeFiles/simulateur.dir/flags.make
src/CMakeFiles/simulateur.dir/executer.c.obj: src/CMakeFiles/simulateur.dir/includes_C.rsp
src/CMakeFiles/simulateur.dir/executer.c.obj: ../src/executer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/simulateur.dir/executer.c.obj"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simulateur.dir\executer.c.obj   -c C:\Users\rolla\CLionProjects\RV32EM-simulator\src\executer.c

src/CMakeFiles/simulateur.dir/executer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simulateur.dir/executer.c.i"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\rolla\CLionProjects\RV32EM-simulator\src\executer.c > CMakeFiles\simulateur.dir\executer.c.i

src/CMakeFiles/simulateur.dir/executer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simulateur.dir/executer.c.s"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\rolla\CLionProjects\RV32EM-simulator\src\executer.c -o CMakeFiles\simulateur.dir\executer.c.s

src/CMakeFiles/simulateur.dir/main.c.obj: src/CMakeFiles/simulateur.dir/flags.make
src/CMakeFiles/simulateur.dir/main.c.obj: src/CMakeFiles/simulateur.dir/includes_C.rsp
src/CMakeFiles/simulateur.dir/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/simulateur.dir/main.c.obj"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\simulateur.dir\main.c.obj   -c C:\Users\rolla\CLionProjects\RV32EM-simulator\src\main.c

src/CMakeFiles/simulateur.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/simulateur.dir/main.c.i"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\rolla\CLionProjects\RV32EM-simulator\src\main.c > CMakeFiles\simulateur.dir\main.c.i

src/CMakeFiles/simulateur.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/simulateur.dir/main.c.s"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\rolla\CLionProjects\RV32EM-simulator\src\main.c -o CMakeFiles\simulateur.dir\main.c.s

# Object files for target simulateur
simulateur_OBJECTS = \
"CMakeFiles/simulateur.dir/decoder.c.obj" \
"CMakeFiles/simulateur.dir/executer.c.obj" \
"CMakeFiles/simulateur.dir/main.c.obj"

# External object files for target simulateur
simulateur_EXTERNAL_OBJECTS =

src/simulateur.exe: src/CMakeFiles/simulateur.dir/decoder.c.obj
src/simulateur.exe: src/CMakeFiles/simulateur.dir/executer.c.obj
src/simulateur.exe: src/CMakeFiles/simulateur.dir/main.c.obj
src/simulateur.exe: src/CMakeFiles/simulateur.dir/build.make
src/simulateur.exe: src/CMakeFiles/simulateur.dir/linklibs.rsp
src/simulateur.exe: src/CMakeFiles/simulateur.dir/objects1.rsp
src/simulateur.exe: src/CMakeFiles/simulateur.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable simulateur.exe"
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\simulateur.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/simulateur.dir/build: src/simulateur.exe

.PHONY : src/CMakeFiles/simulateur.dir/build

src/CMakeFiles/simulateur.dir/clean:
	cd /d C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\simulateur.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/simulateur.dir/clean

src/CMakeFiles/simulateur.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\rolla\CLionProjects\RV32EM-simulator C:\Users\rolla\CLionProjects\RV32EM-simulator\src C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src C:\Users\rolla\CLionProjects\RV32EM-simulator\cmake-build-debug\src\CMakeFiles\simulateur.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/simulateur.dir/depend

