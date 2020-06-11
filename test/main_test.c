//
// Created by rolla on 2020-05-26.
//

#include "unity/unity.h"
#include "../simulateur/RV32EM.h"
#include "memory_test.h"
#include "decoder_test.h"
#include "executer_test.h"
#include "manager_test.h"


void setUp(void)
{
}
void tearDown(void)
{
}

/**
 * Il faut terminer et arranger comment on passe la structure d'une fonction à une autre!
 */
/*void test_decoder_instruction(){
    void* return_struct = 0;
    decoder_instruction(instruction_type_I, return_struct);

    TEST_ASSERT_EQUAL_HEX (expected_struct_J.opcode, return_struct.opcode);
}
 */
int main(void)
{
    UNITY_BEGIN();
    //RUN_TEST(test_decoder_instruction);
    RUN_TEST(run_test_all_type_I);
    RUN_TEST(run_test_all_type_S);
    RUN_TEST(run_test_all_type_J);
    RUN_TEST(run_test_all_type_U);
    RUN_TEST(loadProgramToMemory_should_return_non_zero_on_missing_file);
    RUN_TEST(loadProgramToMemory_should_copy_file_to_memory);
    RUN_TEST(loadProgramToMemory_should_initialize_userMemorySize_and_userMemory);
    return UNITY_END();
}




