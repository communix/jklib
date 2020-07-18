/**
 * @file jk_common.c
 * @brief common functions
 */

#include <jk_type.h>
#include <jk_version.h>
#include <libjk.h>
#include <stdio.h>

int8_t jk_print_array(int32_t *arr, uint32_t length)
{
    if (arr == NULL)
    {
        return ERROR;
    }
    for (uint32_t i = 0; i < length; i++)
    {
        printf("[%d] %d, ", i, *(arr + i));
    }
    printf ("\b\b  \n");
    return NO_ERROR;
}
