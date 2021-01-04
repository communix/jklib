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
 * @brief jk_quick_sort()
 *
 * @param in input array (int type)
 * @param length length of the input array
 * Sorted data is stored in the input array.
 */
void jk_quick_sort(int *in, int length);

/**
 * @brief jk_insertion_sort()
 * 
 * @param in input array (int type)
 * @param length length of the input array
 * Sorted data is stored in the input array.
 */
void jk_insertion_sort(int *in, int length);

/**
 * @brief jk_bubble_sort()
 * 
 * @param in input array (int type)
 * @param length length of the input array
 * Sorted data is stored in the input array.
 */
void jk_bubble_sort(int *in, int length);
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

/**
 * @name jk_insert_array
 * @brief insert element in the array
 * @param arr array input
 * @param length length of the input array.
 * @param pos position of the inserted element
 * @param value value of the inserted element
 * @return return ERROR(-1) when the arr is NULL otherwise NO_ERROR(0)
 */
int8_t jk_insert_array(int32_t *arr, uint32_t length, uint32_t pos, int32_t value);

/**
 * @name jk_delete_array
 * @brief delete element in the array
 * @param arr array input
 * @param length length of the input array.
 * @param pos position of the deleted element
 * @return return ERROR(-1) when the arr is NULL otherwise NO_ERROR(0)
 *         or return ERROR(-1) when the pos is equal of greater than length
 */
int8_t jk_delete_array(int32_t *arr, uint32_t length, uint32_t pos);

/** @} */

 /**
 * @defgroup jk_string functions
 * @{
 */

 /**
 * @name js_string_longest_palindromic
 * @brief longest palindromic sub array function - Brute Force
 * @param input input string max lenght is 99.
 * @return longest palindromic of the input string.
 */
char *js_string_longest_palindromic(char *input);

/** @} */

 /**
 * @defgroup jk_hash functions
 * @{
 */

#define JK_HASH_ADDED       0
#define JK_HASH_UPDATED     1
#define JK_HASH_FAIL        -1
/**
 * @brief jk_hash_element_t
 * data structure for the hash element, it has original key and data
 */
typedef struct jk_hash_elements_s{
    unsigned int key;
    unsigned int count;
    void *data;
    struct jk_hash_elements_s *next;
} jk_hash_element_t;

/**
 * @brief jk_hash_t
 * Structure of the hash, it has the length of the hash table and array of the hash elements
 */
typedef struct {
    jk_hash_element_t **hash;
    int length;
} jk_hash_t;

/**
 * @brief jk_create_hash()
 * Create hash table
 *
 * @param hash_length length of the hash table
 * @return jk_hash_t* address of the created hash table
 */
jk_hash_t *jk_create_hash(int hash_length);

/**
 * @brief jk_destroy_hash()
 * 
 * @param hash address of the hash table
 */
void jk_destroy_hash(jk_hash_t *hash);

/**
 * @brief jk_add_hash()
 * Add data in the hash table
 *
 * @param hash address of the hash table
 * @param key key of this data
 * @param data data, it need to be converted to (void *)
 * @return int -1 if new memory is not allocated. 0 otherwise
 */
int jk_add_hash(jk_hash_t *hash, int key, void *data);

/**
 * @brief jk_read_hash()
 * 
 * @param hash address of the hash table
 * @param key key of the reading data
 * @param count count of the key in the hash - output
 * @return void* data pointer, NULL if the key is not found in the hash.
 */
void *jk_read_hash(jk_hash_t *hash, int key, int *count);

/**
 * @brief jk_remove_hash
 * 
 * @param hash address of the hash table
 * @param key key of the reading data
 */
void jk_remove_hash(jk_hash_t *hash, int key);
/** @} */
