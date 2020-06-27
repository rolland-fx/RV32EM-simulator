//
// Created by rolla on 2020-06-27.
//

#include "execute_S_test.h"

/*******************************************************************************
 * Test pour l'instruction SB
 ******************************************************************************/

void execute_type_S_SB_should_return_non_zero_on_rs1_greater_than_15(){
    struct_S Struct_S;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_8bits;
    Struct_S.rs1 = 16;
    Struct_S.rs2 = 1;
    Struct_S.imm_4_0 = 0;
    Struct_S.imm_11_5 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_S(&Struct_S));
}

void execute_type_S_SB_should_return_non_zero_on_rs2_greater_than_15(){
    struct_S Struct_S;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_8bits;
    Struct_S.rs1 = 1;
    Struct_S.rs2 = 16;
    Struct_S.imm_4_0 = 0;
    Struct_S.imm_11_5 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_S(&Struct_S));
}

void execute_type_S_SB_should_add_4_to_PC(){
    struct_S Struct_S;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rs2 = 2;
    int32_t rs1_value = 25;
    int32_t rs2_value = 25;
    int16_t imm_4_0 = 0;
    uint8_t imm_11_5 = 0;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_8bits;
    Struct_S.rs1 = rs1;
    Struct_S.rs2 = rs2;
    Struct_S.imm_4_0 = imm_4_0;
    Struct_S.imm_11_5 = imm_11_5;


    TEST_ASSERT_EQUAL_UINT8(0, execute_type_S(&Struct_S));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void execute_type_S_SB_should_store_rs2_value_at_rs1_plus_offset_address(){
    struct_S Struct_S;

    uint8_t rs1 = 5;
    uint8_t rs2 = 2;
    int32_t rs1_value = 100;
    int32_t rs2_value = 16;
    int16_t imm_4_0 = 0;
    uint8_t imm_11_5 = 0;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;


    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_8bits;
    Struct_S.rs1 = rs1;
    Struct_S.rs2 = rs2;
    Struct_S.imm_4_0 = imm_4_0;
    Struct_S.imm_11_5 = imm_11_5;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_S(&Struct_S));
    TEST_ASSERT_EQUAL_UINT8(16,user_memory_get_byte(rs1_value));
}

/*******************************************************************************
 * Test pour l'instruction SH
 ******************************************************************************/

void execute_type_S_SH_should_return_non_zero_on_rs1_greater_than_15(){
    struct_S Struct_S;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_16bits;
    Struct_S.rs1 = 16;
    Struct_S.rs2 = 1;
    Struct_S.imm_4_0 = 0;
    Struct_S.imm_11_5 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_S(&Struct_S));
}

void execute_type_S_SH_should_return_non_zero_on_rs2_greater_than_15(){
    struct_S Struct_S;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_16bits;
    Struct_S.rs1 = 1;
    Struct_S.rs2 = 16;
    Struct_S.imm_4_0 = 0;
    Struct_S.imm_11_5 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_S(&Struct_S));
}

void execute_type_S_SH_should_add_4_to_PC(){
    struct_S Struct_S;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rs2 = 2;
    int32_t rs1_value = 25;
    int32_t rs2_value = 25;
    int16_t imm_4_0 = 0;
    uint8_t imm_11_5 = 0;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_16bits;
    Struct_S.rs1 = rs1;
    Struct_S.rs2 = rs2;
    Struct_S.imm_4_0 = imm_4_0;
    Struct_S.imm_11_5 = imm_11_5;


    TEST_ASSERT_EQUAL_UINT8(0, execute_type_S(&Struct_S));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void execute_type_S_SH_should_store_rs2_value_at_rs1_plus_offset_address(){
    struct_S Struct_S;

    uint8_t rs1 = 5;
    uint8_t rs2 = 2;
    int32_t rs1_value = 100;
    int32_t rs2_value = 300;
    int16_t imm_4_0 = 0;
    uint8_t imm_11_5 = 0;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;


    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_16bits;
    Struct_S.rs1 = rs1;
    Struct_S.rs2 = rs2;
    Struct_S.imm_4_0 = imm_4_0;
    Struct_S.imm_11_5 = imm_11_5;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_S(&Struct_S));
    TEST_ASSERT_EQUAL_UINT16(300,user_memory_get_half_word(rs1_value));
}

/*******************************************************************************
 * Test pour l'instruction SW
 ******************************************************************************/

void execute_type_S_SW_should_return_non_zero_on_rs1_greater_than_15(){
    struct_S Struct_S;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_32bits;
    Struct_S.rs1 = 16;
    Struct_S.rs2 = 1;
    Struct_S.imm_4_0 = 0;
    Struct_S.imm_11_5 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_S(&Struct_S));
}

void execute_type_S_SW_should_return_non_zero_on_rs2_greater_than_15(){
    struct_S Struct_S;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_32bits;
    Struct_S.rs1 = 1;
    Struct_S.rs2 = 16;
    Struct_S.imm_4_0 = 0;
    Struct_S.imm_11_5 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_S(&Struct_S));
}

void execute_type_S_SW_should_add_4_to_PC(){
    struct_S Struct_S;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rs2 = 2;
    int32_t rs1_value = 25;
    int32_t rs2_value = 25;
    int16_t imm_4_0 = 0;
    uint8_t imm_11_5 = 0;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_32bits;
    Struct_S.rs1 = rs1;
    Struct_S.rs2 = rs2;
    Struct_S.imm_4_0 = imm_4_0;
    Struct_S.imm_11_5 = imm_11_5;


    TEST_ASSERT_EQUAL_UINT8(0, execute_type_S(&Struct_S));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void execute_type_S_SW_should_store_rs2_value_at_rs1_plus_offset_address(){
    struct_S Struct_S;

    uint8_t rs1 = 5;
    uint8_t rs2 = 2;
    int32_t rs1_value = 100;
    int32_t rs2_value = 34000;
    int16_t imm_4_0 = 0;
    uint8_t imm_11_5 = 0;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;


    Struct_S.opcode = 0x23;
    Struct_S.func3 = STORE_32bits;
    Struct_S.rs1 = rs1;
    Struct_S.rs2 = rs2;
    Struct_S.imm_4_0 = imm_4_0;
    Struct_S.imm_11_5 = imm_11_5;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_S(&Struct_S));
    TEST_ASSERT_EQUAL_UINT32(34000,user_memory_get_word(rs1_value));
}


void RUN_TEST_execute_type_S_SB(){
    RUN_TEST(execute_type_S_SB_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_S_SB_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_S_SB_should_add_4_to_PC);
    RUN_TEST(execute_type_S_SB_should_store_rs2_value_at_rs1_plus_offset_address);
}

void RUN_TEST_execute_type_S_SH(){
    RUN_TEST(execute_type_S_SH_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_S_SH_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_S_SH_should_add_4_to_PC);
    RUN_TEST(execute_type_S_SH_should_store_rs2_value_at_rs1_plus_offset_address);
}

void RUN_TEST_execute_type_S_SW(){
    RUN_TEST(execute_type_S_SW_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_S_SW_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_S_SW_should_add_4_to_PC);
    RUN_TEST(execute_type_S_SW_should_store_rs2_value_at_rs1_plus_offset_address);
}

void RUN_TEST_execute_type_S() {
    RUN_TEST_execute_type_S_SB(); // marche pas avec le usermemory
    RUN_TEST_execute_type_S_SH(); // marche pas avec le usermemory
    RUN_TEST_execute_type_S_SW(); // marche pas avec le usermemory
}