/**
 * @file jk_common.c
 * @brief common functions
 */

#include <jk_type.h>
#include <jk_version.h>
#include <libjk.h>

uint32_t jk_get_version(void)
{
    return JKLIB_VERSION;
}

void jk_swap_int32(int32_t *a, int32_t *b)
{
#if 0
    *a = *a + *b; /// a = a' + b'
    *b = *a - *b; /// b = a' + b' - b' = a'
    *a = *a - *b; /// a = a' + b' - a' = b'
#else
    int32_t temp = *a;
    *a = *b;
    *b = temp;
#endif
}

/**
 * @brief partition function for the quick sort
 *
 * @param in input array
 * @param left left index to sort
 * @param right right index to sort
 * @return int
 */
int partition(int *in, int left, int right)
{
    int pivot = in[right];
    int barrior = 0; // Start from 0
    for (int i = 0; i < right; i++)
    { 
        if (in[i] < pivot)
        {
            jk_swap_int32(&in[i], &in[barrior++]);
        }
    }
    jk_swap_int32(&in[right], &in[barrior]);
    return barrior;
}
/**
 * @brief quick_sort_helper
 *
 * @param in input array
 * @param left left index to sort
 * @param right right index to sort
 */
static void quick_sort_helper(int *in, int left, int right)
{
    if (left < right)
    {
        // @todo need to implement
        int center = partition(in, left, right);
        quick_sort_helper(in, left, center - 1);
        quick_sort_helper(in, center + 1, right);
    }
}
/**
 * @brief jk_quick_sort()
 *
 * @param in input array (int type)
 * @param length length of the input array
 * Sorted data is stored in the input array.
 */
void jk_quick_sort(int *in, int length)
{
    // check the length
    if (length <= 1)
    {
        return;
    }
    // call quick_sort_helper function
    quick_sort_helper(in, 0, length - 1);
}

/**
 * @brief jk_insertion_sort()
 * 
 * @param in input array (int type)
 * @param length length of the input array
 * Sorted data is stored in the input array.
 */
void jk_insertion_sort(int *in, int length)
{
    // check the length
    if (length <= 1)
    {
        return;
    }
    // loop from 1 to end because 0 is sorted
    for (int i = 1; i < length; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (in[j - 1] > in[j])
            {
                jk_swap_int32(&in[j - 1], &in[j]);
            }
            else
            {
                break;
            }
        }
    }
}

/**
 * @brief jk_bubble_sort()
 * 
 * @param in input array (int type)
 * @param length length of the input array
 * Sorted data is stored in the input array.
 */
void jk_bubble_sort(int *in, int length)
{
    // check the length
    if (length <= 1)
    {
        return;
    }
    // Loop from 0 to length - 2
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (in[j] > in[j + 1])
            {
                jk_swap_int32(&in[j], &in[j + 1]);
            }
        }
    }
}