/**
 * @file jk_array.c
 * @brief array functions
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

int8_t jk_insert_array(int32_t *arr, uint32_t length, uint32_t pos, int32_t value)
{
    if (arr == NULL)
    {
        return ERROR;
    }
    if (pos >= length) // Adding new element at the tail
    {
        *(arr + pos) = value;
    } else {
        for (uint32_t i = length - 1; i <= pos; i--)
        {
            *(arr + i + 1) = *(arr + i);
        }
        *(arr + pos) = value;
    }
    return NO_ERROR;
}

int8_t jk_delete_array(int32_t *arr, uint32_t length, uint32_t pos)
{
    if ((arr == NULL) || (pos >= length))
    {
        return ERROR;
    }
    for (uint32_t i = pos; i < (length - 1); i++)
    {
        *(arr + i) = *(arr + i + 1);
    }
    *(arr + length - 1) = 0;
    return NO_ERROR;
}