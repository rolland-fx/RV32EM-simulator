//
// Created by alexa on 2020-06-11.
//

#include "execute_I_test.h"

/*******************************************************************************
 * Test pour l'instruction JALR
 ******************************************************************************/

void excute_type_I_JALR_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.rd = 16;
    Struct_I.opcode = JALR_OPCODE;

    TEST_ASSERT_NOT_EQUAL (0, execute_type_I(&Struct_I));
}

void execute_type_I_JALR_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = JALR_OPCODE;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_JALR_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = JALR_OPCODE;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_JALR_should_add_imm_plus_rs1_to_PC(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint16_t imm = 200;
    uint32_t start_PC = 100;

    PC = start_PC;

    Register[rs1] = 4;

    Struct_I.rd = 0;
    Struct_I.opcode = JALR_OPCODE;

    Struct_I.imm_11_0 = imm;
    Struct_I.rs1 = rs1;


    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + imm + Register[rs1], PC);
}

void execute_type_I_JALR_should_place_PC_plus_4_in_rd(){
    struct_I Struct_I;
    uint32_t start_PC = 100;

    PC = start_PC;

    Struct_I.rd = 11;
    Struct_I.rs1 = 1;
    Struct_I.opcode = JALR_OPCODE;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, Register[Struct_I.rd]);
}

void RUN_TEST_executer_type_I_JALR(){
    RUN_TEST(excute_type_I_JALR_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_JALR_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_JALR_should_not_modify_x0);
    RUN_TEST(execute_type_I_JALR_should_add_imm_plus_rs1_to_PC);
    RUN_TEST(execute_type_I_JALR_should_place_PC_plus_4_in_rd);
}

/*******************************************************************************
 * Test pour l'instruction ADDI
 ******************************************************************************/

void execute_type_I_ADDI_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_ADDI_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_ADDI_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_ADDI_should_place_rs1_plus_imm_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 100;
    int16_t imm = -200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(rs1_value + imm, Register[rd]);
}

void execute_type_I_ADDI_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_ADDI(){
    RUN_TEST(execute_type_I_ADDI_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_ADDI_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_ADDI_should_not_modify_x0);
    RUN_TEST(execute_type_I_ADDI_should_place_rs1_plus_imm_in_rd);
    RUN_TEST(execute_type_I_ADDI_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SLTI
 ******************************************************************************/

void execute_type_I_SLTI_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SLTI_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SLTI_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_SLTI_should_place_1_in_rd_if_rs1_greater_than_imm(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 100;
    int16_t imm = -200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(1, Register[rd]);
}

void execute_type_I_SLTI_should_place_0_in_rd_if_rs1_smaller_than_imm(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = -200;
    int16_t imm = 100;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[rd]);
}

void execute_type_I_SLTI_should_place_0_in_rd_if_rs1_equal_to_imm(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = -200;
    int16_t imm = -200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[rd]);
}

void execute_type_I_SLTI_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_SLTI(){
    RUN_TEST(execute_type_I_SLTI_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_SLTI_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_SLTI_should_not_modify_x0);
    RUN_TEST(execute_type_I_SLTI_should_place_1_in_rd_if_rs1_greater_than_imm);
    RUN_TEST(execute_type_I_SLTI_should_place_0_in_rd_if_rs1_smaller_than_imm);
    RUN_TEST(execute_type_I_SLTI_should_place_0_in_rd_if_rs1_equal_to_imm);
    RUN_TEST(execute_type_I_SLTI_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction LB
 ******************************************************************************/

void execute_type_I_LB_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LB_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LB_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LB_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LB_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LB_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_LB_should_load_rs1_plus_offset_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LB_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT8(value, Register[rd]);
}

void execute_type_I_LB_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LB_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_LB(){
    RUN_TEST(execute_type_I_LB_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_LB_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_LB_should_not_modify_x0);
    RUN_TEST(execute_type_I_LB_should_load_rs1_plus_offset_in_rd);
    RUN_TEST(execute_type_I_LB_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction LH
 ******************************************************************************/

void execute_type_I_LH_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LH_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LH_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LH_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LH_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LH_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_LH_should_load_rs1_plus_offset_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LH_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT16(value, Register[rd]);
}

void execute_type_I_LH_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LH_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_LH(){
    RUN_TEST(execute_type_I_LH_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_LH_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_LH_should_not_modify_x0);
    RUN_TEST(execute_type_I_LH_should_load_rs1_plus_offset_in_rd);
    RUN_TEST(execute_type_I_LH_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction LW
 ******************************************************************************/

void execute_type_I_LW_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LW_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LW_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LW_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LW_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LW_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_LW_should_load_rs1_plus_offset_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LW_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(value, Register[rd]);
}

void execute_type_I_LW_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LW_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_LW(){
    RUN_TEST(execute_type_I_LW_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_LW_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_LW_should_not_modify_x0);
    RUN_TEST(execute_type_I_LW_should_load_rs1_plus_offset_in_rd);
    RUN_TEST(execute_type_I_LW_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction LBU
 ******************************************************************************/

void execute_type_I_LBU_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LBU_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LBU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LBU_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LBU_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LBU_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_LBU_should_load_rs1_plus_offset_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LBU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT8(value, Register[rd]);
}

void execute_type_I_LBU_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LBU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_LBU(){
    RUN_TEST(execute_type_I_LBU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_LBU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_LBU_should_not_modify_x0);
    RUN_TEST(execute_type_I_LBU_should_load_rs1_plus_offset_in_rd);
    RUN_TEST(execute_type_I_LBU_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction LHU
 ******************************************************************************/

void execute_type_I_LHU_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LHU_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LHU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LHU_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_LHU_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LHU_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_LHU_should_load_rs1_plus_offset_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LHU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT16(value, Register[rd]);
}

void execute_type_I_LHU_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;
    uint8_t rs1 = 5;
    uint8_t rd = 2;
    int32_t rs1_value = 100;
    int16_t imm = 200;
    uint8_t value = 85;

    user_memory_save_byte(rs1_value + imm,value);
    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = LOAD_OPCODE;
    Struct_I.func3 = LHU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_LHU(){
    RUN_TEST(execute_type_I_LHU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_LHU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_LHU_should_not_modify_x0);
    RUN_TEST(execute_type_I_LHU_should_load_rs1_plus_offset_in_rd);
    RUN_TEST(execute_type_I_LHU_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SLTIU
 ******************************************************************************/

void execute_type_I_SLTIU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SLTIU_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SLTIU_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_SLTIU_should_place_1_in_rd_if_rs1_less_than_imm(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = 100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(1, Register[rd]);
}

void execute_type_I_SLTIU_should_place_0_in_rd_if_rs1_greater_than_imm(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = 200;
    uint16_t imm = 100;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[rd]);
}

void execute_type_I_SLTIU_should_place_0_in_rd_if_rs1_equal_to_imm(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = 200;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[rd]);
}

void execute_type_I_SLTIU_should_place_1_in_rd_if_imm_equal_to_1(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 200;
    uint16_t imm = 1;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(1, Register[rd]);
}

void execute_type_I_SLTIU_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTIU_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_SLTIU(){
    RUN_TEST(execute_type_I_SLTIU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_SLTIU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_SLTIU_should_not_modify_x0);
    RUN_TEST(execute_type_I_SLTIU_should_place_1_in_rd_if_rs1_less_than_imm);
    RUN_TEST(execute_type_I_SLTIU_should_place_0_in_rd_if_rs1_greater_than_imm);
    RUN_TEST(execute_type_I_SLTIU_should_place_0_in_rd_if_rs1_equal_to_imm);
    RUN_TEST(execute_type_I_SLTIU_should_place_1_in_rd_if_imm_equal_to_1);
    RUN_TEST(execute_type_I_SLTIU_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction XORI
 ******************************************************************************/

void execute_type_I_XORI_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = XORI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_XORI_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = XORI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_XORI_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = XORI_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_XORI_should_place_XOR_of_rs1_and_imm_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 100;
    int16_t imm = 200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = XORI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(rs1_value ^ imm, Register[rd]);
}

void execute_type_I_XORI_should_place_reverse_of_rs1_in_rd_if_imm_equal_minus_1(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = 200;
    int16_t imm = -1;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = XORI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(~rs1_value, Register[rd]);
}

void execute_type_I_XORI_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = XORI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_XORI(){
    RUN_TEST(execute_type_I_XORI_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_XORI_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_XORI_should_not_modify_x0);
    RUN_TEST(execute_type_I_XORI_should_place_XOR_of_rs1_and_imm_in_rd);
    RUN_TEST(execute_type_I_XORI_should_place_reverse_of_rs1_in_rd_if_imm_equal_minus_1);
    RUN_TEST(execute_type_I_XORI_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction ORI
 ******************************************************************************/

void execute_type_I_ORI_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ORI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_ORI_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ORI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_ORI_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ORI_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_ORI_should_place_OR_of_rs1_and_imm_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 100;
    int16_t imm = 200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ORI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(rs1_value | imm, Register[rd]);
}

void execute_type_I_ORI_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ORI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_ORI(){
    RUN_TEST(execute_type_I_ORI_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_ORI_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_ORI_should_not_modify_x0);
    RUN_TEST(execute_type_I_ORI_should_place_OR_of_rs1_and_imm_in_rd);
    RUN_TEST(execute_type_I_ORI_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction ANDI
 ******************************************************************************/

void execute_type_I_ANDI_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ANDI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_ANDI_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ANDI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_ANDI_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ANDI_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_ANDI_should_place_OR_of_rs1_and_imm_in_rd(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 100;
    int16_t imm = 200;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ANDI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(rs1_value & imm, Register[rd]);
}

void execute_type_I_ANDI_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ANDI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_ANDI(){
    RUN_TEST(execute_type_I_ANDI_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_ANDI_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_ANDI_should_not_modify_x0);
    RUN_TEST(execute_type_I_ANDI_should_place_OR_of_rs1_and_imm_in_rd);
    RUN_TEST(execute_type_I_ANDI_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SLLI
 ******************************************************************************/

void execute_type_I_SLLI_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLLI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SLLI_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLLI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SLLI_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLLI_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_SLLI_should_left_shift_rs1_in_rd_from_shamt(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 3;
    int16_t imm = 2;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLLI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(12, Register[rd]);
}

void execute_type_I_SLLI_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLLI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_SLLI(){
    RUN_TEST(execute_type_I_SLLI_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_SLLI_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_SLLI_should_not_modify_x0);
    RUN_TEST(execute_type_I_SLLI_should_left_shift_rs1_in_rd_from_shamt);
    RUN_TEST(execute_type_I_SLLI_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SRLI
 ******************************************************************************/

void execute_type_I_SRLI_should_return_non_zero_on_rs1_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SRLI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SRLI_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SRLI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SRLI_should_not_modify_x0(){
    struct_I Struct_I;

    Register[1] = 100;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SRLI_FUNCT3;
    Struct_I.rd = 0;
    Struct_I.rs1 = 1;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_I_SRLI_should_right_shift_rs1_in_rd_from_shamt(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 12;
    int16_t imm = 2;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SRLI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(3, Register[rd]);
}

void execute_type_I_SRLI_should_right_shift_rs1_in_rd_from_shamt_and_sign_extend(){
    struct_I Struct_I;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    int32_t rs1_value = 0x8000000C;
    int16_t imm = 1026;

    Register[rs1] = rs1_value;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SRLI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(0xE0000003, Register[rd]);
}

void execute_type_I_SRLI_should_add_4_to_PC(){
    struct_I Struct_I;

    uint32_t start_PC = 100;

    uint8_t rs1 = 1;
    uint8_t rd = 2;

    uint32_t rs1_value = -100;
    uint16_t imm = 200;

    Register[rs1] = rs1_value;

    PC = start_PC;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SRLI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_SRLI(){
    RUN_TEST(execute_type_I_SRLI_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_I_SRLI_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_SRLI_should_not_modify_x0);
    RUN_TEST(execute_type_I_SRLI_should_right_shift_rs1_in_rd_from_shamt);
    RUN_TEST(execute_type_I_SRLI_should_right_shift_rs1_in_rd_from_shamt_and_sign_extend);
    RUN_TEST(execute_type_I_SRLI_should_add_4_to_PC);
}

void RUN_TEST_execute_type_I(){
    //RUN_TEST_executer_type_I_JALR();
    //RUN_TEST_execute_type_I_ADDI();
    //RUN_TEST_execute_type_I_SLTI();
    RUN_TEST_execute_type_I_LB(); // marche pas avec le usermemory
    //RUN_TEST_execute_type_I_LH(); // marche pas avec le usermemory
    //RUN_TEST_execute_type_I_LW(); // marche pas avec le usermemory
    //RUN_TEST_execute_type_I_LBU(); // marche pas avec le usermemory
    //RUN_TEST_execute_type_I_LHU(); // marche pas avec le usermemory
    //RUN_TEST_execute_type_I_SLTIU();
    //RUN_TEST_execute_type_I_XORI();
    //RUN_TEST_execute_type_I_ORI();
    //RUN_TEST_execute_type_I_ANDI();
    //RUN_TEST_execute_type_I_SLLI();
    //RUN_TEST_execute_type_I_SRLI();
}
