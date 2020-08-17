/**
 * @file jk_type.h
 * @brief define a new type to support multi platform
 */
#ifndef __JK_TYPE_H
#define __JK_TYPE_H

/**
 * @typedef integer type for 64bit windows support
 * @{
 */
typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
// conflict at linux build env.
//typedef signed long long int int64_t;
//typedef unsigned long long int uint64_t;
/** @} */

/**
 * @def return of the functions
 * @{
 */
#define NO_ERROR        0   ///< No error in this function.
#define ERROR           -1  ///< Error in this function.
/** @} */
#endif //__JK_TYPE_H
