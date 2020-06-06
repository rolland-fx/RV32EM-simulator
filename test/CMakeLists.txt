file(GLOB SOURCES ./*.c ../src/decoder.c ../src/executer.c ../src/interface.c ../src/memory.c /src/manager.c)

add_subdirectory(unity)
add_executable(test ${SOURCES} memory_test.c memory_test.h decoder_test.c decoder_test.h executer_test.c executer_test.h manager_test.c manager_test.h)
target_link_libraries(test unity)
