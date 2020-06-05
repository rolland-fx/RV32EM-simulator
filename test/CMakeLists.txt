file(GLOB SOURCES ./*.c ../src/decoder.c ../src/executer.c ../src/interface.c ../src/memory.c)

add_subdirectory(unity)
add_executable(test ${SOURCES} memory_test.c memory_test.h)
target_link_libraries(test unity)
