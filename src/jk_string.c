/**
 * @file jk_string.c
 * @brief string functions
 */

#include <jk_type.h>
#include <jk_version.h>
#include <libjk.h>
#include <stdio.h>
#include <stdlib.h>

char *js_string_longest_palindromic(char *input)
{
    // Brute Force method
    uint16_t string_length = 0;         ///< length of the input string
    uint16_t max_length = 1;            ///< max length of the palindromic sub-array
    uint16_t start_index = 0;           ///< start index of the palindromic sub-array
    char *output;                       ///< output string

    /// Calculate length of the input string
    while (*(input + string_length) != '\0')
    {
        string_length++;
    }
    printf ("input string length is %d\n", string_length);

    if (string_length >= 1)
    { /// run this algorithm when string length is more than 1.
        for (uint16_t i = 0; i < string_length; i++)
        {
            for (uint16_t j = i + 1; j < string_length; j++)
            {
                if (*(input + i) == *(input + j)) /// Find sub-array which can be a palindromic
                {
                    /// Check a palindromic
                    uint8_t found_palindromic = 1;  /// default setting is found palindromic
                    uint16_t index_left = i;        /// index of the start of the sub-array
                    uint16_t index_right = j;       /// index of the end of the sub-array
                    while (index_left < index_right)
                    { /// Check a palindromic
                        if (*(input + index_left) != *(input + index_right))
                        {
                            found_palindromic = 0; /// Not a palindromic
                            break; // Do not need to run anymore.
                        }
                        index_left++;
                        index_right--;
                    }
                    if (found_palindromic == 1) { /// Found palindromic sub array
                        uint16_t current_length = (j - i + 1);
                        if (max_length < current_length) /// Save the lenth and start index if the new palindromic sub array has a maximum length
                        {
                            max_length = current_length;
                            start_index = i;
                        }
                    }
                }
            }
        }
        if (max_length == 1) {
            output = (char *)malloc(2);
            /// Max length 1 means there's no palindromic sub array. so the first one character will be returned.
            *output = *input;
        }
        else
        {
            /// Copy palindromic sub-array to the output buffer
            output = (char *)malloc(max_length + 1);
            for (uint16_t i = 0; i < max_length; i++)
            {
                *(output + i) = *(input + start_index + i);
            }
        }
    } else {
        /// the output of the single character input is the same as a input.
        output = (char *)malloc(2);
        *output = *input;
    }
    *(output + max_length) = '\0';
    return output;
}
