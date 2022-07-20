#include "singly_linked_list.h"

//====================================================================================================
//
//  HELPER FUNCTIONS
//
//====================================================================================================

static void set_new_node_fields(struct node *n, void *data)
{
    n->data = data;
    n->next = NULL;
}

//====================================================================================================
//
//  GETTING LIST PROPERTIES
//
//====================================================================================================

int is_singly_linked_list_empty(struct node *head)
{
    return (head == NULL);
}

int get_singly_linked_list_length(struct node *head)
{
    int length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return (length);
}

struct node *get_singly_linked_list_tail_node(struct node *head)
{
    if (!is_singly_linked_list_empty(head))
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
    }

    return (head);
}

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

struct node *create_new_singly_linked_list_node(void *data)
{
    struct node *n = malloc(sizeof(*n));
    set_new_node_fields(n, data);

    return (n);
}

//====================================================================================================
//
//  BASIC LIST MODIFICATIONS
//
//====================================================================================================

struct node *append_singly_linked_list_node_to_back(struct node *head, void *data)
{
    if (is_singly_linked_list_empty(head))
    {
        head = create_new_singly_linked_list_node(data);
    }
    else
    {
        struct node *tail = get_singly_linked_list_tail_node(head);
        tail->next = create_new_singly_linked_list_node(data);
    }

    return (head);
}

struct node *append_singly_linked_list_node_to_front(struct node *head, void *data)
{
    if (is_singly_linked_list_empty(head))
    {
        head = create_new_singly_linked_list_node(data);
    }
    else
    {
        struct node *new_node = create_new_singly_linked_list_node(data);
        new_node->next = head;
        head = new_node;
    }

    return (head);
}