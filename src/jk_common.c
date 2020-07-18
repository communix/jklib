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
    *a = *a + *b; /// a = a' + b'
    *b = *a - *b; /// b = a' + b' - b' = a'
    *a = *a - *b; /// a = a' + b' - a' = b'
}