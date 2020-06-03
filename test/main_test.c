//
// Created by rolla on 2020-05-26.
//

#include "unity/unity.h"
#include "../src/RV32EM.h"

void test_strcpy_should_copy();
void test_strlen_should_return_same_length();



void setUp(void)
{
}


void tearDown(void)
{
}

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

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_strlen_should_copy);
    RUN_TEST(test_hexstr_32_bits_number_should_convert_ok);
    RUN_TEST(test_hexstr_16_bits_number_should_convert_ok);
    RUN_TEST(test_hexstr_8_bits_number_should_convert_ok);
    RUN_TEST(test_strcpy_should_copy);
    RUN_TEST(test_strlen_should_return_same_length);
    RUN_TEST(test_strreverse_should_reverse);
    return UNITY_END();

}

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


