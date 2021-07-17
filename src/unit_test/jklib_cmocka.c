/**
 * @file jk_unit_test.c
 * @brief unit test of the libjk
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <jk_type.h>
#include <libjk.h>
#include <cmocka.h>
#include <time.h>

#define JKLIB_VERSION           0x00000001  //00.00.0001
int setUp (void **state) /* Is run before every test, put unit init calls here. */
{
    (void)state;
    printf("SetUp for the test\n");
    return 0;
}
int tearDown (void **state) /* Is run after every test, put unit clean-up calls here. */
{
    (void)state;
    printf("TearDown for the test\n");
    return 0;
}
static void test_jklib_version(void **state)
{
    (void) state;
    /// version check
    assert_int_equal(JKLIB_VERSION, jk_get_version());
}

void test_integer_type_size(void **state)
{
    (void) state;
    /// interget type size check
    assert_int_equal(1, sizeof(int8_t));
    assert_int_equal(1, sizeof(uint8_t));
    assert_int_equal(2, sizeof(int16_t));
    assert_int_equal(2, sizeof(uint16_t));
    assert_int_equal(4, sizeof(int32_t));
    assert_int_equal(4, sizeof(uint32_t));
    assert_int_equal(8, sizeof(int64_t));
    assert_int_equal(8, sizeof(uint64_t));
}

void test_jk_swap_int32(void **state)
{
    (void) state;
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
    assert_int_equal(a_origin, b);
    assert_int_equal(b_origin, a);
    assert_int_equal(c_origin, d);
    assert_int_equal(d_origin, c);
}

void test_jk_print_array(void **state)
{
    (void) state;
    int32_t test_array[1] = {1};
    assert_int_equal(ERROR, jk_print_array(NULL, 1));
    assert_int_equal(NO_ERROR, jk_print_array(test_array, 1));
}

void test_jk_insert_array(void **state)
{
    (void) state;
    int32_t test_array[20] = {1};
    int32_t expected_arr[20] = {0, 1};
    clock_t start_time, end_time;
    double running_time;
    // check the return values
    assert_int_equal(ERROR, jk_insert_array(NULL, 0, 0, 1));
    assert_int_equal(NO_ERROR, jk_insert_array(test_array, 1, 0, 0));
    // check new array
    assert_memory_equal(expected_arr, test_array, 2);
    // Adding the element at the tail
    start_time = clock();
    jk_insert_array(test_array, 2, 2, 2);
    end_time = clock();
    printf ("Running time of the jk_insert_array is %f clocks\n", ((double)(end_time - start_time)));
    expected_arr[2] = 2;
    assert_memory_equal(expected_arr, test_array, 2 * sizeof(int32_t));
}

void test_jk_delete_array(void **state)
{
    (void) state;
    int32_t test_array[20] = {0, 1, 2};
    int32_t expected_arr[2] = {1, 2};
    // check the return values
    assert_int_equal(ERROR, jk_delete_array(NULL, 0, 0));
    assert_int_equal(ERROR, jk_delete_array(test_array, 3, 3));
    assert_int_equal(NO_ERROR, jk_delete_array(test_array, 3, 0));
    // check new array
    jk_delete_array(test_array, 2, 1);
    assert_memory_equal(expected_arr, test_array, 1 * sizeof (int32_t));
}

void test_jk_string_longest_palindromic(void **state)
{
    (void) state;
    char *input = "";
    char *expected = "";
    assert_string_equal(expected, js_string_longest_palindromic(input));
    input = "a";
    expected = "a";
    assert_string_equal(expected, js_string_longest_palindromic(input));
    input = "ab";
    expected = "a";
    assert_string_equal(expected, js_string_longest_palindromic(input));
    input = "abaabdfad";
    expected = "baab";
    assert_string_equal(expected, js_string_longest_palindromic(input));
}

void test_jk_quick_sort(void **state)
{
    (void) state;
    int test_input[10] = {5, 2, 8, 9, 5, 1, 2, 8, 9, 4};
    int sorted_input[10] = {1, 2, 2, 4, 5, 5, 8, 8, 9, 9};
    jk_quick_sort(test_input, 10);
    assert_memory_equal(sorted_input, test_input, 10 * sizeof(int));
    int test_input2[7] = {10, 80, 30, 90, 40, 50, 70};
    int sorted_input2[7] = {10, 30, 40, 50, 70, 80, 90};
    jk_quick_sort(test_input2, 7);
    assert_memory_equal(sorted_input2, test_input2, 7 * sizeof(int));
}

void test_jk_insertion_sort(void **state)
{
    (void) state;
    int test_input[10] = {5, 2, 8, 9, 5, 1, 2, 8, 9, 4};
    int sorted_input[10] = {1, 2, 2, 4, 5, 5, 8, 8, 9, 9};
    jk_print_array(test_input, 10);
    jk_insertion_sort(test_input, 10);
    jk_print_array(test_input, 10);
    jk_print_array(sorted_input, 10);
    assert_memory_equal(sorted_input, test_input, 10 * sizeof(int));
    int test_input2[7] = {10, 80, 30, 90, 40, 50, 70};
    int sorted_input2[7] = {10, 30, 40, 50, 70, 80, 90};
    jk_insertion_sort(test_input2, 7);
    assert_memory_equal(sorted_input2, test_input2, 7 * sizeof(int));
}

void test_jk_bubble_sort(void **state)
{
    (void) state;
    int test_input[10] = {5, 2, 8, 9, 5, 1, 2, 8, 9, 4};
    int sorted_input[10] = {1, 2, 2, 4, 5, 5, 8, 8, 9, 9};
    jk_bubble_sort(test_input, 10);
    assert_memory_equal(sorted_input, test_input, 10 * sizeof(int));
    int test_input2[7] = {10, 80, 30, 90, 40, 50, 70};
    int sorted_input2[7] = {10, 30, 40, 50, 70, 80, 90};
    jk_bubble_sort(test_input2, 7);
    assert_memory_equal(sorted_input2, test_input2, 7 * sizeof(int));
}

void test_jk_hash(void **state)
{
    (void) state;
    int out_count = 0;
    jk_hash_t *hash_table = jk_create_hash(100);
    jk_add_hash(hash_table, 120, NULL);
    jk_read_hash(hash_table, 120, &out_count);
    assert_int_equal(1, out_count);
    jk_remove_hash(hash_table, 120);
    jk_read_hash(hash_table, 120, &out_count);
    assert_int_equal(0, out_count);

}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_jklib_version),
        cmocka_unit_test(test_integer_type_size),
        cmocka_unit_test(test_jk_swap_int32),
        cmocka_unit_test(test_jk_print_array),
        cmocka_unit_test(test_jk_insert_array),
        cmocka_unit_test(test_jk_delete_array),
        cmocka_unit_test(test_jk_string_longest_palindromic),
        cmocka_unit_test(test_jk_quick_sort),
        cmocka_unit_test(test_jk_insertion_sort),
        cmocka_unit_test(test_jk_bubble_sort),
        cmocka_unit_test(test_jk_hash),
    };

    return cmocka_run_group_tests(tests, setUp, tearDown);
}