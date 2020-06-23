file(GLOB SOURCES ./main.c src/*.c src/execute/*.c)

add_executable(simulateur ${SOURCES} src/string_decode.c src/string_decode.h)
target_include_directories(simulateur PUBLIC ${CMAKE_CURRENT_LIST_DIR})
