//
// Created by rolla on 2020-06-27.
//

#include "execute_U_test.h"

void execute_type_U_AUIPC_should_return_1_if_rd_greater_than_15(){
    struct_U Struct_U;

    Struct_U.opcode = 0x37;
    Struct_U.rd = 16;
    Struct_U.imm = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_U(&Struct_U));
}
void execute_type_U_AUIPC_should_add_4_to_PC(){
    struct_U Struct_U;
    uint32_t start_PC = 100;

    Struct_U.opcode = 0x37;
    Struct_U.rd = 4;
    Struct_U.imm = 0;

    PC = start_PC;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_U(&Struct_U));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void execute_type_U_AUIPC_rc_should_be_imm_plus_offset_plus_PC(){
    struct_U Struct_U;

    uint8_t rd = 5;
    uint32_t start_PC = 8;

    Struct_U.opcode = 0x37;
    Struct_U.rd = rd;
    Struct_U.imm = 100;

    PC = start_PC;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_U(&Struct_U));
    TEST_ASSERT_EQUAL_UINT32(409608,Register[rd]);
}


void execute_type_U_LUI_should_return_1_if_rd_greater_than_15(){
    struct_U Struct_U;

    Struct_U.opcode = 0x17;
    Struct_U.rd = 16;
    Struct_U.imm = 0;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_U(&Struct_U));
}
void execute_type_U_LUI_should_add_4_to_PC(){
    struct_U Struct_U;
    uint32_t start_PC = 100;

    Struct_U.opcode = 0x17;
    Struct_U.rd = 4;
    Struct_U.imm = 0;

    PC = start_PC;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_U(&Struct_U));
    TEST_ASSERT_EQUAL_UINT32(start_PC + 4, PC);
}

void execute_type_U_LUI_rc_should_be_imm_plus_offset(){
    struct_U Struct_U;

    uint8_t rd = 5;
    Struct_U.opcode = 0x17;
    Struct_U.rd = rd;
    Struct_U.imm = 100;


    TEST_ASSERT_EQUAL_UINT8(0, execute_type_U(&Struct_U));
    TEST_ASSERT_EQUAL_UINT32(409600,Register[rd]);
}

void RUN_TEST_execute_type_U_AUIPC() {
    RUN_TEST(execute_type_U_AUIPC_should_return_1_if_rd_greater_than_15);
    RUN_TEST(execute_type_U_AUIPC_should_add_4_to_PC);
    RUN_TEST(execute_type_U_AUIPC_rc_should_be_imm_plus_offset_plus_PC);

}
void RUN_TEST_execute_type_U_LUI() {
    RUN_TEST(execute_type_U_LUI_should_return_1_if_rd_greater_than_15);
    RUN_TEST(execute_type_U_LUI_should_add_4_to_PC);
    RUN_TEST(execute_type_U_LUI_rc_should_be_imm_plus_offset);

}

void RUN_TEST_execute_type_U() {
    RUN_TEST_execute_type_U_AUIPC();
    RUN_TEST_execute_type_U_LUI();
}