/**
 * @file jk_linked_list.c
 * @brief Linked list functions
 */

#include <jk_type.h>
#include <jk_version.h>
#include <libjk.h>
#include <stdio.h>
#include <malloc.h>

s_llist_node_t *jk_insert_end_s_linked_list(s_llist_node_t * head, int32_t value)
{
    s_llist_node_t *new_node = (s_llist_node_t *)malloc(sizeof(s_llist_node_t));
    new_node->value = value;
    new_node->next = NULL;
    if (head == NULL) // Create new linked list
    {
        head = new_node;
    }
    else // insert new node at the end of the current linked list
    {
        s_llist_node_t *curr_node = head;
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
    return head;
}

int8_t jk_print_s_linked_list(s_llist_node_t * head)
{
    if (head == NULL) // Create new linked list
    {
        return ERROR;
    }
    else
    {
        s_llist_node_t *curr_node = head;
        while (curr_node != NULL)
        {
            printf("%d --> ", curr_node->value);
            curr_node = curr_node->next;
        }
        printf("\b\b\b\b   \n");
    }
    return NO_ERROR;
}
