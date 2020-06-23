//
// Created by rolla on 2020-06-06.
//

#ifndef RV32EM_SIMULATOR_DECODER_TEST_H
#define RV32EM_SIMULATOR_DECODER_TEST_H

#include "unity/unity.h"
#include "../simulateur/RV32EM.h"


struct_I init_struct_I();
struct_S init_struct_S();
struct_J init_struct_J();
struct_U init_struct_U_1();
struct_U init_struct_U_2();
void test_decoder_type_I_opcode();
void test_decoder_type_I_rd();
void test_decoder_type_I_func3();
void test_decoder_type_I_rs1();
void test_decoder_type_I_imm_11_0();
void run_test_all_type_I();
void test_decoder_type_S_opcode();
void test_decoder_type_S_imm_4_0();
void test_decoder_type_S_func3();
void test_decoder_type_S_rs1();
void test_decoder_type_S_rs2();
void test_decoder_type_S_imm_11_5();
void run_test_all_type_S();
void test_decoder_type_J_opcode();
void test_decoder_type_J_rd();
void test_decoder_type_J_imm_19_12();
void test_decoder_type_J_imm_11();
void test_decoder_type_J_imm_10_1();
void test_decoder_type_J_imm_20();
void run_test_all_type_J();
void test_decoder_type_U_17();
void test_decoder_type_U_37();
void run_test_all_type_U();
void run_test_all_type_R();


#endif //RV32EM_SIMULATOR_DECODER_TEST_H
