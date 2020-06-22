//
// Created by alexa on 2020-06-19.
//

#include "execute_R_test.h"

/*******************************************************************************
 * Test pour l'instruction ADD
 ******************************************************************************/

void execute_type_R_ADD_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = ADD_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_ADD_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = ADD_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_ADD_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = ADD_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_ADD_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = ADD_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_ADD_should_place_rs1_plus_rs2_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = ADD_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(530865, Register[3]);
}

void execute_type_R_ADD_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = ADD_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_ADD(){
    RUN_TEST(execute_type_R_ADD_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_ADD_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_ADD_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_ADD_should_not_modify_x0);
    RUN_TEST(execute_type_R_ADD_should_place_rs1_plus_rs2_in_rd);
    RUN_TEST(execute_type_R_ADD_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SUB
 ******************************************************************************/

void execute_type_R_SUB_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SUB_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SUB_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SUB_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SUB_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SUB_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SUB_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SUB_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_SUB_should_place_rs1_minus_rs2_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SUB_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(777777, Register[3]);
}

void execute_type_R_SUB_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SUB_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_SUB(){
    RUN_TEST(execute_type_R_SUB_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_SUB_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_SUB_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_SUB_should_not_modify_x0);
    RUN_TEST(execute_type_R_SUB_should_place_rs1_minus_rs2_in_rd);
    RUN_TEST(execute_type_R_SUB_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SLL
 ******************************************************************************/

void execute_type_R_SLL_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLL_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLL_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLL_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLL_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLL_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLL_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLL_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_SLL_should_place_rs1_logic_shift_left_rs2_time_in_rd(){
    struct_R Struct_R;

    int32_t rs1 = 0x00005555;
    uint32_t rs2 = 0x55555570;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLL_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x55550000, Register[3]);
}

void execute_type_R_SLL_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 0x55550000;
    uint32_t rs2 = 0x55555570;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLL_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_SLL(){
    RUN_TEST(execute_type_R_SLL_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_SLL_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_SLL_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_SLL_should_not_modify_x0);
    RUN_TEST(execute_type_R_SLL_should_place_rs1_logic_shift_left_rs2_time_in_rd);
    RUN_TEST(execute_type_R_SLL_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SRL
 ******************************************************************************/

void execute_type_R_SRL_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SRL_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SRL_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SRL_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_SRL_should_place_rs1_logic_shift_right_rs2_time_in_rd(){
    struct_R Struct_R;

    int32_t rs1 = 0x55550000;
    uint32_t rs2 = 0x55555570;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SRL_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x00005555, Register[3]);
}

void execute_type_R_SRL_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 0x55550000;
    uint32_t rs2 = 0x5555557f;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_SRL(){
    RUN_TEST(execute_type_R_SRL_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_SRL_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_SRL_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_SRL_should_not_modify_x0);
    RUN_TEST(execute_type_R_SRL_should_place_rs1_logic_shift_right_rs2_time_in_rd);
    RUN_TEST(execute_type_R_SRL_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SRA
 ******************************************************************************/

void execute_type_R_SRA_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SRA_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SRA_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SRA_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SRA_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SRA_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SRA_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SRA_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_SRA_should_place_rs1_arithmetic_shift_right_rs2_time_in_rd_1(){
    struct_R Struct_R;

    int32_t rs1 = 0xaaaa0000;
    uint32_t rs2 = 0x55555570;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SRA_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0xffffaaaa, Register[3]);
}

void execute_type_R_SRA_should_place_rs1_arithmetic_shift_right_rs2_time_in_rd_0(){
    struct_R Struct_R;

    int32_t rs1 = 0x55550000;
    uint32_t rs2 = 0x55555570;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SRA_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x00005555, Register[3]);
}

void execute_type_R_SRA_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 0x55550000;
    uint32_t rs2 = 0x5555557f;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = SUB_SRA_FUNCT7;
    Struct_R.func3 = SRA_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_SRA(){
    RUN_TEST(execute_type_R_SRA_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_SRA_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_SRA_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_SRA_should_not_modify_x0);
    RUN_TEST(execute_type_R_SRA_should_place_rs1_arithmetic_shift_right_rs2_time_in_rd_0);
    RUN_TEST(execute_type_R_SRA_should_place_rs1_arithmetic_shift_right_rs2_time_in_rd_1);
    RUN_TEST(execute_type_R_SRA_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SLT
 ******************************************************************************/

void execute_type_R_SLT_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLT_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLT_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLT_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_SLT_should_place_1_in_rd_if_rs1_is_less_than_rs2(){
    struct_R Struct_R;

    int32_t rs1 = -654321;
    int32_t rs2 = 123456;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(1, Register[3]);
}

void execute_type_R_SLT_should_place_0_in_rd_if_rs1_is_greater_than_rs2(){
    struct_R Struct_R;

    int32_t rs1 = 123456;
    int32_t rs2 = -654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[3]);
}

void execute_type_R_SLT_should_place_0_in_rd_if_rs1_is_equal_than_rs2(){
    struct_R Struct_R;

    int32_t rs1 = 123456;
    int32_t rs2 = 123455;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[3]);
}

void execute_type_R_SLT_should_add_4_to_PC(){
    struct_R Struct_R;

    int32_t rs1 = 123456;
    int32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLT_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_SLT(){
    RUN_TEST(execute_type_R_SLT_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_SLT_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_SLT_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_SLT_should_not_modify_x0);
    RUN_TEST(execute_type_R_SLT_should_place_1_in_rd_if_rs1_is_less_than_rs2);
    RUN_TEST(execute_type_R_SLT_should_place_0_in_rd_if_rs1_is_greater_than_rs2);
    RUN_TEST(execute_type_R_SLT_should_place_0_in_rd_if_rs1_is_equal_than_rs2);
    RUN_TEST(execute_type_R_SLT_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction SLTU
 ******************************************************************************/

void execute_type_R_SLTU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLTU_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLTU_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_SLTU_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_SLTU_should_place_1_in_rd_if_rs1_is_less_than_rs2(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(1, Register[3]);
}

void execute_type_R_SLTU_should_place_0_in_rd_if_rs1_is_greater_than_rs2(){
    struct_R Struct_R;

    uint32_t rs1 = 654321;
    uint32_t rs2 = 123456;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[3]);
}

void execute_type_R_SLTU_should_place_0_in_rd_if_rs1_is_equal_than_rs2(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 123455;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[3]);
}

void execute_type_R_SLTU_rd_x0_rs2_should_place_1_in_rd_if_rs2_not_equal_0(){
    struct_R Struct_R;

    uint32_t rs2 = 123455;

    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(1, Register[3]);
}

void execute_type_R_SLTU_rd_x0_rs2_should_place_0_in_rd_if_rs2_equal_0(){
    struct_R Struct_R;

    uint32_t rs2 = 0;

    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[3]);
}

void execute_type_R_SLTU_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = SLTU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_SLTU(){
    RUN_TEST(execute_type_R_SLTU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_SLTU_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_SLTU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_SLTU_should_not_modify_x0);
    RUN_TEST(execute_type_R_SLTU_should_place_1_in_rd_if_rs1_is_less_than_rs2);
    RUN_TEST(execute_type_R_SLTU_should_place_0_in_rd_if_rs1_is_greater_than_rs2);
    RUN_TEST(execute_type_R_SLTU_should_place_0_in_rd_if_rs1_is_equal_than_rs2);
    RUN_TEST(execute_type_R_SLTU_rd_x0_rs2_should_place_1_in_rd_if_rs2_not_equal_0);
    RUN_TEST(execute_type_R_SLTU_rd_x0_rs2_should_place_0_in_rd_if_rs2_equal_0);
    RUN_TEST(execute_type_R_SLTU_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction XOR
 ******************************************************************************/

void execute_type_R_XOR_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = XOR_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_XOR_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = XOR_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_XOR_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = XOR_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_XOR_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = XOR_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_XOR_should_place_rs1_xor_rs2_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = 0x33333333;
    uint32_t rs2 = 0x55555555;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = XOR_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x66666666, Register[3]);
}

void execute_type_R_XOR_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 0x33333333;
    uint32_t rs2 = 0x55555555;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = XOR_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_XOR(){
    RUN_TEST(execute_type_R_XOR_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_XOR_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_XOR_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_XOR_should_not_modify_x0);
    RUN_TEST(execute_type_R_XOR_should_place_rs1_xor_rs2_in_rd);
    RUN_TEST(execute_type_R_XOR_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction OR
 ******************************************************************************/

void execute_type_R_OR_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = OR_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_OR_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = OR_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_OR_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = OR_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_OR_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = OR_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_OR_should_place_rs1_or_rs2_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = 0x33333333;
    uint32_t rs2 = 0x55555555;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = OR_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x77777777, Register[3]);
}

void execute_type_R_OR_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 0x33333333;
    uint32_t rs2 = 0x55555555;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = OR_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_OR(){
    RUN_TEST(execute_type_R_OR_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_OR_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_OR_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_OR_should_not_modify_x0);
    RUN_TEST(execute_type_R_OR_should_place_rs1_or_rs2_in_rd);
    RUN_TEST(execute_type_R_OR_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction AND
 ******************************************************************************/

void execute_type_R_AND_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = AND_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_AND_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = AND_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_AND_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = AND_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_AND_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = AND_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_AND_should_place_rs1_or_rs2_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = 0x33333333;
    uint32_t rs2 = 0x55555555;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = AND_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x11111111, Register[3]);
}

void execute_type_R_AND_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 0x33333333;
    uint32_t rs2 = 0x55555555;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = R_GENERAL_FUNCT7;
    Struct_R.func3 = AND_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_AND(){
    RUN_TEST(execute_type_R_AND_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_AND_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_AND_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_AND_should_not_modify_x0);
    RUN_TEST(execute_type_R_AND_should_place_rs1_or_rs2_in_rd);
    RUN_TEST(execute_type_R_AND_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction MUL
 ******************************************************************************/

void execute_type_R_MUL_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MUL_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MUL_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MUL_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MUL_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MUL_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MUL_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MUL_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_MUL_should_place_result_in_rd(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MUL_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x312541c0, Register[3]);
}

void execute_type_R_MUL_should_add_4_to_PC(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MUL_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_MUL(){
    RUN_TEST(execute_type_R_MUL_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MUL_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_MUL_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MUL_should_not_modify_x0);
    RUN_TEST(execute_type_R_MUL_should_place_result_in_rd);
    RUN_TEST(execute_type_R_MUL_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction MULH
 ******************************************************************************/


void execute_type_R_MULH_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULH_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULH_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULH_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULH_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULH_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULH_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULH_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_MULH_should_place_result_in_rd(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    int32_t rs2 = 654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULH_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0xffffffed, Register[3]);
}

void execute_type_R_MULH_should_add_4_to_PC(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    int32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULH_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_MULH(){
    RUN_TEST(execute_type_R_MULH_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MULH_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_MULH_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MULH_should_not_modify_x0);
    RUN_TEST(execute_type_R_MULH_should_place_result_in_rd);
    RUN_TEST(execute_type_R_MULH_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction MULHU
 ******************************************************************************/

void execute_type_R_MULHU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULHU_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULHU_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULHU_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    //TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_MULHU_should_place_result_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0x00000012, Register[3]);
}

void execute_type_R_MULHU_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_MULHU(){
    RUN_TEST(execute_type_R_MULHU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MULHU_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_MULHU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MULHU_should_not_modify_x0);
    RUN_TEST(execute_type_R_MULHU_should_place_result_in_rd);
    RUN_TEST(execute_type_R_MULHU_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction MULHSU
 ******************************************************************************/

void execute_type_R_MULHSU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHSU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULHSU_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHSU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULHSU_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHSU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_MULHSU_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 200;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHSU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_MULHSU_should_place_result_in_rd(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHSU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0xffffffed, Register[3]);
}

void execute_type_R_MULHSU_should_add_4_to_PC(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 654321;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHSU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_MULHSU(){
    RUN_TEST(execute_type_R_MULHSU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MULHSU_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_MULHSU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MULHSU_should_not_modify_x0);
    RUN_TEST(execute_type_R_MULHSU_should_place_result_in_rd);
    RUN_TEST(execute_type_R_MULHSU_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction DIV
 ******************************************************************************/

void execute_type_R_DIV_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIV_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_DIV_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIV_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_DIV_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIV_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_DIV_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 50;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIV_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_DIV_should_place_result_in_rd(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 53;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIV_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32((-2329), Register[3]);
}

void execute_type_R_DIV_should_add_4_to_PC(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 53;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIV_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_DIV(){
    RUN_TEST(execute_type_R_DIV_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_DIV_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_DIV_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_DIV_should_not_modify_x0);
    RUN_TEST(execute_type_R_DIV_should_place_result_in_rd);
    RUN_TEST(execute_type_R_DIV_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction DIVU
 ******************************************************************************/

void execute_type_R_DIVU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIVU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_DIVU_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIVU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_DIVU_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIVU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_DIVU_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 50;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIVU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_DIVU_should_place_result_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 53;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIVU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32((2329), Register[3]);
}

void execute_type_R_DIVU_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 53;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = DIVU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_DIVU(){
    RUN_TEST(execute_type_R_DIVU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_DIVU_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_DIVU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_DIVU_should_not_modify_x0);
    RUN_TEST(execute_type_R_DIVU_should_place_result_in_rd);
    RUN_TEST(execute_type_R_DIVU_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction REM
 ******************************************************************************/

void execute_type_R_REM_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REM_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_REM_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REM_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_REM_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REM_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_REM_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 55;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REM_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_REM_should_place_result_in_rd(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 53;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REM_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32((-19), Register[3]);
}

void execute_type_R_REM_should_add_4_to_PC(){
    struct_R Struct_R;

    int32_t rs1 = -123456;
    uint32_t rs2 = 53;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REM_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_REM(){
    RUN_TEST(execute_type_R_REM_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_REM_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_REM_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_REM_should_not_modify_x0);
    RUN_TEST(execute_type_R_REM_should_place_result_in_rd);
    RUN_TEST(execute_type_R_REM_should_add_4_to_PC);
}

/*******************************************************************************
 * Test pour l'instruction REM
 ******************************************************************************/

void execute_type_R_REMU_should_return_non_zero_on_rs1_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 16;
    Struct_R.rs2 = 0;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REMU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_REMU_should_return_non_zero_on_rs2_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 16;
    Struct_R.rd = 1;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REMU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_REMU_should_return_non_zero_on_rd_greater_than_15(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 16;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REMU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
}

void execute_type_R_REMU_should_not_modify_x0(){
    struct_R Struct_R;

    Register[1] = 100;
    Register[2] = 55;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REMU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(0, Register[0]);
}

void execute_type_R_REMU_should_place_result_in_rd(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 53;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REMU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32((19), Register[3]);
}

void execute_type_R_REMU_should_add_4_to_PC(){
    struct_R Struct_R;

    uint32_t rs1 = 123456;
    uint32_t rs2 = 53;

    PC = 100;

    Register[1] = (uint32_t)rs1;
    Register[2] = (uint32_t)rs2;

    Struct_R.rs1 = 1;
    Struct_R.rs2 = 2;
    Struct_R.rd = 3;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = REMU_FUNCT3;

    TEST_ASSERT_EQUAL_UINT8(0, execute_type_R(&Struct_R));
    TEST_ASSERT_EQUAL_UINT32(104, PC);
}

void RUN_TEST_execute_R_REMU(){
    RUN_TEST(execute_type_R_REMU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_REMU_should_return_non_zero_on_rs2_greater_than_15);
    RUN_TEST(execute_type_R_REMU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_REMU_should_not_modify_x0);
    RUN_TEST(execute_type_R_REMU_should_place_result_in_rd);
    RUN_TEST(execute_type_R_REMU_should_add_4_to_PC);
}

void RUN_TEST_execute_R(){
    RUN_TEST_execute_R_ADD();
    RUN_TEST_execute_R_SUB();
    RUN_TEST_execute_R_SLL();
    RUN_TEST_execute_R_SLT();
    RUN_TEST_execute_R_SLTU();
    RUN_TEST_execute_R_XOR();
    RUN_TEST_execute_R_SRL();
    RUN_TEST_execute_R_SRA();
    RUN_TEST_execute_R_OR();
    RUN_TEST_execute_R_AND();
    RUN_TEST_execute_R_MUL();
    RUN_TEST_execute_R_MULH();
    RUN_TEST_execute_R_MULHU();
    RUN_TEST_execute_R_MULHSU();
    RUN_TEST_execute_R_DIV();
    RUN_TEST_execute_R_DIVU();
    RUN_TEST_execute_R_REM();
    RUN_TEST_execute_R_REMU();
}