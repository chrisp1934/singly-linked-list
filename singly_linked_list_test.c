#include <assert.h>

#include "singly_linked_list.h"

//====================================================================================================
//  test_is_singly_linked_list_empty_identifies_empty_list_correctly,
//  test_is_singly_linked_list_emtpy_identifies_non_empty_list_correctly
//
//  The unit tests for is_singly_linked_list_empty
//====================================================================================================

static void test_is_singly_linked_list_empty_identifies_empty_list_correctly()
{
    struct node *head = malloc(sizeof(*head));
    assert(!is_singly_linked_list_empty(head));
}

static void test_is_singly_linked_list_emtpy_identifies_non_empty_list_correctly()
{
    struct node *head = NULL;
    assert(is_singly_linked_list_empty(head));
}

//====================================================================================================
//  test_get_singly_linked_list_tail_node_from_empty_list_correctly,
//  test_get_singly_linked_list_tail_node_from_single_node_list_correctly,
//  test_get_singly_linked_list_tail_node_from_length_two_list_correctly,
//  test_get_singly_linked_list_tail_node_from_length_three_list_correctly
//
//  The unit tests for get_singly_linked_list_tail_node
//====================================================================================================

static void test_get_singly_linked_list_tail_node_from_empty_list_correctly()
{
    struct node *head = NULL;
    assert(get_singly_linked_list_tail_node(head) == NULL);
}

static void test_get_singly_linked_list_tail_node_from_single_node_list_correctly()
{
    struct node *head = malloc(sizeof(*head));
    head->next = NULL;
    assert(get_singly_linked_list_tail_node(head) == head);

    free(head);
}

static void test_get_singly_linked_list_tail_node_from_length_two_list_correctly()
{
    struct node *head = malloc(sizeof(*head));
    struct node *tail = malloc(sizeof(*tail));
    head->next = tail;
    tail->next = NULL;
    assert(get_singly_linked_list_tail_node(head) == tail);

    free(head);
    free(tail);
}

static void test_get_singly_linked_list_tail_node_from_length_three_list_correctly()
{
    struct node *head = malloc(sizeof(*head));
    struct node *middle = malloc(sizeof(*middle));
    struct node *tail = malloc(sizeof(*tail));
    head->next = middle;
    middle->next = tail;
    tail->next = NULL;
    assert(get_singly_linked_list_tail_node(head) == tail);

    free(head);
    free(middle);
    free(tail);
}

//====================================================================================================
//  test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_back,
//  test_create_length_two_list_from_empty_list_using_append_singly_linked_list_node_to_back,
//  test_create_length_three_list_from_empty_list_using_append_singly_linked_list_node_to_back
//
//  The unit tests for append_singly_linked_list_node_to_back
//====================================================================================================

static void test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_back()
{
    struct node *head = NULL;
    int *data = malloc(sizeof(*data));

    head = append_singly_linked_list_node_to_back(head, (void *)data);

    assert(head != NULL);
    assert(head->next == NULL);
    assert(head->data != NULL);

    free(head);
    free(data);
}

static void test_create_length_two_list_from_empty_list_using_append_singly_linked_list_node_to_back()
{
    struct node *head = NULL;
    int *data = malloc(sizeof(*data));

    head = append_singly_linked_list_node_to_back(head, (void *)data);
    assert(append_singly_linked_list_node_to_back(head, (void *)data) == head);

    assert(head != NULL);
    assert(head->next != NULL);
    assert(head->data != NULL);
    assert(head->next->data != NULL);
    assert(head->next->next == NULL);

    free(head->next);
    free(head);
    free(data);
}

static void test_create_length_three_list_from_empty_list_using_append_singly_linked_list_node_to_back()
{
    struct node *head = NULL;
    int *data = malloc(sizeof(*data));

    head = append_singly_linked_list_node_to_back(head, (void *)data);
    assert(append_singly_linked_list_node_to_back(head, (void *)data) == head);
    assert(append_singly_linked_list_node_to_back(head, (void *)data) == head);

    assert(head != NULL);
    assert(head->next != NULL);
    assert(head->data != NULL);
    assert(head->next->data != NULL);
    assert(head->next->next != NULL);
    assert(head->next->next->data != NULL);
    assert(head->next->next->next == NULL);

    free(head->next->next);
    free(head->next);
    free(head);
    free(data);
}

//====================================================================================================
//  main Function
//====================================================================================================

int main(void)
{
    // is_singly_linked_list_empty
    test_is_singly_linked_list_empty_identifies_empty_list_correctly();
    test_is_singly_linked_list_emtpy_identifies_non_empty_list_correctly();

    // get_singly_linked_list_tail_node
    test_get_singly_linked_list_tail_node_from_empty_list_correctly();
    test_get_singly_linked_list_tail_node_from_single_node_list_correctly();
    test_get_singly_linked_list_tail_node_from_length_two_list_correctly();
    test_get_singly_linked_list_tail_node_from_length_three_list_correctly();

    // append_singly_linked_list_node_to_back
    test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_back();
    test_create_length_two_list_from_empty_list_using_append_singly_linked_list_node_to_back();
    test_create_length_three_list_from_empty_list_using_append_singly_linked_list_node_to_back();

    return (0);
}