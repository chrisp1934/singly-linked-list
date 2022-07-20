#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>

//====================================================================================================
//
//  STRUCTS/ENUMS/UNIONS
//
//====================================================================================================

//====================================================================================================
//  node
//
//  This structure represents a node in a singly linked list.
//
//  Fields:
//      void *data        - The memory address of the data in the node.
//      struct node *next - The memory address of the next node in the list. It equals NULL if there
//                          is no next node in the list.
//====================================================================================================
struct node
{
    void *data;
    struct node *next;
} node;

//====================================================================================================
//
//  GETTING LIST PROPERTIES
//
//====================================================================================================

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
//
//  Time Complexity:
//      O(1) - Constant Time
//====================================================================================================
int is_singly_linked_list_empty(struct node *head);

//====================================================================================================
//  get_singly_linked_list_length
//
//  This function gets the length of a singly linked list.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//
//  Return Value:
//      int - This function returns the length of the singly linked list.
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
int get_singly_linked_list_length(struct node *head);

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
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
struct node *get_singly_linked_list_tail_node(struct node *head);

//====================================================================================================
//
//  SETTING LIST PROPERTIES
//
//====================================================================================================

//====================================================================================================
//
//  BASIC NODE MODIFICATIONS
//
//====================================================================================================

//====================================================================================================
//  create_new_singly_linked_list_node
//
//  This function creates a new singly linked list.
//
//  Arguments:
//      void *data - The memory address of the data to be placed in the first node (head) of the 
//                   singly linked list.
//
//  Return Value:
//      struct node * - This function returns the memory address of the head of the singly linked
//                      list after successful execution and NULL after an error.
//
//  Time Complexity:
//      O(1) - Constant Time
//====================================================================================================
struct node *create_new_singly_linked_list_node(void *data);

//====================================================================================================
//
//  BASIC LIST MODIFICATIONS
//
//====================================================================================================

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
//      struct node * - This function returns the memory address of the head of the singly linked
//                      list after successful execution and NULL after an error.
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
struct node *append_singly_linked_list_node_to_back(struct node *head, void *data);

//====================================================================================================
//  append_singly_linked_list_node_to_front
//
//  This function adds a new node to a singly linked list at the front of the list.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//      void *data        - The memory address of the data.
//
//  Return Value:
//      struct node * - This function returns the memory address of the head of the singly linked
//                      list after successful execution and NULL after an error.
//
//  Time Complexity:
//      O(1) - Contsant Time
//====================================================================================================
struct node *append_singly_linked_list_node_to_front(struct node *head, void *data);

#endif