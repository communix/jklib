/**
 * @file jk_unit_test.c
 * @brief unit test of the libjk
 */
#include <jk_type.h>
#include <libjk.h>
#include <unity.h>

#define JKLIB_VERSION           0x00000001  //00.00.0001
void setUp (void) {} /* Is run before every test, put unit init calls here. */
void tearDown (void) {} /* Is run after every test, put unit clean-up calls here. */

void test_jklib_version(void)
{
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(JKLIB_VERSION, jk_get_version(), "JKLIB version is not matched");
}
void test_integer_type_size(void)
{
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, sizeof(int8_t), "int8_t is not 1 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, sizeof(uint8_t), "uint8_t is not 1 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, sizeof(int16_t), "int16_t is not 2 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, sizeof(uint16_t), "uint16_t is not 2 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, sizeof(int32_t), "int32_t is not 4 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, sizeof(uint32_t), "uint32_t is not 4 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(8, sizeof(int64_t), "int64_t is not 8 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(8, sizeof(uint64_t), "uint64_t is not 8 byte");
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_jklib_version);
    RUN_TEST(test_integer_type_size);
    UNITY_END();
    return 1;
}