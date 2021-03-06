/**
 * @file jk_unit_test.c
 * @brief unit test of the libjk
 */
#include <jk_type.h>
#include <libjk.h>
#include <unity.h>
#include <time.h>

#define JKLIB_VERSION           0x00000001  //00.00.0001
void setUp (void) {} /* Is run before every test, put unit init calls here. */
void tearDown (void) {} /* Is run after every test, put unit clean-up calls here. */

void test_jklib_version(void)
{
    /// version check
    TEST_ASSERT_EQUAL_UINT32_MESSAGE(JKLIB_VERSION, jk_get_version(), "JKLIB version is not matched");
}

void test_integer_type_size(void)
{
    /// interget type size check
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, sizeof(int8_t), "int8_t is not 1 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(1, sizeof(uint8_t), "uint8_t is not 1 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, sizeof(int16_t), "int16_t is not 2 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(2, sizeof(uint16_t), "uint16_t is not 2 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, sizeof(int32_t), "int32_t is not 4 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(4, sizeof(uint32_t), "uint32_t is not 4 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(8, sizeof(int64_t), "int64_t is not 8 byte");
    TEST_ASSERT_EQUAL_INT_MESSAGE(8, sizeof(uint64_t), "uint64_t is not 8 byte");
}

void test_jk_swap_int32(void)
{
    /// Swap function unit test
    const int32_t a_origin = 3245234;
    const int32_t b_origin = -54252346;
    const int16_t c_origin = 4623;
    const int16_t d_origin = 6693;
    int32_t a = a_origin;
    int32_t b = b_origin;
    int32_t c = c_origin;
    int32_t d = d_origin;
    jk_swap_int32(&a, &b);
    jk_swap_int32(&c, &d);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(a_origin, b, "swaped data is not matched");
    TEST_ASSERT_EQUAL_INT32_MESSAGE(b_origin, a, "swaped data is not matched");
    TEST_ASSERT_EQUAL_INT16_MESSAGE(c_origin, d, "swaped data is not matched");
    TEST_ASSERT_EQUAL_INT16_MESSAGE(d_origin, c, "swaped data is not matched");
}

void test_jk_print_array(void)
{
    int32_t test_array[1] = {1};
    TEST_ASSERT_EQUAL_INT8_MESSAGE(ERROR, jk_print_array(NULL, 1), "Not return ERROR even NULL input");
    TEST_ASSERT_EQUAL_INT8_MESSAGE(NO_ERROR, jk_print_array(test_array, 1), "ERROR even good condition");
}

void test_jk_insert_array(void)
{
    int32_t test_array[20] = {1};
    int32_t expected_arr[20] = {0, 1};
    clock_t start_time, end_time;
    double running_time;
    // check the return values
    TEST_ASSERT_EQUAL_INT8_MESSAGE(ERROR, jk_insert_array(NULL, 0, 0, 1), "Not return ERROR even NULL input");
    TEST_ASSERT_EQUAL_INT8_MESSAGE(NO_ERROR, jk_insert_array(test_array, 1, 0, 0), "Not return ERROR even NULL input");
    // check new array
    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(expected_arr, test_array, 2, "Output array is wrong");
    // Adding the element at the tail
    start_time = clock();
    jk_insert_array(test_array, 2, 2, 2);
    end_time = clock();
    printf ("Running time of the jk_insert_array is %f clocks\n", ((double)(end_time - start_time)));
    expected_arr[2] = 2;
    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(expected_arr, test_array, 2, "Output array is wrong");
}

void test_jk_delete_array(void)
{
    int32_t test_array[20] = {0, 1, 2};
    int32_t expected_arr[2] = {1, 2};
    // check the return values
    TEST_ASSERT_EQUAL_INT8_MESSAGE(ERROR, jk_delete_array(NULL, 0, 0), "Not return ERROR even NULL input");
    TEST_ASSERT_EQUAL_INT8_MESSAGE(ERROR, jk_delete_array(test_array, 3, 3), "Not return ERROR even NULL input");
    TEST_ASSERT_EQUAL_INT8_MESSAGE(NO_ERROR, jk_delete_array(test_array, 3, 0), "Not return ERROR even NULL input");
    // check new array
    jk_delete_array(test_array, 2, 1);
    TEST_ASSERT_EQUAL_INT32_ARRAY_MESSAGE(expected_arr, test_array, 1, "Output array is wrong");
}

void test_jk_string_longest_palindromic(void)
{
    char *input = "";
    char *expected = "";
    TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, js_string_longest_palindromic(input), "No character input do not return proper output");
    input = "a";
    expected = "a";
    TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, js_string_longest_palindromic(input), "a input do not return proper output");
    input = "ab";
    expected = "a";
    TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, js_string_longest_palindromic(input), "ab input do not return proper output");
    input = "abaabdfad";
    expected = "baab";
    TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, js_string_longest_palindromic(input), "abaabdfad input do not return proper output");
}

void test_jk_quick_sort(void)
{
    int test_input[10] = {5, 2, 8, 9, 5, 1, 2, 8, 9, 4};
    int sorted_input[10] = {1, 2, 2, 4, 5, 5, 8, 8, 9, 9};
    jk_quick_sort(test_input, 10);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_input, test_input, 10, "quick sort function is wrong");
    int test_input2[7] = {10, 80, 30, 90, 40, 50, 70};
    int sorted_input2[7] = {10, 30, 40, 50, 70, 80, 90};
    jk_quick_sort(test_input2, 7);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_input2, test_input2, 7, "quick sort function is wrong");
}

void test_jk_insertion_sort(void)
{
    int test_input[10] = {5, 2, 8, 9, 5, 1, 2, 8, 9, 4};
    int sorted_input[10] = {1, 2, 2, 4, 5, 5, 8, 8, 9, 9};
    jk_insertion_sort(test_input, 10);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_input, test_input, 10, "quick sort function is wrong");
    int test_input2[7] = {10, 80, 30, 90, 40, 50, 70};
    int sorted_input2[7] = {10, 30, 40, 50, 70, 80, 90};
    jk_insertion_sort(test_input2, 7);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_input2, test_input2, 7, "quick sort function is wrong");
}

void test_jk_bubble_sort(void)
{
    int test_input[10] = {5, 2, 8, 9, 5, 1, 2, 8, 9, 4};
    int sorted_input[10] = {1, 2, 2, 4, 5, 5, 8, 8, 9, 9};
    jk_bubble_sort(test_input, 10);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_input, test_input, 10, "quick sort function is wrong");
    int test_input2[7] = {10, 80, 30, 90, 40, 50, 70};
    int sorted_input2[7] = {10, 30, 40, 50, 70, 80, 90};
    jk_bubble_sort(test_input2, 7);
    TEST_ASSERT_EQUAL_INT_ARRAY_MESSAGE(sorted_input2, test_input2, 7, "quick sort function is wrong");
}

void test_jk_hash(void)
{
    int out_count = 0;
    jk_hash_t *hash_table = jk_create_hash(100);
    jk_add_hash(hash_table, 120, NULL);
    jk_read_hash(hash_table, 120, &out_count);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(1, out_count, "Hash table count is wrong!!!");
    jk_remove_hash(hash_table, 120);
    jk_read_hash(hash_table, 120, &out_count);
    TEST_ASSERT_EQUAL_INT32_MESSAGE(0, out_count, "Hash table count is wrong!!!");

}
 
int main()
{
    UNITY_BEGIN(); 
    RUN_TEST(test_jklib_version);
    RUN_TEST(test_integer_type_size);
    RUN_TEST(test_jk_swap_int32);
    RUN_TEST(test_jk_print_array);
    RUN_TEST(test_jk_insert_array);
    RUN_TEST(test_jk_delete_array);
    RUN_TEST(test_jk_string_longest_palindromic);
    RUN_TEST(test_jk_quick_sort);
    RUN_TEST(test_jk_insertion_sort);
    RUN_TEST(test_jk_bubble_sort);
    RUN_TEST(test_jk_hash);
    UNITY_END();
    return 1;
}