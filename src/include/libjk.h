/**
 * @file libjk.h
 * @brief functions in the libjk (JK library)
 * @author Jay Kim
 * @date 07/24/2020
 */

/**
 * @name jk_get_version
 * @brief read JKLib version to 32bit integer type
 * @return version of the JKLib. [31:24] Major [23:16] Minor [15:0] Patch version
 */
uint32_t jk_get_version(void);

/**
 * @name jk_swap_int32
 * @brief swap two data values
 * @param a int32 address - first data
 * @param b int32 address - second data
 */
void jk_swap_int32(int32_t *a, int32_t *b);

/**
 * @defgroup jk_array functions related to an array
 * @{
 */
/**
 * @name jk_print_array
 * @brief print the array data
 * @param arr array input
 * @param length length of the input array.
 * @return return ERROR(-1) when the arr is NULL otherwise NO_ERROR(0)
 */
int8_t jk_print_array(int32_t *arr, uint32_t length);

/** @} */
 