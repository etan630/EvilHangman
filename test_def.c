#include "unit_test.h"
#include "my_string.h"
#include <string.h>
#include <stdio.h>


//function 1
Status test_init_default_returns_nonNULL(char* buffer, int length) 
{

	MY_STRING hString = NULL; 
	
	hString = my_string_init_default();

	
	if(hString == NULL) 
	{
		strncpy(buffer, "test_init_default_returns_nonNULL\n" "my_string_init_default returns NULL", length);
		return FAILURE; 
	}
	else 
	{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length); 
		return SUCCESS;
	}
}



//function 2
Status test_get_size_on_init_default_returns_0(char* buffer, int length) 
{
	MY_STRING hString = NULL; 
	Status status;

	
	hString = my_string_init_default();

	
	if(my_string_get_size(hString) != 0) 
	{
		status = FAILURE;
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString)); 	
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n" "Did not receive 0 from get_size after init_default\n", length); 
	}
	else 
	{
		status = SUCCESS;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n", length); 
	}
	my_string_destroy(&hString);
	return status; 
}



//function 3
Status test_etan_destroy_sets_objects_to_null(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	my_string_destroy(&hString);
	if (hString != NULL)
	{
		status = FAILURE;
		printf("Expected NULL but got the address %p\n", hString);
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n" "Did not receive NULL from my_string_destroy after init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_destroy_sets_objects_to_null\n", length);
	}
	return status;
}


//function 4
Status test_etan_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_capacity(hString) != 7)
	{
		status = FAILURE;
		printf("Expected a capacity of 7 but got %d\n", my_string_get_capacity(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n" "Did not receive 7 from get_capacity after init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_get_capacity_on_init_default_returns_7\n", length);
	}
	my_string_destroy(&hString);
	return status;
}



//function 5
Status test_etan_is_empty_returns_true(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_default();

	if (my_string_empty(hString) != TRUE)
	{
		status = FAILURE;
		printf("Expected the bool %d but got %d\n", my_string_empty(hString), FALSE);
		strncpy(buffer, "test_is_empty_returns_true\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_is_empty_returns_true\n", length);
	}

	my_string_destroy(&hString);
	return status;
}



//function 6
Status test_etan_is_empty_returns_false(char* buffer, int length)
{
        MY_STRING hString = NULL;
        Status status;
        hString = my_string_init_c_string("Test test -- string is not empty");

        if (my_string_empty(hString) != FALSE)
        {
                status = FAILURE;
                printf("Expected the bool %d but got %d\n", my_string_empty(hString), TRUE);
                strncpy(buffer, "test_is_empty_returns_false\n", length);
        }
        else
        {
                status = SUCCESS;
                strncpy(buffer, "test_is_empty_returns_false\n", length);
        }

        my_string_destroy(&hString);
        return status;
}


//function 7
Status test_etan_my_string_init_c_string_is_not_null(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	
	hString = my_string_init_c_string("Test test -- should not be null\n");

	if (hString == NULL)
	{
		strncpy(buffer, "test_my_string_init_c_string_is_not_null\n" "muy_string_init_c_string returns NULL", length);
		status = FAILURE;
	}
	else
	{
		strncpy(buffer, "test_my_string_init_c_string_is_not_null\n", length);
		status = SUCCESS;
	}
	my_string_destroy(&hString);
	return status;
}


//function 8
Status test_etan_my_string_init_c_string_returns_correct_size(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("the");

	if (my_string_get_size(hString) != 3)
	{
		status = FAILURE;
		strncpy(buffer, "test_my_string_init_c_string_returns_correct_size\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_init_c_string_returns_correct_size\n", length);
	}
	
	my_string_destroy(&hString);	
	return status;
}



//function 9
Status test_etan_my_string_init_c_string_returns_correct_capacity(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	hString = my_string_init_c_string("the");

	if (my_string_get_capacity(hString) != my_string_get_size(hString) + 1)
	{
		status = FAILURE;
		strncpy(buffer, "test_my_string_init_c_string_returns_correct_capacity\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_init_c_string_returns_correct_capacity\n", length);
	}
	my_string_destroy(&hString);
	return status;
}



//function 10
Status test_etan_my_string_init_c_string_sets_correct_string_into_hString(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char test[] = "the";
	hString = my_string_init_c_string(test);

	for(int i = 0; i < my_string_get_size(hString); i++)
	{
		if(*my_string_at(hString, i) != test[i])
		{
			status = FAILURE;
			strncpy(buffer, "test_my_string_init_c_string_sets_correct_string_into_hString\n", length);
		}
	}
	status = SUCCESS;
	strncpy(buffer,"test_my_string_init_c_string_sets_correct_string_into_hString\n", length);

	my_string_destroy(&hString);
	return status;
}



//function 11
Status test_etan_my_string_compare_returns_less_than_zero_if_left_smaller_than_right(char* buffer, int length)
{
	MY_STRING hStringLeft = my_string_init_c_string("the apple");
	MY_STRING hStringRight = my_string_init_c_string("the apples");
	Status status;

	if (my_string_compare(hStringLeft, hStringRight) < 0)
	{
		status = SUCCESS;
		strncpy(buffer, "test_my_string_compare_returns_less_than_zero_if_left_smaller_than_right\n", length);
	}
	else
	{
		status = FAILURE;
		strncpy(buffer, "test_my_string_compare_returns_less_than_zero_if_left_smaller_than_right\n", length);
	}
	my_string_destroy(&hStringLeft);
	my_string_destroy(&hStringRight);

	return status;
}


//function 12
Status test_etan_my_string_compare_returns_zero_if_same(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("hello test test");
	MY_STRING hString2 = my_string_init_c_string("hello test test");
	Status status;

	if(my_string_compare(hString1, hString2) == 0)
	{
		status = SUCCESS;
		strncpy(buffer, "test_etan_my_string_compare_returns_zero_if_same\n", length);
	}
	else
	{
		status = FAILURE;
		strncpy(buffer, "test_etan_my_string_compare_returns_zero_if_same\n", length);
	}
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);

	return status;
}



//function 13
Status test_etan_my_string_compare_returns_greater_than_zero_if_left_bigger(char* buffer, int length)
{
        MY_STRING hString1 = my_string_init_c_string("hello test test test");
        MY_STRING hString2 = my_string_init_c_string("hello test test");
        Status status;

        if(my_string_compare(hString1, hString2) > 1)
        {
                status = SUCCESS;
                strncpy(buffer, "test_etan_my_string_compare_returns_greater_than_zero_if_left_bigger\n", length);
        }
        else
        {
                status = FAILURE;
       		strncpy(buffer, "test_etan_my_string_compare_returns_greater_than_zero_if_left_bigger\n", length);
       	}
        my_string_destroy(&hString1);
        my_string_destroy(&hString2);

        return status;
}


//function 14
Status test_etan_concat_combines_strings_correctly(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("This is string1 and ");
	MY_STRING hString2 = my_string_init_c_string("this is string2!");
	Status status;
	char test[] = "This is string1 and this is string2!";

	my_string_concat(hString1, hString2);
	for (int i = 0; i < my_string_get_size(hString1); i++)
	{
		if (*my_string_at(hString1, i) != test[i])
		{
			status = FAILURE;
			strncpy(buffer, "test_etan_concat_combines_strings_correctly\n", length);
		}
	}	
	status = SUCCESS;
        strncpy(buffer, "test_etan_concat_combines_strings_correctly\n", length);
	
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}


//function 15
Status test_etan_extration_gets_correct_string(char* buffer, int length)
{
	MY_STRING hString = NULL;
	FILE* input = fopen("simple.txt", "r");
	Status status;
	char c[] = "The quick brown";
	hString = my_string_init_default();

	my_string_extraction(hString, input);

	for (int i = 0; i < my_string_get_size(hString); i++)
	{
		if (*my_string_at(hString, i) != c[i])
		{
			status = FAILURE;
			strncpy(buffer, "test_etan_extration_gets_correct_string\n", length);
		}
		else
		{
			status = SUCCESS;
			strncpy(buffer, "test_etan_extration_gets_correct_string\n", length);
		}
	}
	fclose(input);
	my_string_destroy(&hString);
	return status;
}

//function 16
Status test_etan_insertion_writes_correct_string(char* buffer, int length)
{
	MY_STRING hString1 = my_string_init_c_string("this is a test\n");
	MY_STRING hString2 = my_string_init_default();
	Status status;

	FILE* input = fopen("test.txt", "w");
	my_string_insertion(hString2, input);
	fclose(input);

	input = fopen("test.txt", "r");
	my_string_extraction(hString1, input); //putting data into file
	fclose(input);

	for(int i = 0; i < my_string_get_size(hString1); i++)
	{
		if (*my_string_at(hString2, i) != *my_string_at(hString1, i))
		{
			status = FAILURE;
			strncpy(buffer, "test_etan_insertion_writes_correct_string\n", length);
		}
		else
		{
			status = SUCCESS;
			strncpy(buffer, "test_etan_insetion_writes_coorect_string\n", length);
		}
	}
	my_string_destroy(&hString1);
	my_string_destroy(&hString2);
	return status;
}


//function 17
Status test_etan_push_back_returns_success_by_adding_character(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "test";
	hString = my_string_init_c_string("This is a ");
	char full[] = "This is a test";

	for (int i = 0; i < strlen(c); i++)
	{
		my_string_push_back(hString, c[i]);
	}

	for (int i = 0; i < my_string_get_size(hString); i++)
	{
		if (*my_string_at(hString, i) != full[i])
		{
			status = FAILURE;
			strncpy(buffer, "test_etan_push_back_returns_success_by_adding_character\n", length);
			break;
		}
		else
		{
			status = SUCCESS;
			strncpy(buffer, "test_etan_push_back_returns_success_by_adding_character\n", length);
		}
		break;
	}
	my_string_destroy(&hString);
	return status;
}

//function 18
Status test_etan_push_back_resize_capacity_given_long_string(char* buffer, int length)
{
	MY_STRING hString = my_string_init_default();
	Status status;
	int capacity = my_string_get_capacity(hString);
	char c[] = "This is a super super super long string. This is also a test to see if the push back with correctly resize and adjust the capacity if given a very long string. Test test test test";

	for (int i = 0; i < (capacity + 2); i++)
	{
		my_string_push_back(hString, c[i]);
	}

	if (my_string_get_capacity(hString) != (capacity * 2))
	{
		status = FAILURE;
		strncpy(buffer, "test_etan_push_back_resize_capacity_given_long_string\n", length);
	}

	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_etan_push_back_resize_capacity_given_long_string\n", length);
	}

	my_string_destroy(&hString);
	return status;
}

//function 19
Status test_etan_pop_back_correctly_removes_last_character(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "Test";
	hString = my_string_init_c_string(c);
	MY_STRING test = my_string_init_default();


	my_string_pop_back(hString);
	
	for (int i = 0; i < strlen(c) - 1; i++)
        {
                my_string_push_back(test, c[i]);
        }

	for (int i = 0; i < my_string_get_size(hString); i++)
	{
		if(*my_string_at(hString, i) != *my_string_at(test, i))
		{
			status = FAILURE;
			strncpy(buffer, "test_etan_pop_back_correctly_removes_last_character\n", length);
		}
		else
		{
			status = SUCCESS;
			strncpy(buffer, "test_etan_pop_back_correctly_removes_last_character\n", length);

		}
	}

	my_string_destroy(&hString);
	my_string_destroy(&test);

	return status;
}

//function 20
Status test_etan_pop_back_returns_FAILURE_if_string_empty(char* buffer, int length)
{
	MY_STRING hString = my_string_init_default();
	Status status;

	if(my_string_pop_back(hString) == FAILURE)
	{
		status = SUCCESS;
		strncpy(buffer, "test_etan_pop_back_returns_FAILURE_if_string_empty\n", length);
	}
	else
	{
		status = FAILURE;
		 strncpy(buffer, "test_etan_pop_back_returns_FAILURE_if_string_empty\n", length);
	}
	my_string_destroy(&hString);
	return status;
}

//function 21
Status test_etan_pop_back_returns_SUCCESS_if_string_not_empty(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("test test");
	Status status;

	if(my_string_pop_back(hString) == SUCCESS)
	{
		status = SUCCESS;
                strncpy(buffer, "test_etan_pop_back_returns_FAILURE_if_string_empty\n", length);
        }
        else
        {
                status = FAILURE;
                 strncpy(buffer, "test_etan_pop_back_returns_FAILURE_if_string_empty\n", length);
        }
        my_string_destroy(&hString);
        return status;
}

//function 22
Status test_etan_pop_back_reduces_size_if_string_is_too_big(char* buffer, int length)
{
	MY_STRING hString = my_string_init_c_string("test");
	Status status;
	int size = my_string_get_size(hString);
	my_string_pop_back(hString);

	int current = my_string_get_size(hString);

	if (size - 1 != current)
	{
		status = FAILURE;
		strncpy(buffer, "test_etan_pop_back_reduces_size_if_string_is_too_big\n", length);
	}
	else
	{
		status = SUCCESS;
		 strncpy(buffer, "test_etan_pop_back_reduces_size_if_string_is_too_big\n", length);
	}

	my_string_destroy(&hString);
	return status;
}

//function 23
Status test_etan_my_string_at_returns_correct_address_of_character_at_index(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "test test";
	hString = my_string_init_c_string(c);

	for (int i = 0; i < my_string_get_size(hString); i++)
	{
		if (*my_string_at(hString, i) != c[i])
		{
			status = FAILURE;
			strncpy(buffer, "test_etan_my_string_at_returns_correct_address_of_character_at_index\n", length);
		}
		else
		{
			status = SUCCESS;
			strncpy(buffer, "test_etan_my_string_at_returns_correct_address_of_character_at_index\n", length);
		}
	}
	my_string_destroy(&hString);
	return status;
}

//function 24
Status test_etan_c_str_returns_correct_address_of_first_element(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "test test";
	hString = my_string_init_c_string(c);

	for (int i = 0; i < my_string_get_size(hString); i++)
	{
		if(my_string_c_str(hString)[i] != c[i])
		{
			status = FAILURE;
			strncpy(buffer,"test_etan_c_str_returns_correct_address_of_first_element\n", length);
			break;
		}
		else
		{
			status = SUCCESS;
			strncpy(buffer,"test_etan_c_str_returns_correct_address_of_first_element\n", length);
		}
		break;
	}
	my_string_destroy(&hString);
	return status;
}

//function 25
Status test_etan_get_size_returns_correct_size_not_on_default(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;
	char c[] = "this is a test";
	hString = my_string_init_c_string(c);

	if(my_string_get_size(hString) != strlen(c))
	{
		status = FAILURE;
		strncpy(buffer, "test_etan_get_size_returns_correct_size_not_on_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_etan_get_size_returns_correct_size_not_on_default\n", length);
	}
	my_string_destroy(&hString);
	return status;
}
