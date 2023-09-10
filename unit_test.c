#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
	Status (*tests[])(char*, int) =
       	{
		test_init_default_returns_nonNULL,
		test_get_size_on_init_default_returns_0,
		test_etan_destroy_sets_objects_to_null,
		test_etan_get_capacity_on_init_default_returns_7,
		test_etan_is_empty_returns_true,
		test_etan_is_empty_returns_false,
		test_etan_my_string_init_c_string_is_not_null,
		test_etan_my_string_init_c_string_returns_correct_size,
		test_etan_my_string_init_c_string_returns_correct_capacity,
		test_etan_my_string_init_c_string_sets_correct_string_into_hString,
		test_etan_my_string_compare_returns_less_than_zero_if_left_smaller_than_right,
		test_etan_my_string_compare_returns_zero_if_same,
		test_etan_my_string_compare_returns_greater_than_zero_if_left_bigger,
		test_etan_concat_combines_strings_correctly,
		test_etan_extration_gets_correct_string,
		test_etan_insertion_writes_correct_string,
		test_etan_push_back_returns_success_by_adding_character,
		test_etan_push_back_resize_capacity_given_long_string,
		test_etan_pop_back_correctly_removes_last_character,
		test_etan_pop_back_returns_FAILURE_if_string_empty,
		test_etan_pop_back_returns_SUCCESS_if_string_not_empty,
		test_etan_pop_back_reduces_size_if_string_is_too_big,
		test_etan_my_string_at_returns_correct_address_of_character_at_index,
		test_etan_c_str_returns_correct_address_of_first_element,
		test_etan_get_size_returns_correct_size_not_on_default
	};
	int number_of_functions = sizeof(tests) / sizeof(tests[0]); 
	int i;
	char buffer[500];
	int success_count = 0;
	int failure_count = 0;

	for(i=0; i<number_of_functions; i++) 
	{
		if(tests[i](buffer, 500) == FAILURE) 
		{
			printf("FAILED: Test %d failed miserably\n", i); 
			printf("\t%s\n", buffer);
			failure_count++;
		} 
		else 
		{
			// printf("PASS: Test %d passed\n", i);
			// printf("\t%s\n", buffer); 
			success_count++;
		} 
	}
	printf("Total number of tests: %d\n", number_of_functions); 	
	printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions); 
	return 0;
}
