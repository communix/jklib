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
