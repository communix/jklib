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
 * @defgroup jk_linked_list functions related to a linked list
 * @{
 */

/**
 * @struct s_ll_node
 * @brief singly linked list node
 * @{
 */

typedef struct s_llist_node
{
    int32_t value;                  ///< int32 value of the node
    struct s_llist_node *next;      ///< pointer of the next node
} s_llist_node_t;
/** @} */

/**
 * @name jk_insert_end_s_linked_list
 * @brief insert new node at the end of the linked list
 * @param head head pointer of the current linked list, Set NULL to create new linked list.
 * @param value value of the new node.
 * @return header point of the linked list
 */
s_llist_node_t *jk_insert_end_s_linked_list(s_llist_node_t * head, int32_t value);

/**
 * @name jk_delete_end_s_linked_list
 * @brief delete the node at the end of the linked list
 * @param head head pointer of the current linked list
 * @return header point of the linked list, it return NULL if the linked list have no node.
 */
s_llist_node_t *jk_delete_end_s_linked_list(s_llist_node_t * head);

/**
 * @name jk_insert_end_s_linked_list
 * @brief print the linked list
 * @param head head pointer of the current linked list.
 * @return return ERROR(-1) when the head is NULL otherwise NO_ERROR(0)
 */
int8_t jk_print_s_linked_list(s_llist_node_t * head);
/** @} */
