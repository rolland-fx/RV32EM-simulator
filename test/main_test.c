//
// Created by rolla on 2020-05-26.
//

#include "unity/unity.h"
#include "../simulateur/RV32EM.h"
#include "main_test.h"
#include "memory_test.h"
#include "decoder_test.h"
#include "execute_test.h"
#include "manager_test.h"
#include "execute_test.h"


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
    //RUN_TEST_loadProgramToMemory(); //Doit être exécuter pour pouvoir exé
    //RUN_TEST(test_decoder_instruction);
    //RUN_TEST(run_test_all_type_I);
    //RUN_TEST(run_test_all_type_S);
    //RUN_TEST(run_test_all_type_J);
    //RUN_TEST(run_test_all_type_U);

    //RUN_TEST_execute_type_B();
    //RUN_TEST_execute_type_I();
    //RUN_TEST_executer_type_J();
    //RUN_TEST_execute_type_I();
    RUN_TEST_execute_R();

    return UNITY_END();
}




