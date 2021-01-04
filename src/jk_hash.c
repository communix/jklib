/**
 * @file jk_hash.c
 * @brief hash functions
 */

#include <jk_type.h>
#include <jk_version.h>
#include <libjk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief jk_create_hash()
 * Create hash table
 *
 * @param hash_length length of the hash table
 * @return jk_hash_t* address of the created hash table
 */
jk_hash_t *jk_create_hash(int hash_length)
{
    jk_hash_t *output = (jk_hash_t *)malloc(sizeof(jk_hash_t));
    jk_hash_element_t **hash = (jk_hash_element_t **)malloc(sizeof(jk_hash_element_t *));
    jk_hash_element_t *hash_element = (jk_hash_element_t *)calloc(hash_length, sizeof(jk_hash_element_t));
    output->hash = hash;
    *(output->hash) = hash_element;
    output->length = hash_length;
    return output;
}
/**
 * @brief jk_destroy_hash()
 * 
 * @param hash address of the hash table
 */
void jk_destroy_hash(jk_hash_t *hash)
{
    for (int i = 0; i < hash->length; i++)
    {
        jk_hash_element_t *current = (*(hash->hash) + i);
        if ((current == NULL) || (current->next == NULL))
        {
            continue;
        }
        current = current->next;
        while (current->next != NULL)
        {
            jk_hash_element_t *del = current;
            current = current->next;
            free(del);
        }
    }
    free(*(hash->hash));
    free(hash->hash);
    free(hash);
}

/**
 * @brief jk_add_hash()
 * Add data in the hash table
 *
 * @param hash address of the hash table
 * @param key key of this data
 * @param data data, it need to be converted to (void *)
 * @return int JK_HASH_FAIL if new memory is not allocated.
 *             JK_HASH_UPDATED if key is already in the hash (count increase and data is updated).
 *             JK_HASH_ADDED otherwise
 */
int jk_add_hash(jk_hash_t *hash, int key, void *data)
{
    int in_key = key % hash->length;
    jk_hash_element_t *current = (*(hash->hash) + in_key);
    jk_hash_element_t *prev = NULL;
    while (current != NULL)
    {
        if (current->key == key)
        {
            // Duplicated,
            free(current->data);
            current->data = data;
            (current->count)++;
            return JK_HASH_UPDATED; // Updated.
        }
        prev = current;
        current = current->next;
    }
    jk_hash_element_t *new = (jk_hash_element_t *)malloc(sizeof(jk_hash_element_t));
    if (new == NULL)
    {
        return JK_HASH_FAIL; // Fail to allocate memory
    }
    prev->next = new;
    new->key = key;
    (new->count)++;
    new->data = data;
    new->next = NULL;
    return JK_HASH_ADDED;
}

/**
 * @brief jk_read_hash()
 * 
 * @param hash address of the hash table
 * @param key key of the reading data
 * @param count count of the key in the hash - output
 * @return void* data pointer, NULL if the key is not found in the hash.
 */
void *jk_read_hash(jk_hash_t *hash, int key, int *count)
{
    int in_key = key % hash->length;
    *count = 0;
    if ((*(hash->hash) + in_key) != NULL)
    {
        jk_hash_element_t *current = (*(hash->hash) + in_key);
        while(current != NULL)
        {
            if (current->key == key)
            {
                *count = current->count;
                return (void *)current->data;
            }
            current = current->next;
        }
    }
    return NULL;
}

/**
 * @brief jk_remove_hash
 * 
 * @param hash address of the hash table
 * @param key key of the reading data
 */
void jk_remove_hash(jk_hash_t *hash, int key)
{
    int in_key = key % hash->length;
    jk_hash_element_t *current = (*(hash->hash) + in_key);
    jk_hash_element_t *prev = NULL;
    while(current)
    {
        if (current->key == key)
        {
            if (prev != NULL)
            {
                prev->next = current->next;
            }
            free(current);
        }
        prev = current;
        current = current->next;
    }
}