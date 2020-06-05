//
// Created by alexa on 2020-06-05.
//

#include "memory_test.h"

void loadProgramToMemory_should_return_non_zero_on_missing_file()
{
    TEST_ASSERT_NOT_EQUAL (0, loadProgramToMemory("wrong_file_name.txt"));
}

void loadProgramToMemory_should_copy_file_to_memory(){
    uint32_t expectedresult[42] = {0x10000517, 0x00052503, 0x01c000ef, 0x00050593, 0x10000517, 0xff052503, 0x04c000ef,
                                 0x00a00793, 0x00000073, 0xff010113, 0x00112423, 0x00a12023, 0xfff50293, 0x0002d863,
                                 0x00100513, 0x01010113, 0x00008067, 0xfff50513, 0xfddff0ef, 0x00050313, 0x00012503,
                                 0x00812083, 0x01010113, 0x02650533, 0x00008067, 0x00050293, 0x00058313, 0x10000517,
                                 0xf9850513, 0x00400793, 0x00000073, 0x00028513, 0x00100793, 0x00000073, 0x10000517,
                                 0xf9050513, 0x00400793, 0x00000073, 0x00030513, 0x00100793, 0x00000073, 0x00008067};

    TEST_ASSERT_EQUAL_UINT8 (0, loadProgramToMemory("riscv_test.txt"));
    TEST_ASSERT_EQUAL_INT32_ARRAY (expectedresult, Memory, 42);
    TEST_ASSERT_EQUAL_UINT32 (MEMORY_SIZE - 42, userMemorySize);
    TEST_ASSERT_EQUAL_UINT32 (Memory + 42, userMemory);

};

void loadProgramToMemory_should_initialize_userMemorySize_and_userMemory()
{
    TEST_ASSERT_EQUAL_UINT8 (0, loadProgramToMemory("riscv_test.txt"));
    TEST_ASSERT_EQUAL_UINT32 (MEMORY_SIZE - 42, userMemorySize);
    TEST_ASSERT_EQUAL_UINT32 (Memory + 42, userMemory);
}
