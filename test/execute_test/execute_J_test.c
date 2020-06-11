//
// Created by alexa on 2020-06-11.
//

#include "execute_J_test.h"

void excute_type_J_JAL_should_return_non_zero_on_rd_greater_than_15(){
    struct_J Struct_J;

    Struct_J.rd = 16;
    Struct_J.opcode = JAL_OPCODE;

    TEST_ASSERT_NOT_EQUAL (0, execute_type_J(&Struct_J));
}

void execute_type_J_JAL_should_add_offset_to_PC(){
    struct_J Struct_J;
    uint32_t start_PC = 100;

    PC = start_PC;
    uint32_t imm = 200;

    Struct_J.rd = 0;
    Struct_J.opcode = JAL_OPCODE;

    Struct_J.imm_20 = (imm >> 19) & 0x00001;
    Struct_J.imm_19_12 = (imm >> 11) & 0x000ff;
    Struct_J.imm_11 = (imm >> 10) & 0x00001;
    Struct_J.imm_10_1 = (imm >> 0) & 0x003ff;


    TEST_ASSERT_EQUAL_UINT8(0, execute_type_J(&Struct_J));
    TEST_ASSERT_EQUAL_UINT32(start_PC + ((imm << 1) & 0x1111e), PC);
}

void execute_type_J_JAL_should_place_PC_plus_4_in_rd(){
    struct_J Struct_J;
    uint32_t start_PC = 100;

    PC = start_PC;

    Struct_J.rd = 11;
    Struct_J.opcode = JAL_OPCODE;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_J(&Struct_J));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, Register[Struct_J.rd]);
}

void RUN_TEST_executer_type_J_JAL(){
    RUN_TEST(excute_type_J_JAL_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_J_JAL_should_add_offset_to_PC);
    RUN_TEST(execute_type_J_JAL_should_place_PC_plus_4_in_rd);
}
