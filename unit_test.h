#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_etan_destroy_sets_objects_to_null(char* buffer, int length);
Status test_etan_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_etan_is_empty_returns_true(char* buffer, int length);
Status test_etan_is_empty_returns_false(char* buffer, int length);
Status test_etan_my_string_init_c_string_is_not_null(char* buffer, int length);
Status test_etan_my_string_init_c_string_returns_correct_size(char* buffer, int length);
Status test_etan_my_string_init_c_string_returns_correct_capacity(char* buffer, int length);
Status test_etan_my_string_init_c_string_sets_correct_string_into_hString(char* buffer, int length);
Status test_etan_my_string_compare_returns_less_than_zero_if_left_smaller_than_right(char* buffer, int length);
Status test_etan_my_string_compare_returns_zero_if_same(char* buffer, int length);
Status test_etan_my_string_compare_returns_greater_than_zero_if_left_bigger(char* buffer, int length);
Status test_etan_concat_combines_strings_correctly(char* buffer, int length);
Status test_etan_extration_gets_correct_string(char* buffer, int length);
Status test_etan_insertion_writes_correct_string(char* buffer, int length);
Status test_etan_push_back_returns_success_by_adding_character(char* buffer, int length);
Status test_etan_push_back_resize_capacity_given_long_string(char* buffer, int length);
Status test_etan_pop_back_correctly_removes_last_character(char* buffer, int length);
Status test_etan_pop_back_returns_FAILURE_if_string_empty(char* buffer, int length);
Status test_etan_pop_back_returns_SUCCESS_if_string_not_empty(char* buffer, int length);
Status test_etan_pop_back_reduces_size_if_string_is_too_big(char* buffer, int length);
Status test_etan_my_string_at_returns_correct_address_of_character_at_index(char* buffer, int length);
Status test_etan_c_str_returns_correct_address_of_first_element(char* buffer, int length);
Status test_etan_get_size_returns_correct_size_not_on_default(char* buffer, int length);
#endif
