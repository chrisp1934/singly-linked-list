#include "singly_linked_list.h"

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

static void set_new_node_fields(struct node *n, void *data)
{
    n->data = data;
    n->next = NULL;
}

struct node *append_singly_linked_list_node_to_back(struct node *head, void *data)
{
    if (is_singly_linked_list_empty(head))
    {
        head = malloc(sizeof(*head));
        set_new_node_fields(head, data);
    }
    else
    {
        struct node *tail = get_singly_linked_list_tail_node(head);
        tail->next = malloc(sizeof(*(tail->next)));
        set_new_node_fields(tail->next, data);
    }

    return (head);
}