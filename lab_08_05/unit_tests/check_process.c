#include <check.h>
#include <stdlib.h>

#include "../inc/process.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define OK 0

START_TEST(test_find_max_1)
{
    long long arr[] = { 1, 2, 3, 4, 5 };
    long long max = find_max(arr, sizeof(arr) / sizeof(arr[0]));
    long long real_max = 5;

    ck_assert_mem_eq(&max, &real_max, sizeof(max));
}
END_TEST

START_TEST(test_find_max_2)
{
    long long arr[] = { 10, 2, 2, 2, 5, 6 };
    long long max = find_max(arr, sizeof(arr) / sizeof(arr[0]));
    long long real_max = 10;

    ck_assert_mem_eq(&max, &real_max, sizeof(max));
}
END_TEST

START_TEST(test_find_max_of_rows_1)
{
    matr_t a;
    create_matr(&a, 5, 5);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            a.body[i][j] = i + j; 
        }
    }

    long long *arr = malloc(a.cols * sizeof(long long));

    find_max_of_rows(&a, arr);

    long long arr_real[] = { 4, 5, 6, 7, 8 };

    ck_assert_mem_eq(arr, arr_real, sizeof(arr_real) / sizeof(arr_real[0]));

    free_matr(&a);
    free(arr);

}
END_TEST

START_TEST(test_find_max_of_rows_2)
{
    matr_t a;
    create_matr(&a, 5, 5);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            a.body[i][j] = a.rows - i + j; 
        }
    }

    long long *arr = malloc(a.cols * sizeof(long long));

    find_max_of_rows(&a, arr);

    long long arr_real[] = { 9, 8, 7, 6, 5 };

    ck_assert_mem_eq(arr, arr_real, sizeof(arr_real) / sizeof(arr_real[0]));

    free_matr(&a);
    free(arr);
}
END_TEST

START_TEST(test_geometric_mean_1)
{
    matr_t a;
    create_matr(&a, 3, 3);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            a.body[i][j] = i + j; 
        }
    }

    long long *arr = malloc(a.cols * sizeof(long long));

    geometric_mean_of_cols(&a, arr);

    long long arr_real[] = { 0, 1, 2 };

    ck_assert_mem_eq(arr, arr_real, sizeof(arr_real) / sizeof(arr_real[0]));

    free_matr(&a);
    free(arr);
}
END_TEST

START_TEST(test_geometric_mean_2)
{
    matr_t a;
    create_matr(&a, 3, 5);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            a.body[i][j] = i + j; 
        }
    }

    long long *arr = malloc(a.cols * sizeof(long long));

    geometric_mean_of_cols(&a, arr);

    long long arr_real[] = { 0, 1, 2, 3, 4 };

    ck_assert_mem_eq(arr, arr_real, sizeof(arr_real) / sizeof(arr_real[0]));

    free_matr(&a);
    free(arr);
}
END_TEST

START_TEST(test_geometric_mean_3)
{
    matr_t a;
    create_matr(&a, 3, 6);

    for (size_t i = 0; i < a.rows; ++i)
    {
        for (size_t j = 0; j < a.cols; ++j)
        {
            a.body[i][j] = i + j; 
        }
    }

    long long *arr = malloc(a.cols * sizeof(long long));

    geometric_mean_of_cols(&a, arr);

    long long arr_real[] = { 0, 1, 2, 3, 4, 5 };

    ck_assert_mem_eq(arr, arr_real, sizeof(arr_real) / sizeof(arr_real[0]));

    free_matr(&a);
    free(arr);
}
END_TEST


Suite* calc_avg_suite(void)
{
    Suite *s;
    // TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции calc_avg
    s = suite_create("key");
    
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_find_max_1);
    tcase_add_test(tc_pos, test_find_max_of_rows_1);
    tcase_add_test(tc_pos, test_find_max_of_rows_2);
    tcase_add_test(tc_pos, test_find_max_2);
    tcase_add_test(tc_pos, test_geometric_mean_1);
    tcase_add_test(tc_pos, test_geometric_mean_2);
    tcase_add_test(tc_pos, test_geometric_mean_3);
    // tcase_add_test(tc_pos, test_mysort_random_arr);
    // tcase_add_test(tc_pos, test_mysort_one_elm);
    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}


int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = calc_avg_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
    
