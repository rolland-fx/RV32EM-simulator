//
// Created by alexa on 2020-06-05.
//

#ifndef RV32EM_SIMULATOR_MEMORY_TEST_H
#define RV32EM_SIMULATOR_MEMORY_TEST_H

#include "unity/unity.h"
#include "../simulateur/src/memory.h"

void loadProgramToMemory_should_return_non_zero_on_missing_file();
void loadProgramToMemory_should_copy_file_to_memory();
void loadProgramToMemory_should_initialize_userMemorySize_and_userMemory();

#endif //RV32EM_SIMULATOR_MEMORY_TEST_H
