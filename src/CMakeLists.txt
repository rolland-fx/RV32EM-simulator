file(GLOB SOURCES ./*.c)

add_executable(simulateur ${SOURCES} decoder.c executer.c interface.c memory.c memory.h)
target_include_directories(simulateur PUBLIC ${CMAKE_CURRENT_LIST_DIR})
