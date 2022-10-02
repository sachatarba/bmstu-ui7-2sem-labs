#include <check.h>
#include <stdlib.h>

#include "../inc/process.h"
#include "../inc/utils.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define OK 0

START_TEST(test_key_regular)
{
    int a_in[] = { 1, 2, 3, 4, 5, 6 };
    int a_res[] = { 2, 3, 4, 5 };

    int *pb = NULL;
    int *pe = NULL;

    key(a_in, a_in + sizeof(a_in) / sizeof(a_in[0]), &pb, &pe);

    ck_assert_mem_eq(pb, a_res, sizeof(a_res));
    free(pb);
}
END_TEST

START_TEST(test_key_two_mins)
{
    int a_in[] = { 1, 1, 3, 4, 5, 6 };
    int a_res[] = { 1, 3, 4, 5 };

    int *pb = NULL;
    int *pe = NULL;

    key(a_in, a_in + sizeof(a_in) / sizeof(a_in[0]), &pb, &pe);

    ck_assert_mem_eq(pb, a_res, sizeof(a_res));
    free(pb);
}
END_TEST

START_TEST(test_key_two_max)
{
    int a_in[] = { 1, 2, 3, 4, 6, 7 };
    int a_res[] = { 2, 3, 4, 6 };

    int *pb = NULL;
    int *pe = NULL;

    key(a_in, a_in + sizeof(a_in) / sizeof(a_in[0]), &pb, &pe);

    ck_assert_mem_eq(pb, a_res, sizeof(a_res));
    free(pb);
}
END_TEST

START_TEST(test_key_one)
{
    int a_in[] = { 1, 1, 1, 1, 1, 2 };
    int a_res[] = { 1, 1, 1, 1 };

    int *pb = NULL;
    int *pe = NULL;

    key(a_in, a_in + sizeof(a_in) / sizeof(a_in[0]), &pb, &pe);

    ck_assert_mem_eq(pb, a_res, sizeof(a_res));
    free(pb);
}
END_TEST

START_TEST(test_key_max_then_min)
{
    int a_in[] = { 7, 1, 1, 1, 1, -1 };
    int a_res[] = { 1, 1, 1, 1 };

    int *pb = NULL;
    int *pe = NULL;

    key(a_in, a_in + sizeof(a_in) / sizeof(a_in[0]), &pb, &pe);

    ck_assert_mem_eq(pb, a_res, sizeof(a_res));
    free(pb);
}
END_TEST

START_TEST(test_key_bad_ptrs)
{
    int *a_in = NULL;

    int *pb = NULL;
    int *pe = NULL;

    ck_assert_int_ne(key(a_in, a_in + 2 * sizeof(int), &pb, &pe), OK);
    free(pb);
}
END_TEST

START_TEST(test_key_pb_ge_pe)
{
    int a_in[] = { 0, 1, 1, 1, 1, 2 };

    int *pb = NULL;
    int *pe = NULL;

    ck_assert_int_ne(key(a_in + sizeof(a_in) / sizeof(a_in[0]), a_in, &pb, &pe), OK);
    free(pb);
}
END_TEST

START_TEST(test_key_no_data)
{
    int a_in[] = { 0, 1 };

    int *pb = NULL;
    int *pe = NULL;

    ck_assert_int_ne(key(a_in + sizeof(a_in) / sizeof(a_in[0]), a_in, &pb, &pe), OK);
    free(pb);
}
END_TEST

START_TEST(test_mysort_sorted_arr)
{
    int a_in[] = { 1, 2, 3, 4, 5, 6 };
    int a_res[] = { 1, 2, 3, 4, 5, 6 };


    mysort(a_in, sizeof(a_in) / sizeof(a_in[0]), sizeof(int), compare_int);

    ck_assert_mem_eq(a_in, a_res, sizeof(a_res));
}
END_TEST

START_TEST(test_mysort_unsorted_arr)
{
    int a_in[] = { 6, 5, 4, 3, 2, 1 };
    int a_res[] = { 1, 2, 3, 4, 5, 6 };


    mysort(a_in, sizeof(a_in) / sizeof(a_in[0]), sizeof(int), compare_int);

    ck_assert_mem_eq(a_in, a_res, sizeof(a_res));
}
END_TEST

START_TEST(test_mysort_random_arr)
{
    int a_in[] = { 4, 6, 2, 5, 1, 3 };
    int a_res[] = { 1, 2, 3, 4, 5, 6 };

    mysort(a_in, sizeof(a_in) / sizeof(a_in[0]), sizeof(int), compare_int);

    ck_assert_mem_eq(a_in, a_res, sizeof(a_res));
}
END_TEST

START_TEST(test_mysort_one_elm)
{
    int a_in[] = { 1 };
    int a_res[] = { 1 };

    mysort(a_in, sizeof(a_in) / sizeof(a_in[0]), sizeof(int), compare_int);

    ck_assert_mem_eq(a_in, a_res, sizeof(a_res));
}
END_TEST

Suite* calc_avg_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции calc_avg
    s = suite_create("key");
    
    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове calc_avg
    tc_neg = tcase_create("negatives");
    // // Добавим в tc_neg соответствующие функции-тесты
    tcase_add_test(tc_neg, test_key_bad_ptrs);
    tcase_add_test(tc_neg, test_key_no_data);
    tcase_add_test(tc_neg, test_key_pb_ge_pe);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);
    
    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // calc_avg для корректных параметров
    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_key_regular);
    tcase_add_test(tc_pos, test_key_two_mins);
    tcase_add_test(tc_pos, test_key_two_max);
    tcase_add_test(tc_pos, test_key_one);
    tcase_add_test(tc_pos, test_key_max_then_min);
    tcase_add_test(tc_pos, test_mysort_sorted_arr);
    tcase_add_test(tc_pos, test_mysort_unsorted_arr);
    tcase_add_test(tc_pos, test_mysort_random_arr);
    tcase_add_test(tc_pos, test_mysort_one_elm);
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
    
