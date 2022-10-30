#include <check.h>
#include <stdlib.h>

#include "../inc/utils.h"

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

START_TEST(test_copy_string_regular)
{
    char s_in[] = "aaaaaoooooo";
    char s_res[] = "aaaaaoooooo";
    char *s_cpy = NULL;

    copy_string(&s_cpy, s_in);

    ck_assert_mem_eq(s_cpy, s_res, sizeof(s_res));
    free(s_cpy);
}
END_TEST

START_TEST(test_copy_string_empty)
{
    char s_in[] = "";
    char s_res[] = "";
    char *s_cpy = NULL;

    copy_string(&s_cpy, s_in);

    ck_assert_mem_eq(s_cpy, s_res, sizeof(s_res));
    free(s_cpy);
}
END_TEST

START_TEST(test_copy_string_big_string)
{
    char s_in[] = "aaaaaooooooaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char s_res[] = "aaaaaooooooaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char *s_cpy = NULL;

    copy_string(&s_cpy, s_in);

    ck_assert_mem_eq(s_cpy, s_res, sizeof(s_res));
    free(s_cpy);
}
END_TEST

START_TEST(test_copy_string_with_spaces)
{
    char s_in[] = "aakakakk aakkeoafeojape aefiaeoifhei      eajfianef     ";
    char s_res[] = "aakakakk aakkeoafeojape aefiaeoifhei      eajfianef     ";
    char *s_cpy = NULL;

    copy_string(&s_cpy, s_in);

    ck_assert_mem_eq(s_cpy, s_res, sizeof(s_res));
    free(s_cpy);
}
END_TEST

START_TEST(test_is_string_whitespace_all_spaces)
{
    char s_in[] = "           ";
    int real_result = 1;
    
    int res = is_string_whitespace(s_in);

    ck_assert_mem_eq(&real_result, &res, sizeof(res));
}
END_TEST

START_TEST(test_is_string_whitespace_has_spaces)
{
    char s_in[] = "     aejiefjai      ";
    int real_result = 0;
    
    int res = is_string_whitespace(s_in);

    ck_assert_mem_eq(&real_result, &res, sizeof(res));
}
END_TEST

START_TEST(test_is_string_whitespace_no_spaces)
{
    char s_in[] = "afhioehafheahfoahe";
    int real_result = 0;
    
    int res = is_string_whitespace(s_in);

    ck_assert_mem_eq(&real_result, &res, sizeof(res));
}
END_TEST

START_TEST(test_parce_number_only_number)
{
    char buff[] = "12345";
    int res_number = 12345;
    
    long long number;
    parse_number(buff, &number);

    ck_assert_mem_eq(&res_number, &number, sizeof(res_number));
}
END_TEST

START_TEST(test_parce_number_number_and_letters)
{
    char buff[] = "12345aaaa";
    int res_number = 12345;
    
    long long number;
    parse_number(buff, &number);

    ck_assert_mem_eq(&res_number, &number, sizeof(res_number));
}
END_TEST


Suite* tests(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("tests");

    tc_pos = tcase_create("positives");
    // Добавим в tc_pos соответствующие функции-тесты
    tcase_add_test(tc_pos, test_copy_string_big_string);
    tcase_add_test(tc_pos, test_copy_string_empty);
    tcase_add_test(tc_pos, test_copy_string_regular);
    tcase_add_test(tc_pos, test_copy_string_with_spaces);
    tcase_add_test(tc_pos, test_is_string_whitespace_all_spaces);
    tcase_add_test(tc_pos, test_is_string_whitespace_has_spaces);
    tcase_add_test(tc_pos, test_is_string_whitespace_no_spaces);
    tcase_add_test(tc_pos, test_parce_number_only_number);
    tcase_add_test(tc_pos, test_parce_number_number_and_letters);
    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
