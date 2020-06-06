file(GLOB SOURCES ./*.c)

add_executable(simulateur ${SOURCES} decoder.c executer.c interface.c interface.h memory.c memory.h manager.c manager.h)
target_include_directories(simulateur PUBLIC ${CMAKE_CURRENT_LIST_DIR})
