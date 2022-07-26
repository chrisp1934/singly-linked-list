# Singly Linked List
## Description
A C library for a singly linked list using a void pointer for data written by Christopher Priebe. This library aims to use as little of the C standard library as possible.

## Node Structure
```c
struct node
{
    void *data;
    struct node *next;
} node;
```

## Implemented Functions
### Getting List Properties
- [X] Is the list empty? (```int is_singly_linked_list_empty(struct node *head)```)
- [X] Is node in list? (```int is_node_in_singly_linked_list(struct node *head, const void *data, int (*compare)(const void *, const void *))```)
- [X] Get length of list (```size_t get_singly_linked_list_length(struct node *head)```)
- [X] Get current tail node (```struct node *get_singly_linked_list_tail_node(struct node *head)```)

### Setting List Properties

### Basic Node Modifications
- [X] Create new node (```struct node *create_new_singly_linked_list_node(void *data)```)

### Basic List Modifications
- [X] Append new node to back (```struct node *append_singly_linked_list_node_to_back(struct node *head, void *data)```)
- [X] Append new node to front (```struct node *append_singly_linked_list_node_to_front(struct node *head, void *data)```)

### Freeing List
- [X] Free list (```void free_singly_linked_list(struct node *head)```)
