//====================================================================================================
//
//  File Name:   singly_linked_list.h
//  Author:      Christopher Priebe
//  Repository:  singly-linked-list
//  Date:        7/20/2022
//
//====================================================================================================

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
//  is_data_in_singly_linked_list
//
//  This function checks if a node holding a specified value exists in a singly linked list.
//
//  Arguments:
//      struct node *head                          - The memory address of the first node in the
//                                                   list.
//      const void *data                           - The memory address of the value to search for in
//                                                   the list.
//      int (*compare)(const void *, const void *) - The comparison function used to find an
//                                                   equivalent value in the list.
//  Return Value:
//      int - The position of the first occurence of the node containing the value in the list. -1
//            is returned if the value is not found in the list.
//
//  Time Complexity:
//      O(n) - Linear Complexity
//====================================================================================================
int is_data_in_singly_linked_list(struct node *head, const void *data, int (*compare)(const void *, const void *));

//====================================================================================================
//  get_singly_linked_list_length_iteratively
//
//  This function gets the length of a singly linked list iteratively.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//
//  Return Value:
//      size_t - This function returns the length of the list.
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
size_t get_singly_linked_list_length_iteratively(struct node *head);

//====================================================================================================
//  get_singly_linked_list_length_recursively
//
//  This function gets the length of a singly linked list recursively.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//
//  Return Value:
//      size_t - This function returns the length of the list.
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
size_t get_singly_linked_list_length_recursively(struct node *head);

//====================================================================================================
//  get_singly_linked_list_tail_node
//
//  This function gets the tail node in a singly linked list.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//
//  Return Value:
//      struct node * - This function returns the memory address of the tail node in a after
//                      successful execution and NULL after an error.
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
struct node *get_singly_linked_list_tail_node(struct node *head);

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
//      void *new_node_data - The memory address of the data to be placed in the first node (head) of 
//                            the singly linked list.
//
//  Return Value:
//      struct node * - This function returns the memory address of the head of the list after
//                      successful execution and NULL after an error.
//
//  Time Complexity:
//      O(1) - Constant Time
//====================================================================================================
struct node *create_new_singly_linked_list_node(void *new_node_data);

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
//      struct node *head   - The memory address of the first node in the list.
//      void *new_node_data - The memory address of the data.
//
//  Return Value:
//      struct node * - This function returns the memory address of the head of the list after
//                      successful execution and NULL after an error.
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
struct node *append_singly_linked_list_node_to_back(struct node *head, void *new_node_data);

//====================================================================================================
//  append_singly_linked_list_node_to_front
//
//  This function adds a new node to a singly linked list at the front of the list.
//
//  Arguments:
//      struct node *head   - The memory address of the first node in the list.
//      void *new_node_data - The memory address of the data.
//
//  Return Value:
//      struct node * - This function returns the memory address of the head of the list after
//                      successful execution and NULL after an error.
//
//  Time Complexity:
//      O(1) - Constant Time
//====================================================================================================
struct node *append_singly_linked_list_node_to_front(struct node *head, void *new_node_data);

//====================================================================================================
//  append_singly_linked_list_node_after_node
//
//  This function adds a new node to a singly linked list after the node at the address passed.
//
//  Arguments:
//      struct node *head          - The memory address of the first node in the list.
//      void *new_node_data        - The memory address of the data.
//      struct node *selected_node - The address of the node for which the new node will be placed
//                                   after.
//
//  Return Value:
//      struct node * - This function returns the memory address of the head of the list after
//                      successful execution and NULL after an error.
//
//  Time Complexity:
//      O(n) - Constant Time
//====================================================================================================
struct node *append_singly_linked_list_node_after_node(struct node *head, void *new_node_data, struct node *selected_node);

//====================================================================================================
//
//  FREEING LIST
//
//====================================================================================================

//====================================================================================================
//  free_singly_linked_list
//
//  This function deallocates memory for the nodes in a singly linked list. It does NOT deallocate
//  memory for any of the data in the singly linked list.
//
//  Arguments:
//      struct node *head - The memory address of the first node in the list.
//
//  Return Value:
//      void
//
//  Time Complexity:
//      O(n) - Linear Time
//====================================================================================================
void free_singly_linked_list(struct node *head);

#endif