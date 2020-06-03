file(GLOB SOURCES ./*.c ../src/main.c)

add_subdirectory(unity)
add_executable(test ${SOURCES})
target_link_libraries(test unity)
