//====================================================================================================
//
//  File Name:   singly_linked_list_test.c
//  Author:      Christopher Priebe
//  Repository:  singly-linked-list
//  Date:        7/20/2022
//
//====================================================================================================

#include "../include/singly_linked_list_test.h"

//====================================================================================================
//
//  HELPER FUNCTIONS
//
//====================================================================================================

static void **create_test_array_from_int_array(int *test_values, size_t test_values_size)
{
    int i;
    int **int_data_pointer_array = malloc(sizeof(*int_data_pointer_array) * test_values_size);

    for (i = 0; i < test_values_size; i++)
    {
        int_data_pointer_array[i] = malloc(sizeof(*int_data_pointer_array[i]));
        *int_data_pointer_array[i] = test_values[i];
    }

    return ((void **)int_data_pointer_array);
}

static struct node *create_list_from_array(void **arr, size_t length)
{
    struct node *head = NULL;

    if ((arr != NULL) & (length > 0))
    {
        head = malloc(sizeof(*head));
        head->data = arr[0];
        head->next = NULL;

        int i;
        struct node *prev_node = head;
        struct node *curr_node = head->next;

        for (i = 1; i < length; i++)
        {
            curr_node = malloc(sizeof(*curr_node));
            curr_node->data = arr[i];
            curr_node->next = NULL;
            prev_node->next = curr_node;

            prev_node = curr_node;
        }
    }

    return (head);
}

static void free_test_array(void **arr, size_t length)
{
    int i;
    for (i = 0; i < length; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

static void free_list(struct node *head)
{
    struct node *curr_node;

    while (head != NULL)
    {
        curr_node = head;
        head = head->next;
        free(curr_node);
    }
}

static int compare_int_ascending(const void *i_v_1, const void *i_v_2)
{
    int i_1 = *((int *)i_v_1);
    int i_2 = *((int *)i_v_2);

    return (i_1 - i_2);
}

/*
static int compare_int_descending(const void *i_v_1, const void *i_v_2)
{
    int i_1 = *((int *)i_v_1);
    int i_2 = *((int *)i_v_2);

    return (i_2 - i_1);
}
*/

//====================================================================================================
//
//  GETTING LIST PROPERTIES
//
//====================================================================================================

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
    free(head);
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
//  test_is_data_in_singly_linked_list_identifies_value_not_found_in_empty_list,
//  test_is_data_in_singly_linked_list_identifies_value_found_in_single_node_list,
//  test_is_data_in_singly_linked_list_identifies_value_not_found_in_single_node_list,
//  test_is_data_in_singly_linked_list_identifies_value_not_found_in_length_four_list,
//  test_is_data_in_singly_linked_list_identifies_value_found_in_length_four_list_with_unique_occurrence,
//  test_is_data_in_singly_linked_list_identifies_value_found_in_length_four_list_with_repeat_occurrence
//
//  The unit tests for is_data_in_singly_linked_list
//====================================================================================================

static void test_is_data_in_singly_linked_list_identifies_value_not_found_in_empty_list()
{
    // arrange
    int *test_values = NULL;
    int test_values_size = 0;

    void **data_pointer_array = create_test_array_from_int_array(test_values, test_values_size);
    struct node *head = create_list_from_array(data_pointer_array, test_values_size);

    int *int_value_pointer = malloc(sizeof(*int_value_pointer));
    *int_value_pointer = 5;

    // act
    int position = is_data_in_singly_linked_list(head, (void *)int_value_pointer, compare_int_ascending);

    // assert
    assert(position == -1);

    // teardown
    free_list(head);
    free_test_array(data_pointer_array, test_values_size);
    free(int_value_pointer);
}

static void test_is_data_in_singly_linked_list_identifies_value_found_in_single_node_list()
{
    // arrange
    int test_values[] = {15};
    int test_values_size = 1;

    void **data_pointer_array = create_test_array_from_int_array(test_values, test_values_size);
    struct node *head = create_list_from_array(data_pointer_array, test_values_size);

    int *int_value_pointer = malloc(sizeof(*int_value_pointer));
    *int_value_pointer = 15;

    // act
    int position = is_data_in_singly_linked_list(head, (void *)int_value_pointer, compare_int_ascending);

    // assert
    assert(position == 0);

    // teardown
    free_list(head);
    free_test_array(data_pointer_array, test_values_size);
    free(int_value_pointer);
}

static void test_is_data_in_singly_linked_list_identifies_value_not_found_in_single_node_list()
{
    // arrange
    int test_values[] = {25};
    int test_values_size = 1;

    void **data_pointer_array = create_test_array_from_int_array(test_values, test_values_size);
    struct node *head = create_list_from_array(data_pointer_array, test_values_size);

    int *int_value_pointer = malloc(sizeof(*int_value_pointer));
    *int_value_pointer = 15;

    // act
    int position = is_data_in_singly_linked_list(head, (void *)int_value_pointer, compare_int_ascending);

    // assert
    assert(position == -1);

    // teardown
    free_list(head);
    free_test_array(data_pointer_array, test_values_size);
    free(int_value_pointer);
}

static void test_is_data_in_singly_linked_list_identifies_value_not_found_in_length_four_list()
{
    // arrange
    int test_values[] = {25, 93, 104, 20};
    int test_values_size = 4;

    void **data_pointer_array = create_test_array_from_int_array(test_values, test_values_size);
    struct node *head = create_list_from_array(data_pointer_array, test_values_size);

    int *int_value_pointer = malloc(sizeof(*int_value_pointer));
    *int_value_pointer = 8;

    // act
    int position = is_data_in_singly_linked_list(head, (void *)int_value_pointer, compare_int_ascending);

    // assert
    assert(position == -1);

    // teardown
    free_list(head);
    free_test_array(data_pointer_array, test_values_size);
    free(int_value_pointer);
}

static void test_is_data_in_singly_linked_list_identifies_value_found_in_length_four_list_with_unique_occurrence()
{
    // arrange
    int test_values[] = {25, 93, 104, 20};
    int test_values_size = 4;

   void **data_pointer_array = create_test_array_from_int_array(test_values, test_values_size);
    struct node *head = create_list_from_array(data_pointer_array, test_values_size);

    int *int_value_pointer = malloc(sizeof(*int_value_pointer));
    *int_value_pointer = 104;

    // act
    int position = is_data_in_singly_linked_list(head, (void *)int_value_pointer, compare_int_ascending);

    // assert
    assert(position == 2);

    // teardown
    free_list(head);
    free_test_array(data_pointer_array, test_values_size);
    free(int_value_pointer);
}

static void test_is_data_in_singly_linked_list_identifies_value_found_in_length_four_list_with_repeat_occurrence()
{
    // arrange
    int test_values[] = {25, 83, 83, 83};
    int test_values_size = 4;

    void **data_pointer_array = create_test_array_from_int_array(test_values, test_values_size);
    struct node *head = create_list_from_array(data_pointer_array, test_values_size);

    int *int_value_pointer = malloc(sizeof(*int_value_pointer));
    *int_value_pointer = 83;

    // act
    int position = is_data_in_singly_linked_list(head, (void *)int_value_pointer, compare_int_ascending);

    // assert
    assert(position == 1);

    // teardown
    free_list(head);
    free_test_array(data_pointer_array, test_values_size);
    free(int_value_pointer);
}

//====================================================================================================
//  test_get_singly_linked_list_length_of_empty_list_correctly,
//  test_get_singly_linked_list_length_of_single_node_list_correctly,
//  test_get_singly_linked_list_length_of_length_two_list_correctly,
//  test_get_singly_linked_list_length_of_length_three_list_correctly
//
//  The unit tests for get_singly_linked_list_length
//====================================================================================================

static void test_get_singly_linked_list_length_of_empty_list_correctly()
{
    // arrange
    struct node *head = NULL;

    // act
    size_t length = get_singly_linked_list_length(head);

    // assert
    assert(length == 0);

    // teardown
}

static void test_get_singly_linked_list_length_of_single_node_list_correctly()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    head->next = NULL;

    // act
    size_t length = get_singly_linked_list_length(head);

    // assert
    assert(length == 1);

    // teardown
    free(head);
}

static void test_get_singly_linked_list_length_of_length_two_list_correctly()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    struct node *tail = malloc(sizeof(*tail));

    head->next = tail;
    tail->next = NULL;

    // act
    size_t length = get_singly_linked_list_length(head);

    // assert
    assert(length == 2);

    // teardown
    free(head);
    free(tail);
}

static void test_get_singly_linked_list_length_of_length_three_list_correctly()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    struct node *middle = malloc(sizeof(*middle));
    struct node *tail = malloc(sizeof(*tail));

    head->next = middle;
    middle->next = tail;
    tail->next = NULL;

    // act
    size_t length = get_singly_linked_list_length(head);

    // assert
    assert(length == 3);

    // teardown
    free(head);
    free(middle);
    free(tail);
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
//  test_create_new_singly_linked_list_node_with_unknown_data,
//  test_create_new_singly_linked_list_node_with_signed_int_data
//
//  The unit tests for create_new_singly_linked_list_node
//====================================================================================================

static void test_create_new_singly_linked_list_node_with_unknown_data()
{
    // arrange
    void *data = NULL;

    // act
    struct node *head = create_new_singly_linked_list_node(data);

    // assert
    assert(head != NULL);
    assert(head->next == NULL);
    assert(head->data == NULL);

    // teardown
    free(head);
}

static void test_create_new_singly_linked_list_node_with_signed_int_data()
{
    // arrange
    int *data = malloc(sizeof(*data));
    *data = 25;

    // act
    struct node *head = create_new_singly_linked_list_node((void *)data);

    // assert
    assert(head != NULL);
    assert(head->next == NULL);
    assert(*((int *)head->data) == 25);

    // teardown
    free(head);
    free(data);
}

//====================================================================================================
//
//  BASIC LIST MODIFICATIONS
//
//====================================================================================================

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

    head->data = (void *)data;
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

    head->data = (void *)data;
    head->next = second;
    second->data = (void *)data;
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
//  test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_front,
//  test_create_length_two_list_from_length_one_list_using_append_singly_linked_list_node_to_front,
//
//  The unit tests for append_singly_linked_list_node_to_front
//====================================================================================================

static void test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_front()
{
    // arrange
    struct node *original_head = NULL;
    int *data = malloc(sizeof(*data));

    // act
    struct node *head_after_append = append_singly_linked_list_node_to_front(original_head, (void *)data);

    // assert
    assert(head_after_append != original_head);
    assert(head_after_append->next == NULL);
    assert(head_after_append->data == data);

    // teardown
    free(head_after_append);
    free(data);
}

static void test_create_length_two_list_from_length_one_list_using_append_singly_linked_list_node_to_front()
{
    // arrange
    struct node *original_head = malloc(sizeof(*original_head));
    int *data = malloc(sizeof(*data));

    original_head->data = (void *)data;
    original_head->next = NULL;

    // act
    struct node *head_after_append = append_singly_linked_list_node_to_front(original_head, (void *)data);

    // assert
    assert(head_after_append != original_head);
    assert(head_after_append->next == original_head);
    assert(head_after_append->data = data);
    assert(original_head->next == NULL);
    assert(original_head->data = data);

    // teardown
    free(head_after_append->next);
    free(head_after_append);
    free(data);
}

//====================================================================================================
//  test_free_singly_linked_list_with_empty_list,
//  test_free_singly_linked_list_with_single_node_list,
//  test_free_singly_linked_list_with_length_four_list
//
//  The unit tests for free_singly_linked_list
//====================================================================================================

static void test_free_singly_linked_list_with_empty_list()
{
    // arrange
    struct node *head = NULL;

    // act
    free_singly_linked_list(head);

    // assert
    assert(1);

    // teardown
}

static void test_free_singly_linked_list_with_single_node_list()
{
    // arrange
    struct node *head = malloc(sizeof(*head));
    head->next = NULL;

    // act
    free_singly_linked_list(head);

    // assert
    assert(1);

    // teardown
}

static void test_free_singly_linked_list_with_length_four_list()
{
    // arrange
    int test_values[] = {3242, 43, 56, 234};
    int test_values_size = 4;

    void **data_pointer_array = create_test_array_from_int_array(test_values, test_values_size);
    struct node *head = create_list_from_array(data_pointer_array, test_values_size);

    // act
    free_singly_linked_list(head);

    // assert
    assert(1);

    // teardown
    free_test_array(data_pointer_array, test_values_size);
}

//====================================================================================================
//  main Function
//====================================================================================================

int main(void)
{
    // GETTING LIST PROPERTIES

    // is_singly_linked_list_empty
    test_is_singly_linked_list_empty_identifies_empty_list_correctly();
    test_is_singly_linked_list_emtpy_identifies_non_empty_list_correctly();

    // is_data_in_singly_linked_list
    test_is_data_in_singly_linked_list_identifies_value_not_found_in_empty_list();
    test_is_data_in_singly_linked_list_identifies_value_found_in_single_node_list();
    test_is_data_in_singly_linked_list_identifies_value_not_found_in_single_node_list();
    test_is_data_in_singly_linked_list_identifies_value_not_found_in_length_four_list();
    test_is_data_in_singly_linked_list_identifies_value_found_in_length_four_list_with_unique_occurrence();
    test_is_data_in_singly_linked_list_identifies_value_found_in_length_four_list_with_repeat_occurrence();

    // get_singly_linked_list_length
    test_get_singly_linked_list_length_of_empty_list_correctly();
    test_get_singly_linked_list_length_of_single_node_list_correctly();
    test_get_singly_linked_list_length_of_length_two_list_correctly();
    test_get_singly_linked_list_length_of_length_three_list_correctly();

    // SETTING LIST PROPERTIES

    // BASIC NODE MODIFICATIONS

    // create_new_singly_linked_list_node
    test_create_new_singly_linked_list_node_with_unknown_data();
    test_create_new_singly_linked_list_node_with_signed_int_data();

    // BASIC LIST MODIFICATIONS

    // get_singly_linked_list_tail_node
    test_get_singly_linked_list_tail_node_from_empty_list_correctly();
    test_get_singly_linked_list_tail_node_from_single_node_list_correctly();
    test_get_singly_linked_list_tail_node_from_length_two_list_correctly();
    test_get_singly_linked_list_tail_node_from_length_three_list_correctly();

    // append_singly_linked_list_node_to_back
    test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_back();
    test_create_length_two_list_from_length_one_list_using_append_singly_linked_list_node_to_back();
    test_create_length_three_list_length_two_list_using_append_singly_linked_list_node_to_back();

    // append_singly_linked_list_node_to_front
    test_create_single_node_list_from_empty_list_using_append_singly_linked_list_node_to_front();
    test_create_length_two_list_from_length_one_list_using_append_singly_linked_list_node_to_front();

    // FREEING LIST

    // free_singly_linked_list
    test_free_singly_linked_list_with_empty_list();
    test_free_singly_linked_list_with_single_node_list();
    test_free_singly_linked_list_with_length_four_list();

    return (0);
}