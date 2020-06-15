//
// Created by alexa on 2020-06-11.
//

#include "execute_I_test.h"

void excute_type_I_JALR_should_return_non_zero_on_rd_greater_than_15(){
    struct_I Struct_I;

    Struct_I.rd = 16;
    Struct_I.opcode = JALR_OPCODE;

    TEST_ASSERT_NOT_EQUAL (0, execute_type_I(&Struct_I));
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
    Struct_I.opcode = JALR_OPCODE;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, Register[Struct_I.rd]);
}

void RUN_TEST_executer_type_I_JALR(){
    RUN_TEST(excute_type_I_JALR_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_I_JALR_should_add_imm_plus_rs1_to_PC);
    RUN_TEST(execute_type_I_JALR_should_place_PC_plus_4_in_rd);
}

void execute_type_I_ADDI_should_return_non_zero_on_rd_greater_than_16(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_ADDI_should_return_non_zero_on_rs1_greater_than_16(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
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
    RUN_TEST(execute_type_I_ADDI_should_return_non_zero_on_rs1_greater_than_16);
    RUN_TEST(execute_type_I_ADDI_should_return_non_zero_on_rd_greater_than_16);
    RUN_TEST(execute_type_I_ADDI_should_place_rs1_plus_imm_in_rd);
    RUN_TEST(execute_type_I_ADDI_should_add_4_to_PC);
}

void execute_type_I_SLTI_should_return_non_zero_on_rd_greater_than_16(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rd = 16;
    Struct_I.rs1 = 1;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
}

void execute_type_I_SLTI_should_return_non_zero_on_rs1_greater_than_16(){
    struct_I Struct_I;

    Struct_I.opcode = ARMT_OPCODE;
    Struct_I.func3 = SLTI_FUNCT3;
    Struct_I.rd = 1;
    Struct_I.rs1 = 16;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_I(&Struct_I));
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
    Struct_I.func3 = ADDI_FUNCT3;
    Struct_I.rs1 = rs1;
    Struct_I.imm_11_0 = imm;
    Struct_I.rd = rd;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_I(&Struct_I));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void RUN_TEST_execute_type_I_SLTI(){
    RUN_TEST(execute_type_I_SLTI_should_return_non_zero_on_rs1_greater_than_16);
    RUN_TEST(execute_type_I_SLTI_should_return_non_zero_on_rd_greater_than_16);
    RUN_TEST(execute_type_I_SLTI_should_place_1_in_rd_if_rs1_greater_than_imm);
    RUN_TEST(execute_type_I_SLTI_should_place_0_in_rd_if_rs1_smaller_than_imm);
    RUN_TEST(execute_type_I_SLTI_should_place_0_in_rd_if_rs1_equal_to_imm);
    RUN_TEST(execute_type_I_SLTI_should_add_4_to_PC);
}
