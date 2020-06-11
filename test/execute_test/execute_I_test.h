//
// Created by alexa on 2020-06-11.
//

#ifndef RV32EM_SIMULATOR_EXECUTE_I_TEST_H
#define RV32EM_SIMULATOR_EXECUTE_I_TEST_H

#include "../../simulateur/src/execute/execute_I.h"

#include "../unity/unity.h"

/**
 * Run all test for instruction JALR
 */
void RUN_TEST_executer_type_I_JALR();

/**
 * Run all test for instruction ADDI
 */
void RUN_TEST_execute_type_I_ADDI();

/**
 * Run all test for instruction SLTI
 */
void RUN_TEST_execute_type_I_SLTI();

#endif //RV32EM_SIMULATOR_EXECUTE_I_TEST_H
