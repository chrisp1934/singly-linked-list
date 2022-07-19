#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>

//====================================================================================================
//  node
//
//  TODO: FILL IN
//====================================================================================================
struct node
{
    void *data;
    struct node *next;
} node;

//====================================================================================================
//  is_list_empty
//
//  This function checks if a singly linked list is empty.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//
//  Return Value:
//      int - This function returns 1 if the list is empty and 0 if it is not.
//====================================================================================================
int is_singly_linked_list_empty(struct node *head);

//====================================================================================================
//  get_singly_linked_list_tail_node
//
//  This function gets the tail node in a singly linked list.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//
//  Return Value:
//      struct node * - This function returns the memory address of the tail node in a singly linked
//                      after successful execution and NULL after an error.
//====================================================================================================
struct node *get_singly_linked_list_tail_node(struct node *head);

//====================================================================================================
//  append_singly_linked_list_node_to_back
//
//  This function adds a new node to a singly linked list at the end of the list.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//      void *data        - The memory address of the data.
//
//  Return Value:
//      struct node * - This function returns the memory address of the head of the singly linked list
//                      after successful execution and NULL after an error.
//====================================================================================================
struct node *append_singly_linked_list_node_to_back(struct node *head, void *data);

#endif