//
// Created by alexa on 2020-06-19.
//

#include "execute_R_test.h"

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

void execute_type_R_MUL_should_return_non_zero_on_rd_equal_to_0(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MUL_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
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
    RUN_TEST(execute_type_R_MUL_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MUL_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MUL_should_return_non_zero_on_rd_equal_to_0);
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

void execute_type_R_MULH_should_return_non_zero_on_rd_equal_to_0(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULH_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
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
    RUN_TEST(execute_type_R_MULH_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MULH_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MULH_should_return_non_zero_on_rd_equal_to_0);
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

void execute_type_R_MULHU_should_return_non_zero_on_rd_equal_to_0(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
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
    RUN_TEST(execute_type_R_MULHU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MULHU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MULHU_should_return_non_zero_on_rd_equal_to_0);
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

void execute_type_R_MULHSU_should_return_non_zero_on_rd_equal_to_0(){
    struct_R Struct_R;

    Struct_R.rs1 = 0;
    Struct_R.rs2 = 0;
    Struct_R.rd = 0;
    Struct_R.funct7 = MUL_DIV_FUNCT7;
    Struct_R.func3 = MULHSU_FUNCT3;

    TEST_ASSERT_NOT_EQUAL(0, execute_type_R(&Struct_R));
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
    RUN_TEST(execute_type_R_MULHSU_should_return_non_zero_on_rs1_greater_than_15);
    RUN_TEST(execute_type_R_MULHSU_should_return_non_zero_on_rd_greater_than_15);
    RUN_TEST(execute_type_R_MULHSU_should_return_non_zero_on_rd_equal_to_0);
    RUN_TEST(execute_type_R_MULHSU_should_place_result_in_rd);
    RUN_TEST(execute_type_R_MULHSU_should_add_4_to_PC);
}

void RUN_TEST_execute_R(){
    RUN_TEST_execute_R_MUL();
    RUN_TEST_execute_R_MULH();
    RUN_TEST_execute_R_MULHU();
    RUN_TEST_execute_R_MULHSU();
}