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