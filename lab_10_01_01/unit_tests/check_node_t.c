#include <check.h>
#include <stdlib.h>

#include "../inc/node_t.h"
#include "../inc/comparator.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define OK 0

Suite* tests(void);

int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = tests();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

START_TEST(test_sorted_insert_sorted)
{
    int a[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    node_t *head = malloc(sizeof(node_t));
    
    head->data = a;
    head->next = NULL;

    for (int i = 1; i < (int) (sizeof(a) / sizeof(a[0])); i++)
    {
        node_t *new = malloc(sizeof(node_t));
        new->data = a + i;
        new->next = NULL;
        sorted_insert(&head, new, copmare_int);
    }

    int data = 0;
    int correct = 1;

    for (int i = 0; i < 11; i++)
    {
        data = *((int *) pop_back(&head));

        if (data != 10 - i)
        {
            correct = 0;
        }
    }
    
    ck_assert_int_eq(correct, 1);
}
END_TEST

START_TEST(test_sorted_insert_unsorted)
{
    int a[11] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

    node_t *head = malloc(sizeof(node_t));
    
    head->data = a;
    head->next = NULL;

    for (int i = 1; i < (int) (sizeof(a) / sizeof(a[0])); i++)
    {
        node_t *new = malloc(sizeof(node_t));
        new->data = a + i;
        new->next = NULL;
        sorted_insert(&head, new, copmare_int);
    }

    int data = 0;
    int correct = 1;

    for (int i = 0; i < 11; i++)
    {
        data = *((int *) pop_back(&head));

        if (data != 10 - i)
        {
            correct = 0;
        }
    }
    
    ck_assert_int_eq(correct, 1);
}
END_TEST

START_TEST(test_sorted_insert_two_elms)
{
    int a[2] = { 10, 9 };

    node_t *head = malloc(sizeof(node_t));
    
    head->data = a;
    head->next = NULL;

    for (int i = 1; i < (int) (sizeof(a) / sizeof(a[0])); i++)
    {
        node_t *new = malloc(sizeof(node_t));
        new->data = a + i;
        new->next = NULL;
        sorted_insert(&head, new, copmare_int);
    }

    int data = 0;
    int correct = 1;

    for (int i = 0; i < 2; i++)
    {
        data = *((int *) pop_back(&head));

        if (data != 10 - i)
        {
            correct = 0;
        }
    }
    
    ck_assert_int_eq(correct, 1);
}
END_TEST

START_TEST(test_pop_back_regular)
{
    int a[1] = { 10 };

    node_t *head = malloc(sizeof(node_t));
    
    head->data = a;
    head->next = NULL;

    int data = 0;
    data = *((int *) pop_back(&head));
    
    ck_assert_int_eq(data, 10);
}
END_TEST

START_TEST(test_compare_int_gt)
{
    int a = 1, b = 0;
    int res = copmare_int(&a, &b);

    ck_assert_int_gt(res, 0);
}
END_TEST

START_TEST(test_compare_int_lt)
{
    int a = 0, b = 1;
    int res = copmare_int(&a, &b);

    ck_assert_int_lt(res, 0);
}
END_TEST

START_TEST(test_compare_int_eq)
{
    int a = 3, b = 3;
    int res = copmare_int(&a, &b);

    ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(test_find_regular)
{
    int a[11] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };

    node_t *head = malloc(sizeof(node_t));
    
    head->data = a;
    head->next = NULL;

    for (int i = 1; i < (int) (sizeof(a) / sizeof(a[0])); i++)
    {
        node_t *new = malloc(sizeof(node_t));
        new->data = a + i;
        new->next = NULL;
        sorted_insert(&head, new, copmare_int);
    }

    int data_res = 5;

    node_t *res = find(head, &data_res, copmare_int);
    
    ck_assert_int_eq(*((int *) res->data), data_res);

    for (int i = 0; i < 11; i++)
    {
        pop_back(&head);
    }
    
}
END_TEST


Suite* tests(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_sorted_insert_sorted);
    tcase_add_test(tc_pos, test_sorted_insert_unsorted);
    tcase_add_test(tc_pos, test_sorted_insert_two_elms);
    tcase_add_test(tc_pos, test_pop_back_regular);
    tcase_add_test(tc_pos, test_compare_int_eq);
    tcase_add_test(tc_pos, test_compare_int_gt);
    tcase_add_test(tc_pos, test_compare_int_lt);
    tcase_add_test(tc_pos, test_find_regular);
    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
