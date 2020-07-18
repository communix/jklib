/**
 * @file array_function_test.c
 * @brief jklib array function test
 */
#include <jk_type.h>
#include <jk_version.h>
#include <libjk.h>
#include <stdio.h>

/**
 * @name test_jk_print_array
 * @brief test function of the jk_print_array()
 * Need to check the array is printed without error.
 */
static void test_jk_print_array(void)
{
    int8_t result;
    int32_t input1[20] = {0, 10, 20, 30, 40};
    if (jk_print_array(input1, 20) == ERROR)
    {
        printf ("jk_print_array returns error\n");
    }
    /// Check this function return error when the arry is NULL
    int32_t *input2 = NULL;
    if (jk_print_array(input2, 20) == ERROR)
    {
        printf ("jk_print_array returns error\n");
    }
}

int main(void){
    printf ("Start test_jk_print_array()\n");
    test_jk_print_array();
}