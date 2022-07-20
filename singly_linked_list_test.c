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
    // arrange
    struct node *head = malloc(sizeof(*head));

    // act
    int is_empty = is_singly_linked_list_empty(head);

    // assert
    assert(!is_empty);

    // teardown
}

static void test_is_singly_linked_list_emtpy_identifies_non_empty_list_correctly()
{
    // arrange
    struct node *head = NULL;

    // act
    int is_empty = is_singly_linked_list_empty(head);

    // assert
    assert(is_empty);

    // teardown
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
    // arrange
    struct node *head = NULL;

    // act
    struct node *tail = get_singly_linked_list_tail_node(head);
    
    // assert
    assert(tail == NULL);

    // teardown
}

static void test_get_singly_linked_list_tail_node_from_single_node_list_correctly()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    head->next = NULL;

    // act
    struct node *tail = get_singly_linked_list_tail_node(head);

    // assert
    assert(tail == head);

    // teardown
    free(head);
}

static void test_get_singly_linked_list_tail_node_from_length_two_list_correctly()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    struct node *tail = malloc(sizeof(*tail));

    head->next = tail;
    tail->next = NULL;

    // act
    struct node *gotten_tail = get_singly_linked_list_tail_node(head);

    // assert
    assert(gotten_tail == tail);

    // teardown
    free(head);
    free(tail);
}

static void test_get_singly_linked_list_tail_node_from_length_three_list_correctly()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    struct node *middle = malloc(sizeof(*middle));
    struct node *tail = malloc(sizeof(*tail));

    head->next = middle;
    middle->next = tail;
    tail->next = NULL;

    // act
    struct node *gotten_tail = get_singly_linked_list_tail_node(head);

    // assert
    assert(gotten_tail == tail);

    // teardown
    free(head);
    free(middle);
    free(tail);
}

//====================================================================================================
//  test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_back,
//  test_create_length_two_list_from_length_one_list_using_append_singly_linked_list_node_to_back,
//  test_create_length_three_list_length_two_list_using_append_singly_linked_list_node_to_back
//
//  The unit tests for append_singly_linked_list_node_to_back
//====================================================================================================

static void test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_back()
{
    // arrange
    struct node *original_head = NULL;
    int *data = malloc(sizeof(*data));

    // act
    struct node *head_after_append = append_singly_linked_list_node_to_back(original_head, (void *)data);

    // assert
    assert(head_after_append != original_head);
    assert(head_after_append->next == NULL);
    assert(head_after_append->data == data);

    // teardown
    free(head_after_append);
    free(data);
}

static void test_create_length_two_list_from_length_one_list_using_append_singly_linked_list_node_to_back()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    int *data = malloc(sizeof(*data));

    head->data = data;
    head->next = NULL;

    // act
    struct node *head_after_append = append_singly_linked_list_node_to_back(head, (void *)data);

    // assert
    assert(head_after_append == head);
    assert(head->next != NULL);
    assert(head->next->data == data);

    // teardown
    free(head->next);
    free(head);
    free(data);
}

static void test_create_length_three_list_length_two_list_using_append_singly_linked_list_node_to_back()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    struct node *second = malloc(sizeof(*second));
    int *data = malloc(sizeof(*data));

    head->data = data;
    head->next = second;
    second->data = data;
    second->next = NULL;

    // act
    struct node *head_after_append = append_singly_linked_list_node_to_back(head, (void *)data);

    // assert
    assert(head_after_append == head);
    assert(second->next != NULL);
    assert(second->next->data == data);

    // teardown
    free(second->next);
    free(second);
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
    test_create_length_two_list_from_length_one_list_using_append_singly_linked_list_node_to_back();
    test_create_length_three_list_length_two_list_using_append_singly_linked_list_node_to_back();

    return (0);
}