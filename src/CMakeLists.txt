file(GLOB SOURCES ./*.c)

add_executable(simulateur ${SOURCES} decoder.c executer.c interface.c)
target_include_directories(simulateur PUBLIC ${CMAKE_CURRENT_LIST_DIR})
