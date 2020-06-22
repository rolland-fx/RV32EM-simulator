//
// Created by jeanp on 2020-06-22.
//

#include "execute_B_test.h"

/*******************************************************************************
 * Test pour l'instruction BEQ
 ******************************************************************************/

void execute_type_B_BEQ_should_return_non_zero_on_rs1_greater_than_15(){
    struct_B Struct_B;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BEQ_FUNCT3;
    Struct_B.rs1 = 16;
    Struct_B.rs2 = 2;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_B(&Struct_B));
}

void execute_type_B_BEQ_should_return_non_zero_on_rs2_greater_than_15(){
    struct_B Struct_B;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BEQ_FUNCT3;
    Struct_B.rs1 = 2;
    Struct_B.rs2 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_B(&Struct_B));
}

void execute_type_B_BEQ_PC_equal_PC_plus_offset_if_src1_equal_src_2(){
    struct_B Struct_B;

    uint8_t rs1 = 6;
    uint8_t rs2 = 1;

    int32_t rs1_value = 12;
    int32_t rs2_value = 12;
    int16_t imm = 200;
    uint32_t start_PC = 100;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BEQ_FUNCT3;
    Struct_B.rs1 = rs1;
    Struct_B.rs2 = rs2;
    Struct_B.imm_4_1 = 4;
    Struct_B.imm_10_5 = 6;
    Struct_B.imm_11 = 0;
    Struct_B.imm_12 = 0;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_B(&Struct_B));
    TEST_ASSERT_EQUAL_UINT32(start_PC + imm, PC);
}

void execute_type_B_BEQ_should_add_4_to_PC_if_src1_not_equal_src2(){
    struct_B Struct_B;

    uint8_t rs1 = 6;
    uint8_t rs2 = 1;

    int32_t rs1_value = 12;
    int32_t rs2_value = 11;
    int16_t imm = 200;
    uint32_t start_PC = 100;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BEQ_FUNCT3;
    Struct_B.rs1 = rs1;
    Struct_B.rs2 = rs2;
    Struct_B.imm_4_1 = 4;
    Struct_B.imm_10_5 = 6;
    Struct_B.imm_11 = 0;
    Struct_B.imm_12 = 0;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_B(&Struct_B));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_B_BEQ(){
    RUN_TEST(execute_type_B_BEQ_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_B_BEQ_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_B_BEQ_PC_equal_PC_plus_offset_if_src1_equal_src_2);
    RUN_TEST(execute_type_B_BEQ_should_add_4_to_PC_if_src1_not_equal_src2);
}

/*******************************************************************************
 * Test pour l'instruction BNE
 ******************************************************************************/

void execute_type_B_BNE_should_return_non_zero_on_rs1_greater_than_15(){
    struct_B Struct_B;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BNE_FUNCT3;
    Struct_B.rs1 = 16;
    Struct_B.rs2 = 2;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_B(&Struct_B));
}

void execute_type_B_BNE_should_return_non_zero_on_rs2_greater_than_15(){
    struct_B Struct_B;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BNE_FUNCT3;
    Struct_B.rs1 = 2;
    Struct_B.rs2 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_B(&Struct_B));
}

void execute_type_B_BNE_PC_equal_PC_plus_offset_if_src1_not_equal_src_2(){
    struct_B Struct_B;

    uint8_t rs1 = 6;
    uint8_t rs2 = 1;

    int32_t rs1_value = 12;
    int32_t rs2_value = 11;
    int16_t imm = 200;
    uint32_t start_PC = 100;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BNE_FUNCT3;
    Struct_B.rs1 = rs1;
    Struct_B.rs2 = rs2;
    Struct_B.imm_4_1 = 4;
    Struct_B.imm_10_5 = 6;
    Struct_B.imm_11 = 0;
    Struct_B.imm_12 = 0;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_B(&Struct_B));
    TEST_ASSERT_EQUAL_UINT32(start_PC + imm, PC);
}

void execute_type_B_BNE_should_add_4_to_PC_if_src1_equal_src2(){
    struct_B Struct_B;

    uint8_t rs1 = 6;
    uint8_t rs2 = 1;

    int32_t rs1_value = 12;
    int32_t rs2_value = 12;
    int16_t imm = 200;
    uint32_t start_PC = 100;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BNE_FUNCT3;
    Struct_B.rs1 = rs1;
    Struct_B.rs2 = rs2;
    Struct_B.imm_4_1 = 4;
    Struct_B.imm_10_5 = 6;
    Struct_B.imm_11 = 0;
    Struct_B.imm_12 = 0;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_B(&Struct_B));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_B_BNE(){
    RUN_TEST(execute_type_B_BNE_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_B_BNE_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_B_BNE_PC_equal_PC_plus_offset_if_src1_not_equal_src_2);
    RUN_TEST(execute_type_B_BNE_should_add_4_to_PC_if_src1_equal_src2);
}

/*******************************************************************************
 * Test pour l'instruction BNE
 ******************************************************************************/

void execute_type_B_BLT_should_return_non_zero_on_rs1_greater_than_15(){
    struct_B Struct_B;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BLT_FUNCT3;
    Struct_B.rs1 = 16;
    Struct_B.rs2 = 2;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_B(&Struct_B));
}

void execute_type_B_BLT_should_return_non_zero_on_rs2_greater_than_15(){
    struct_B Struct_B;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BLT_FUNCT3;
    Struct_B.rs1 = 2;
    Struct_B.rs2 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_B(&Struct_B));
}

void execute_type_B_BLT_PC_equal_PC_plus_offset_if_src1_less_than_src_2(){
    struct_B Struct_B;

    uint8_t rs1 = 6;
    uint8_t rs2 = 1;

    int32_t rs1_value = 6;
    int32_t rs2_value = 12;
    int16_t imm = 200;
    uint32_t start_PC = 100;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BLT_FUNCT3;
    Struct_B.rs1 = rs1;
    Struct_B.rs2 = rs2;
    Struct_B.imm_4_1 = 4;
    Struct_B.imm_10_5 = 6;
    Struct_B.imm_11 = 0;
    Struct_B.imm_12 = 0;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_B(&Struct_B));
    TEST_ASSERT_EQUAL_UINT32(start_PC + imm, PC);
}

void execute_type_B_BLT_should_add_4_to_PC_if_src1_greater_than_src2(){
    struct_B Struct_B;

    uint8_t rs1 = 6;
    uint8_t rs2 = 1;

    int32_t rs1_value = 12;
    int32_t rs2_value = 6;
    int16_t imm = 200;
    uint32_t start_PC = 100;

    Register[rs1] = rs1_value;
    Register[rs2] = rs2_value;

    PC = start_PC;

    Struct_B.opcode = BRANCH_OPCODE;
    Struct_B.func3 = BLT_FUNCT3;
    Struct_B.rs1 = rs1;
    Struct_B.rs2 = rs2;
    Struct_B.imm_4_1 = 4;
    Struct_B.imm_10_5 = 6;
    Struct_B.imm_11 = 0;
    Struct_B.imm_12 = 0;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_B(&Struct_B));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_B_BLT(){
    RUN_TEST(execute_type_B_BLT_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_B_BLT_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_B_BLT_PC_equal_PC_plus_offset_if_src1_less_than_src_2);
    RUN_TEST(execute_type_B_BLT_should_add_4_to_PC_if_src1_greater_than_src2);
}

void RUN_TEST_execute_type_B(){

    RUN_TEST_execute_type_B_BEQ();
    RUN_TEST_execute_type_B_BNE();
    RUN_TEST_execute_type_B_BLT();
}