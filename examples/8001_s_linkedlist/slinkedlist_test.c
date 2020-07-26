/**
 * @file slinkedlist_test.c
 * @brief jklib singly linked list function test
 */
#include <jk_type.h>
#include <jk_version.h>
#include <libjk.h>
#include <stdio.h>

/**
 * @name test_jk_s_linked_list
 * @brief test function of the singly linked list functions
 */
static void test_jk_s_linked_list(void)
{
    s_llist_node_t *list1;
    list1 = jk_insert_end_s_linked_list(NULL, 125); // First node 125.
    list1 = jk_insert_end_s_linked_list(list1, 3245); // Second node.
    list1 = jk_insert_end_s_linked_list(list1, 643); // Third node.
    list1 = jk_insert_end_s_linked_list(list1, 5412); // Fourth node.
    if (jk_print_s_linked_list(list1) == ERROR)
    {
        printf ("jk_print_s_linked_list returns error\n");
    }
    printf ("Delete the last node. please check the last node is deleted or not.\n");
    list1 = jk_delete_end_s_linked_list(list1);
    if (jk_print_s_linked_list(list1) == ERROR)
    {
        printf ("jk_print_s_linked_list returns error\n");
    }
}

int main(void){
    printf ("Start test_jk_s_linked_list()\n");
    test_jk_s_linked_list();
}