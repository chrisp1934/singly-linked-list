//====================================================================================================
//
//  File Name:   singly_linked_list.c
//  Author:      Christopher Priebe
//  Repository:  singly-linked-list
//  Date:        7/20/2022
//
//====================================================================================================

#include "../include/singly_linked_list.h"

//====================================================================================================
//
//  HELPER FUNCTIONS
//
//====================================================================================================

static void sllh_set_new_node_fields(struct node *n, void *data)
{
    n->data = data;
    n->next = NULL;
}

static struct node *sllh_get_node(struct node *head, struct node *selected_node)
{
    struct node *curr_node = head;
    while ((curr_node != NULL) && (curr_node != selected_node))
    {
        curr_node = curr_node->next;
    }

    return (curr_node);
}

static void sllh_append_node(struct node *n, struct node *new_n)
{
    if ((n != NULL) && (new_n != NULL))
    {
        new_n->next = n->next;
        n->next = new_n;
    }
}

static void sllh_create_new_node_and_append_node(struct node *n, void *new_node_data)
{
    struct node *new_node = create_new_singly_linked_list_node(new_node_data);
    sllh_append_node(n, new_node);
}

static void sllh_append_singly_linked_list_node_after_node_if_both_head_and_selected_node_not_null(struct node *head, void *new_node_data, struct node *selected_node)
{
    struct node *found_node = sllh_get_node(head, selected_node);
    if (found_node != NULL)
    {
        sllh_create_new_node_and_append_node(found_node, new_node_data);
    }
}

static int sllh_is_value_equal(const void *v_p_1, const void *v_p_2, int (*compare)(const void *, const void *))
{
    return (compare(v_p_1, v_p_2) == 0);
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

int is_data_in_singly_linked_list(struct node *head, const void *data, int (*compare)(const void *, const void *))
{
    int current_position = 0;
    int data_position = -1;

    while (head != NULL)
    {
        if (sllh_is_value_equal(head->data, data, compare))
        {
            head = NULL;
            data_position = current_position;
        }
        else
        {
            head = head->next;
            current_position++;
        }
    }

    return (data_position);
}

size_t get_singly_linked_list_length_iteratively(struct node *head)
{
    size_t length = 0;

    while (head != NULL)
    {
        length++;
        head = head->next;
    }

    return (length);
}

size_t get_singly_linked_list_length_recursively(struct node *head)
{
    if (head == NULL)
    {
        return (0);
    }
    else
    {
        return (get_singly_linked_list_length_recursively(head->next) + 1);
    }
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
//  BASIC NODE MODIFICATIONS
//
//====================================================================================================

struct node *create_new_singly_linked_list_node(void *new_node_data)
{
    struct node *n = malloc(sizeof(*n));
    sllh_set_new_node_fields(n, new_node_data);

    return (n);
}

//====================================================================================================
//
//  BASIC LIST MODIFICATIONS
//
//====================================================================================================

struct node *append_singly_linked_list_node_to_back(struct node *head, void *new_node_data)
{
    if (is_singly_linked_list_empty(head))
    {
        head = create_new_singly_linked_list_node(new_node_data);
    }
    else
    {
        struct node *tail = get_singly_linked_list_tail_node(head);
        tail->next = create_new_singly_linked_list_node(new_node_data);
    }

    return (head);
}

struct node *append_singly_linked_list_node_to_front(struct node *head, void *new_node_data)
{
    if (is_singly_linked_list_empty(head))
    {
        head = create_new_singly_linked_list_node(new_node_data);
    }
    else
    {
        struct node *new_node = create_new_singly_linked_list_node(new_node_data);
        new_node->next = head;
        head = new_node;
    }

    return (head);
}

struct node *append_singly_linked_list_node_after_node(struct node *head, void *new_node_data, struct node *selected_node)
{
    if ((head == NULL) && (selected_node == NULL))
    {
        head = create_new_singly_linked_list_node(new_node_data);
    }
    else
    {
        sllh_append_singly_linked_list_node_after_node_if_both_head_and_selected_node_not_null(head, new_node_data, selected_node);
    }

    return (head);
}

//====================================================================================================
//
//  FREEING LIST
//
//====================================================================================================

void free_singly_linked_list(struct node *head)
{
    struct node *curr_node;

    while (head != NULL)
    {
        curr_node = head;
        head = head->next;
        free(curr_node);
    }
}