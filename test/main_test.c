//
// Created by rolla on 2020-05-26.
//

#include "unity/unity.h"
#include "../src/RV32EM.h"

void setUp(void)
{
}
void tearDown(void)
{
}
/*
void test_strlen_should_copy(void)
{
    TEST_ASSERT_TRUE(1);

}
void test_hexstr_16_bits_number_should_convert_ok(void)
{
    char number[16];
    TEST_ASSERT_EQUAL_STRING("4D20",hexstr(1234,number,16));
}
void test_hexstr_32_bits_number_should_convert_ok(void)
{
    char number[32];
    TEST_ASSERT_EQUAL_STRING("00004D20",hexstr(1234,number,32));
}
void test_hexstr_8_bits_number_should_convert_ok(void)
{
    char number[8];
    TEST_ASSERT_EQUAL_STRING("E0",hexstr(14,number,8));
}
void test_strreverse_should_reverse(void){
    char string[] = "Hello World!";
    TEST_ASSERT_EQUAL_STRING("!dlroW olleH", strreverse(string));
}
*/
/*
void test_strcpy_should_copy() {

    char copy_of_string_to_test[100];
    char string_to_test[] = "Test";
    char string_expected[] = "Test";

    TEST_ASSERT_EQUAL_STRING(string_expected,strcpy(copy_of_string_to_test,string_to_test));
}
void test_strlen_should_return_same_length()
{
    size_t length_expected = 4;
    char string_to_test[] = "test";
    TEST_ASSERT_EQUAL_size_t(length_expected,strlen(string_to_test));
}
*/

/**
 * Change the value here to test different instruction.
 */
uint32_t instruction_type_I = 0x00052503;
uint32_t instruction_type_S = 0x00a12023;
uint32_t instruction_type_J = 0xfddff0ef;
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
void run_test_all_type_J(){
    RUN_TEST(test_decoder_type_J_opcode);
    RUN_TEST(test_decoder_type_J_rd);
    RUN_TEST(test_decoder_type_J_imm_19_12);
    RUN_TEST(test_decoder_type_J_imm_11);
    RUN_TEST(test_decoder_type_J_imm_10_1);
    RUN_TEST(test_decoder_type_J_imm_20);
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
    RUN_TEST(test_decoder_instruction);
    return UNITY_END();
}




