//
// Created by rolla on 2020-06-06.
//

#include "decoder_test.h"


/**
 * Change the value here to test different instruction.
 */
uint32_t instruction_type_I   = 0x00052503;
uint32_t instruction_type_S   = 0x00a12023;
uint32_t instruction_type_J   = 0xfddff0ef;
uint32_t instruction_type_U_1 = 0x00001097;
uint32_t instruction_type_U_2 = 0x000010b7;
uint32_t instruction_type_R   = 0x023170B3;
uint32_t instruction_type_B   = 0x0E3105E3;
/**
 * Change the value here to test different instruction.
 * Instruction are decoded manually here to provide a comparaison for the function to test.
 */
struct_I init_struct_I(){

    struct_I expected_struct_I;
    expected_struct_I.opcode      = 0x03;
    expected_struct_I.rd          = 0x0a;
    expected_struct_I.func3       = 0x02;
    expected_struct_I.rs1         = 0x0a;
    expected_struct_I.imm_11_0    = 0x0000;

    return expected_struct_I;
}
struct_S init_struct_S(){

    struct_S expected_struct_S;
    expected_struct_S.opcode    = 0x23;
    expected_struct_S.imm_4_0   = 0x00;
    expected_struct_S.func3     = 0x02;
    expected_struct_S.rs1       = 0x02;
    expected_struct_S.rs2       = 0x0a;
    expected_struct_S.imm_11_5  = 0x00;

    return expected_struct_S;
}
struct_J init_struct_J(){

    struct_J expected_struct_J;
    expected_struct_J.opcode    = 0x6F;
    expected_struct_J.rd        = 0x01;
    expected_struct_J.imm_19_12 = 0xFF;
    expected_struct_J.imm_11    = 0x01;
    expected_struct_J.imm_10_1  = 0x03EE;
    expected_struct_J.imm_20    = 0x01;

    return expected_struct_J;
}
struct_U init_struct_U_1(){

    struct_U expected_struct_U;
    expected_struct_U.opcode    = 0x17;
    expected_struct_U.rd        = 0x01;
    expected_struct_U.imm       = 0x01;

    return expected_struct_U;
}

struct_U init_struct_U_2(){

    struct_U expected_struct_U;
    expected_struct_U.opcode    = 0x37;
    expected_struct_U.rd        = 0x01;
    expected_struct_U.imm       = 0x01;

    return expected_struct_U;
}
struct_R init_struct_R(){

    struct_R expected_struct_R;
    expected_struct_R.opcode      = 0x33;
    expected_struct_R.rd          = 0x01;
    expected_struct_R.func3       = 0x07;
    expected_struct_R.rs1         = 0x02;
    expected_struct_R.rs2         = 0x03;
    expected_struct_R.funct7      = 0x01;

    return expected_struct_R;
}
struct_B init_struct_B(){

    struct_B expected_struct_B;
    expected_struct_B.opcode      = 0x63;
    expected_struct_B.imm_11      = 0x01;
    expected_struct_B.imm_4_1     = 0x05;
    expected_struct_B.func3       = 0x00;
    expected_struct_B.rs1         = 0x02;
    expected_struct_B.rs2         = 0x03;
    expected_struct_B.imm_10_5    = 0x07;
    expected_struct_B.imm_12      = 0x00;

    return expected_struct_B;
}

/**
 * Following tests are for testing the decoding of Instruction of Type 'I'.
 */
void test_decoder_type_I_opcode()
{
    struct_I actual_struct_I;
    struct_I expected_struct_I = init_struct_I();
    decoder_type_I(instruction_type_I,&actual_struct_I);

    TEST_ASSERT_EQUAL_HEX (expected_struct_I.opcode, actual_struct_I.opcode);
}
void test_decoder_type_I_rd()
{
    struct_I actual_struct_I;
    struct_I expected_struct_I = init_struct_I();
    decoder_type_I(instruction_type_I,&actual_struct_I);

    TEST_ASSERT_EQUAL_HEX (expected_struct_I.rd, actual_struct_I.rd);
}
void test_decoder_type_I_func3()
{
    struct_I actual_struct_I;
    struct_I expected_struct_I = init_struct_I();
    decoder_type_I(instruction_type_I,&actual_struct_I);

    TEST_ASSERT_EQUAL_HEX (expected_struct_I.func3, actual_struct_I.func3);
}
void test_decoder_type_I_rs1()
{
    struct_I actual_struct_I;
    struct_I expected_struct_I = init_struct_I();
    decoder_type_I(instruction_type_I,&actual_struct_I);

    TEST_ASSERT_EQUAL_HEX (expected_struct_I.rs1, actual_struct_I.rs1);
}
void test_decoder_type_I_imm_11_0()
{
    struct_I actual_struct_I;
    struct_I expected_struct_I = init_struct_I();
    decoder_type_I(instruction_type_I,&actual_struct_I);

    TEST_ASSERT_EQUAL_HEX (expected_struct_I.imm_11_0, actual_struct_I.imm_11_0);
}
void run_test_all_type_I(){
    RUN_TEST(test_decoder_type_I_opcode);
    RUN_TEST(test_decoder_type_I_rd);
    RUN_TEST(test_decoder_type_I_func3);
    RUN_TEST(test_decoder_type_I_rs1);
    RUN_TEST(test_decoder_type_I_imm_11_0);
}
/**
 * Following tests are for testing the decoding of Instruction of Type 'S'.
 */
void test_decoder_type_S_opcode()
{
    struct_S actual_struct_S;
    struct_S expected_struct_S = init_struct_S();
    decoder_type_S(instruction_type_S,&actual_struct_S);

    TEST_ASSERT_EQUAL_HEX (expected_struct_S.opcode, actual_struct_S.opcode);
}
void test_decoder_type_S_imm_4_0()
{
    struct_S actual_struct_S;
    struct_S expected_struct_S = init_struct_S();
    decoder_type_S(instruction_type_S,&actual_struct_S);

    TEST_ASSERT_EQUAL_HEX (expected_struct_S.imm_4_0, actual_struct_S.imm_4_0);
}
void test_decoder_type_S_func3()
{
    struct_S actual_struct_S;
    struct_S expected_struct_S = init_struct_S();
    decoder_type_S(instruction_type_S,&actual_struct_S);

    TEST_ASSERT_EQUAL_HEX (expected_struct_S.func3, actual_struct_S.func3);
}
void test_decoder_type_S_rs1()
{
    struct_S actual_struct_S;
    struct_S expected_struct_S = init_struct_S();
    decoder_type_S(instruction_type_S,&actual_struct_S);

    TEST_ASSERT_EQUAL_HEX (expected_struct_S.rs1, actual_struct_S.rs1);
}
void test_decoder_type_S_rs2()
{
    struct_S actual_struct_S;
    struct_S expected_struct_S = init_struct_S();
    decoder_type_S(instruction_type_S,&actual_struct_S);

    TEST_ASSERT_EQUAL_HEX (expected_struct_S.rs2, actual_struct_S.rs2);
}
void test_decoder_type_S_imm_11_5()
{
    struct_S actual_struct_S;
    struct_S expected_struct_S = init_struct_S();
    decoder_type_S(instruction_type_S,&actual_struct_S);

    TEST_ASSERT_EQUAL_HEX (expected_struct_S.imm_11_5, actual_struct_S.imm_11_5);
}
void run_test_all_type_S(){
    RUN_TEST(test_decoder_type_S_opcode);
    RUN_TEST(test_decoder_type_S_imm_4_0);
    RUN_TEST(test_decoder_type_S_func3);
    RUN_TEST(test_decoder_type_S_rs1);
    RUN_TEST(test_decoder_type_S_rs2);
    RUN_TEST(test_decoder_type_S_imm_11_5);
}
/**
 * Following tests are for testing the decoding of Instruction of Type 'J'.
 */
void test_decoder_type_J_opcode()
{
    struct_J actual_struct_J;
    struct_J expected_struct_J = init_struct_J();
    decoder_type_J(instruction_type_J,&actual_struct_J);

    TEST_ASSERT_EQUAL_HEX (expected_struct_J.opcode, actual_struct_J.opcode);
}
void test_decoder_type_J_rd()
{
    struct_J actual_struct_J;
    struct_J expected_struct_J = init_struct_J();
    decoder_type_J(instruction_type_J,&actual_struct_J);

    TEST_ASSERT_EQUAL_HEX (expected_struct_J.rd, actual_struct_J.rd);
}
void test_decoder_type_J_imm_19_12()
{
    struct_J actual_struct_J;
    struct_J expected_struct_J = init_struct_J();
    decoder_type_J(instruction_type_J,&actual_struct_J);

    TEST_ASSERT_EQUAL_HEX (expected_struct_J.imm_19_12, actual_struct_J.imm_19_12);
}
void test_decoder_type_J_imm_11()
{
    struct_J actual_struct_J;
    struct_J expected_struct_J = init_struct_J();
    decoder_type_J(instruction_type_J,&actual_struct_J);

    TEST_ASSERT_EQUAL_HEX (expected_struct_J.imm_11, actual_struct_J.imm_11);
}
void test_decoder_type_J_imm_10_1()
{
    struct_J actual_struct_J;
    struct_J expected_struct_J = init_struct_J();
    decoder_type_J(instruction_type_J,&actual_struct_J);

    TEST_ASSERT_EQUAL_HEX (expected_struct_J.imm_10_1, actual_struct_J.imm_10_1);
}
void test_decoder_type_J_imm_20()
{
    struct_J actual_struct_J;
    struct_J expected_struct_J = init_struct_J();
    decoder_type_J(instruction_type_J,&actual_struct_J);

    TEST_ASSERT_EQUAL_HEX (expected_struct_J.imm_20, actual_struct_J.imm_20);
}
void test_decoder_type_U_17()
{
    struct_U actual_struct_U;
    struct_U expected_struct_U = init_struct_U_1();
    decoder_type_U(instruction_type_U_1,&actual_struct_U);
    TEST_ASSERT_EQUAL_HEX (expected_struct_U.opcode, actual_struct_U.opcode);
    TEST_ASSERT_EQUAL_HEX (expected_struct_U.rd, actual_struct_U.rd);
    TEST_ASSERT_EQUAL_HEX (expected_struct_U.imm, actual_struct_U.imm);

}
void test_decoder_type_U_37()
{
    struct_U actual_struct_U;
    struct_U expected_struct_U = init_struct_U_2();
    decoder_type_U(instruction_type_U_2,&actual_struct_U);
    TEST_ASSERT_EQUAL_HEX (expected_struct_U.opcode, actual_struct_U.opcode);
    TEST_ASSERT_EQUAL_HEX (expected_struct_U.rd, actual_struct_U.rd);
    TEST_ASSERT_EQUAL_HEX (expected_struct_U.imm, actual_struct_U.imm);

}

void run_test_all_type_J(){
    RUN_TEST(test_decoder_type_J_opcode);
    RUN_TEST(test_decoder_type_J_rd);
    RUN_TEST(test_decoder_type_J_imm_19_12);
    RUN_TEST(test_decoder_type_J_imm_11);
    RUN_TEST(test_decoder_type_J_imm_10_1);
    RUN_TEST(test_decoder_type_J_imm_20);
}
void run_test_all_type_U()
{
    RUN_TEST(test_decoder_type_U_17);
    RUN_TEST(test_decoder_type_U_37);
}

/**
 * Following tests are for testing the decoding of Instruction of Type 'R'.
 */
void test_decoder_type_R_opcode()
{
    struct_R actual_struct_R;
    struct_R expected_struct_R = init_struct_R();
    decoder_type_R(instruction_type_R,&actual_struct_R);

    TEST_ASSERT_EQUAL_HEX (expected_struct_R.opcode, actual_struct_R.opcode);
}
void test_decoder_type_R_rd()
{
    struct_R actual_struct_R;
    struct_R expected_struct_R = init_struct_R();
    decoder_type_R(instruction_type_R,&actual_struct_R);

    TEST_ASSERT_EQUAL_HEX (expected_struct_R.rd, actual_struct_R.rd);
}
void test_decoder_type_R_func3()
{
    struct_R actual_struct_R;
    struct_R expected_struct_R = init_struct_R();
    decoder_type_R(instruction_type_R,&actual_struct_R);

    TEST_ASSERT_EQUAL_HEX (expected_struct_R.func3, actual_struct_R.func3);
}
void test_decoder_type_R_rs1()
{
    struct_R actual_struct_R;
    struct_R expected_struct_R = init_struct_R();
    decoder_type_R(instruction_type_R,&actual_struct_R);

    TEST_ASSERT_EQUAL_HEX (expected_struct_R.rs1, actual_struct_R.rs1);
}
void test_decoder_type_R_rs2()
{
    struct_R actual_struct_R;
    struct_R expected_struct_R = init_struct_R();
    decoder_type_R(instruction_type_R,&actual_struct_R);

    TEST_ASSERT_EQUAL_HEX (expected_struct_R.rs2, actual_struct_R.rs2);
}
void test_decoder_type_R_func7()
{
    struct_R actual_struct_R;
    struct_R expected_struct_R = init_struct_R();
    decoder_type_R(instruction_type_R,&actual_struct_R);

    TEST_ASSERT_EQUAL_HEX (expected_struct_R.funct7, actual_struct_R.funct7);
}
void run_test_all_type_R(){
    RUN_TEST(test_decoder_type_R_opcode);
    RUN_TEST(test_decoder_type_R_rd);
    RUN_TEST(test_decoder_type_R_func3);
    RUN_TEST(test_decoder_type_R_rs1);
    RUN_TEST(test_decoder_type_R_rs2);
    RUN_TEST(test_decoder_type_R_func7);
}

/**
 * Following tests are for testing the decoding of Instruction of Type 'B'.
 */
void test_decoder_type_B_opcode()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.opcode, actual_struct_B.opcode);
}
void test_decoder_type_B_imm_11()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.imm_11, actual_struct_B.imm_11);
}
void test_decoder_type_B_imm_4_1()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.imm_4_1, actual_struct_B.imm_4_1);
}
void test_decoder_type_B_func3()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.func3, actual_struct_B.func3);
}
void test_decoder_type_B_rs1()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.rs1, actual_struct_B.rs1);
}
void test_decoder_type_B_rs2()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.rs2, actual_struct_B.rs2);
}
void test_decoder_type_B_imm_10_5()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.imm_10_5, actual_struct_B.imm_10_5);
}
void test_decoder_type_B_imm_12()
{
    struct_B actual_struct_B;
    struct_B expected_struct_B = init_struct_B();
    decoder_type_B(instruction_type_B,&actual_struct_B);

    TEST_ASSERT_EQUAL_HEX (expected_struct_B.imm_12, actual_struct_B.imm_12);
}
void run_test_all_type_B(){
    RUN_TEST(test_decoder_type_B_opcode);
    RUN_TEST(test_decoder_type_B_imm_11);
    RUN_TEST(test_decoder_type_B_imm_4_1);
    RUN_TEST(test_decoder_type_B_func3);
    RUN_TEST(test_decoder_type_B_rs1);
    RUN_TEST(test_decoder_type_B_rs2);
    RUN_TEST(test_decoder_type_B_imm_10_5);
    RUN_TEST(test_decoder_type_B_imm_12);
}
