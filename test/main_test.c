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


void setUp(void){
}
void tearDown(void){
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST_loadProgramToMemory();
    RUN_TEST(run_test_all_type_I);
    RUN_TEST(run_test_all_type_S);
    RUN_TEST(run_test_all_type_J);
    RUN_TEST(run_test_all_type_U);

    RUN_TEST_execute_type_B();
    RUN_TEST_execute_type_I();
    RUN_TEST_executer_type_J();
    RUN_TEST_execute_type_I();
    RUN_TEST_execute_R();
    RUN_TEST_execute_type_S();
    RUN_TEST_execute_type_U();

    return UNITY_END();
}




