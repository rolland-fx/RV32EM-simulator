file(GLOB SOURCES ./*.c execute_test/*.c ../simulateur/src/*.c ../simulateur/src/execute/*.c)

add_subdirectory(unity)
add_executable(test ${SOURCES})
target_link_libraries(test unity)
set(CMAKE_C_FLAGS "--coverage")