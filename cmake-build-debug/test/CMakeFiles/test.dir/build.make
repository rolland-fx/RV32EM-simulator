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

test/CMakeFiles/test.dir/__/simulateur/src/decoder.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/decoder.c.obj: ../simulateur/src/decoder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/decoder.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\decoder.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\decoder.c

test/CMakeFiles/test.dir/__/simulateur/src/decoder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/decoder.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\decoder.c > CMakeFiles\test.dir\__\simulateur\src\decoder.c.i

test/CMakeFiles/test.dir/__/simulateur/src/decoder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/decoder.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\decoder.c -o CMakeFiles\test.dir\__\simulateur\src\decoder.c.s

test/CMakeFiles/test.dir/__/simulateur/src/executer.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/executer.c.obj: ../simulateur/src/executer.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/executer.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\executer.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer.c

test/CMakeFiles/test.dir/__/simulateur/src/executer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/executer.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer.c > CMakeFiles\test.dir\__\simulateur\src\executer.c.i

test/CMakeFiles/test.dir/__/simulateur/src/executer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/executer.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer.c -o CMakeFiles\test.dir\__\simulateur\src\executer.c.s

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.obj: ../simulateur/src/executer/executer_B.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_B.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_B.c

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_B.c > CMakeFiles\test.dir\__\simulateur\src\executer\executer_B.c.i

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_B.c -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_B.c.s

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.obj: ../simulateur/src/executer/executer_I.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_I.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_I.c

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_I.c > CMakeFiles\test.dir\__\simulateur\src\executer\executer_I.c.i

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_I.c -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_I.c.s

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.obj: ../simulateur/src/executer/executer_J.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_J.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_J.c

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_J.c > CMakeFiles\test.dir\__\simulateur\src\executer\executer_J.c.i

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_J.c -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_J.c.s

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.obj: ../simulateur/src/executer/executer_R.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_R.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_R.c

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_R.c > CMakeFiles\test.dir\__\simulateur\src\executer\executer_R.c.i

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_R.c -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_R.c.s

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.obj: ../simulateur/src/executer/executer_S.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_S.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_S.c

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_S.c > CMakeFiles\test.dir\__\simulateur\src\executer\executer_S.c.i

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_S.c -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_S.c.s

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.obj: ../simulateur/src/executer/executer_U.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_U.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_U.c

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_U.c > CMakeFiles\test.dir\__\simulateur\src\executer\executer_U.c.i

test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\executer\executer_U.c -o CMakeFiles\test.dir\__\simulateur\src\executer\executer_U.c.s

test/CMakeFiles/test.dir/__/simulateur/src/interface.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/interface.c.obj: ../simulateur/src/interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/interface.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\interface.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\interface.c

test/CMakeFiles/test.dir/__/simulateur/src/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/interface.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\interface.c > CMakeFiles\test.dir\__\simulateur\src\interface.c.i

test/CMakeFiles/test.dir/__/simulateur/src/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/interface.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\interface.c -o CMakeFiles\test.dir\__\simulateur\src\interface.c.s

test/CMakeFiles/test.dir/__/simulateur/src/manager.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/manager.c.obj: ../simulateur/src/manager.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/manager.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\manager.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\manager.c

test/CMakeFiles/test.dir/__/simulateur/src/manager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/manager.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\manager.c > CMakeFiles\test.dir\__\simulateur\src\manager.c.i

test/CMakeFiles/test.dir/__/simulateur/src/manager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/manager.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\manager.c -o CMakeFiles\test.dir\__\simulateur\src\manager.c.s

test/CMakeFiles/test.dir/__/simulateur/src/memory.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/__/simulateur/src/memory.c.obj: ../simulateur/src/memory.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object test/CMakeFiles/test.dir/__/simulateur/src/memory.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\__\simulateur\src\memory.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\memory.c

test/CMakeFiles/test.dir/__/simulateur/src/memory.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/__/simulateur/src/memory.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\memory.c > CMakeFiles\test.dir\__\simulateur\src\memory.c.i

test/CMakeFiles/test.dir/__/simulateur/src/memory.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/__/simulateur/src/memory.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\simulateur\src\memory.c -o CMakeFiles\test.dir\__\simulateur\src\memory.c.s

test/CMakeFiles/test.dir/decoder_test.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/decoder_test.c.obj: ../test/decoder_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object test/CMakeFiles/test.dir/decoder_test.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\decoder_test.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\decoder_test.c

test/CMakeFiles/test.dir/decoder_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/decoder_test.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\decoder_test.c > CMakeFiles\test.dir\decoder_test.c.i

test/CMakeFiles/test.dir/decoder_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/decoder_test.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\decoder_test.c -o CMakeFiles\test.dir\decoder_test.c.s

test/CMakeFiles/test.dir/executer_test.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/executer_test.c.obj: ../test/executer_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object test/CMakeFiles/test.dir/executer_test.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\executer_test.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\executer_test.c

test/CMakeFiles/test.dir/executer_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/executer_test.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\executer_test.c > CMakeFiles\test.dir\executer_test.c.i

test/CMakeFiles/test.dir/executer_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/executer_test.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\executer_test.c -o CMakeFiles\test.dir\executer_test.c.s

test/CMakeFiles/test.dir/main_test.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/main_test.c.obj: ../test/main_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object test/CMakeFiles/test.dir/main_test.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\main_test.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\main_test.c

test/CMakeFiles/test.dir/main_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/main_test.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\main_test.c > CMakeFiles\test.dir\main_test.c.i

test/CMakeFiles/test.dir/main_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/main_test.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\main_test.c -o CMakeFiles\test.dir\main_test.c.s

test/CMakeFiles/test.dir/manager_test.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/manager_test.c.obj: ../test/manager_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object test/CMakeFiles/test.dir/manager_test.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\manager_test.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\manager_test.c

test/CMakeFiles/test.dir/manager_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/manager_test.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\manager_test.c > CMakeFiles\test.dir\manager_test.c.i

test/CMakeFiles/test.dir/manager_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/manager_test.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\manager_test.c -o CMakeFiles\test.dir\manager_test.c.s

test/CMakeFiles/test.dir/memory_test.c.obj: test/CMakeFiles/test.dir/flags.make
test/CMakeFiles/test.dir/memory_test.c.obj: ../test/memory_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object test/CMakeFiles/test.dir/memory_test.c.obj"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\memory_test.c.obj   -c C:\Users\alexa\CLionProjects\RV32EM-simulator\test\memory_test.c

test/CMakeFiles/test.dir/memory_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/memory_test.c.i"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\alexa\CLionProjects\RV32EM-simulator\test\memory_test.c > CMakeFiles\test.dir\memory_test.c.i

test/CMakeFiles/test.dir/memory_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/memory_test.c.s"
	cd /d C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\test && C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\alexa\CLionProjects\RV32EM-simulator\test\memory_test.c -o CMakeFiles\test.dir\memory_test.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/__/simulateur/src/decoder.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/executer.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/interface.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/manager.c.obj" \
"CMakeFiles/test.dir/__/simulateur/src/memory.c.obj" \
"CMakeFiles/test.dir/decoder_test.c.obj" \
"CMakeFiles/test.dir/executer_test.c.obj" \
"CMakeFiles/test.dir/main_test.c.obj" \
"CMakeFiles/test.dir/manager_test.c.obj" \
"CMakeFiles/test.dir/memory_test.c.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/decoder.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/executer.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_B.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_I.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_J.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_R.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_S.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/executer/executer_U.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/interface.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/manager.c.obj
test/test.exe: test/CMakeFiles/test.dir/__/simulateur/src/memory.c.obj
test/test.exe: test/CMakeFiles/test.dir/decoder_test.c.obj
test/test.exe: test/CMakeFiles/test.dir/executer_test.c.obj
test/test.exe: test/CMakeFiles/test.dir/main_test.c.obj
test/test.exe: test/CMakeFiles/test.dir/manager_test.c.obj
test/test.exe: test/CMakeFiles/test.dir/memory_test.c.obj
test/test.exe: test/CMakeFiles/test.dir/build.make
test/test.exe: test/unity/libunity.a
test/test.exe: test/CMakeFiles/test.dir/linklibs.rsp
test/test.exe: test/CMakeFiles/test.dir/objects1.rsp
test/test.exe: test/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\alexa\CLionProjects\RV32EM-simulator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking C executable test.exe"
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

