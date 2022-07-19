#include "singly_linked_list.h"

int is_singly_linked_list_empty(struct node *head)
{
    return (head == NULL);
}

struct node *get_singly_linked_list_tail_node(struct node *head)
{
    if (head != NULL)
    {
        while (head->next != NULL)
        {
            head = head->next;
        }
    }

    return (head);
}

struct node *append_singly_linked_list_node_to_back(struct node *head, void *data)
{
    if (is_singly_linked_list_empty(head))
    {
        head = malloc(sizeof(*head));
        head->data = data;
        head->next = NULL;
    }
    else
    {
        struct node *tail = get_singly_linked_list_tail_node(head);
        tail->next = malloc(sizeof(*(tail->next)));
        tail->next->data = data;
        tail->next->next = NULL;
    }

    return (head);
}