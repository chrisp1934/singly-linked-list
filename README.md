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
- [X] Is specific data in list? (```int is_data_in_singly_linked_list(struct node *head, const void *data, int (*compare)(const void *, const void *))```)
- [X] Get length of list iteratively (```size_t get_singly_linked_list_length_iteratively(struct node *head)```)
- [X] Get length of list recursively (```size_t get_singly_linked_list_length_recursively(struct node *head)```)
- [X] Get current tail node (```struct node *get_singly_linked_list_tail_node(struct node *head)```)
- [ ] Get node at specific position
- [ ] Get number of occurrences of specific data
- [ ] Is there a loop in the list?
- [ ] Get loop length
- [ ] Remove duplicate elements from unsorted list
- [ ] Remove duplicate elemtns from sorted list

### Basic Node Modifications
- [X] Create new node (```struct node *create_new_singly_linked_list_node(void *new_node_data)```)

### Basic List Modifications
- [X] Append new node to back (```struct node *append_singly_linked_list_node_to_back(struct node *head, void *new_node_data)```)
- [X] Append new node to front (```struct node *append_singly_linked_list_node_to_front(struct node *head, void *new_node_data)```)
- [X] Append new node after specific node (```struct node *append_singly_linked_list_node_after_node(struct node *head, void *new_node_data, struct node *selected_node)```)
- [ ] Append new node before specific node (```struct node *append_singly_linked_list_node_before_node(struct node *head, void *new_node_data, struct node *selected_node)```)
- [ ] Append new node after node containing specific data (```struct node *append_singly_linked_list_node_before_data(struct node *head, void *new_node_data, void *data)```)
- [ ] Append new node before node containing specific data (```struct node *append_singly_linked_list_node_after_data(struct node *head, void *new_node_data, void *data)```)
- [ ] Delete head node
- [ ] Delete tail node
- [ ] Delete node after specific node
- [ ] Delete node before specific node
- [ ] Delete node after node containing specific data
- [ ] Delete node before node containing specific data

### Advanced List Modifications
- [ ] Swap two nodes
- [ ] Swap two nodes containing specific data
- [ ] Reverse list
- [ ] Sort list using quick sort

### Freeing List
- [X] Free list (```void free_singly_linked_list(struct node *head)```)
