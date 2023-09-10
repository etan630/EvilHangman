#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include "my_string.h" 

struct my_string 
{
  int size; // the number of characters currently in the object
  int capacity; // total capacity of the object
  char* data; // pointer to the object -malloc starts here
};
typedef struct my_string My_string; // define type

Boolean check_if_used( MY_STRING guess_list, char c ) {

    My_string* pMy_string = (My_string*)guess_list;
    int i ;

    for ( i = 0; i < my_string_get_size( guess_list ); i++ ) {

        if ( pMy_string -> data[i] == c ) {

            printf( "You have already guessed that letter! Try again...\n" ) ;
            return TRUE ;

        }

    }

    return FALSE ;

}


MY_STRING my_string_init_default(void)
{
	My_string *pString; //pointer string
	
	pString = (My_string*)malloc(sizeof(My_string));
  if (pString != NULL) {
    pString->capacity = 7;
	  pString->size = 0;
	  pString->data = (char*)malloc(sizeof(char)*pString->capacity);
    if (pString->data == NULL)
	  {
		  free(pString);
		  printf("my_string_init_default failed creating internal array -- will return NULL\n");
		  return NULL;
	  }
  } else if (pString == NULL)
	{
		printf("my_string_init_default failed -- will return NULL\n");
		return NULL;
	}

	return (MY_STRING) pString;

}

void my_string_destroy(MY_STRING* phMy_string)
{
	My_string *pString = (My_string*) *phMy_string; //casting to known type
	free(pString->data); //freeing the internal array
	pString->data = NULL; //ensure its freed

	free(pString);
	*phMy_string = NULL; //want to set handle in main to NULL

	//printf("my_string succesfully destroyed!\n");
}


MY_STRING my_string_init_c_string(const char* c_string)
{
  int i = 0; 
  int capacity = 0; 
  int size = 0; 
  char c = 'd'; 

  for( i = 0; c != '\0'; i++) // measure the size of the given c-string
    {
      c = c_string[i];
    }
  size = i - 1;
  capacity = size; 
  
  My_string* pString; 
  pString = (My_string*)malloc(sizeof(My_string)); 
  if(pString != NULL) 
  {
    pString->size = size; 
    pString->capacity = capacity; 
    pString->data = (char*)malloc(sizeof(char)*pString->capacity);
  }
  else 
  {
    printf("my_string_init_c_string failed -- will return NULL");
    free(pString); 
    pString = NULL; 
  }

  for (i = 0; i < capacity; i++) 
  {
    //copy string but not null-terminator
    pString->data[i] = c_string[i];
  }

  return (MY_STRING)pString; // cast to handle tpye void* and return
}

int my_string_get_capacity(MY_STRING hMy_string)
{
	My_string* pString = (My_string*) hMy_string; //cast to known type
	return pString->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	My_string* pString = (My_string*) hMy_string;
	return pString->size;
}

int my_string_compare( MY_STRING hLeft_string, MY_STRING hRight_string ) {

    My_string *pLeft_string = ( My_string * ) hLeft_string ;
    My_string *pRight_string = ( My_string * ) hRight_string ;
    int i ;
    //app
    //apple
    //
    //use size to tell when go out of bounds
    //1) see if empty or not
    //2)if first characters diff return difference between charaters -- 'a' - 'z' for an example
    //want to keep on looking until run out of bounds

    for ( i = 0; i < pLeft_string -> size && i < pRight_string -> size; i++ )    {
        
        if ( pLeft_string -> data[i] < pRight_string -> data[i] )
	{
            return -1 ;
        } else if ( pLeft_string -> data[i] > pRight_string -> data[i] ) {
            
            return 1 ;
        }

    }
    return 0;
}


Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
	My_string* pString = (My_string*) hMy_string; //casting to known type
	int c;
	char first_character;
	int noc;
	char* temp;
	int i;

	pString->size = 0; //deletes what ever was in the string before

	noc = fscanf(fp, " %c", &first_character); //this will skip all of the beginning spaces and blank and go directly to first "actual" character -- reading from file -- uses noc to see number of characters

	if (noc != 1) //means wasnt able to get character
	{
		return FAILURE; //didn't succeed in getting a string
	}	
	
	pString->data[pString->size] = first_character; //uses size because technically size is at 0 rn... so youre initializing the first element
	pString->size++;

	c = fgetc(fp);
	//while we got something and we want to keep it:
	while (c != EOF && !isspace(c)) //not end and is not a space
	{
		//if there is not room then try to make room
		if (pString->size >= pString->capacity) //this means its full
		{//RESIZING TO MAKE BIGGER!!
			temp = (char*)malloc(pString->capacity * 2 * sizeof(char)); //you want to double capacity
			if (temp == NULL)
			{
				printf("pString resize failed\n");
				return FAILURE;
			}

			for (i = 0; i < pString->size; i++)
			{
				temp[i] = pString->data[i];
			}
			free(pString->data); //because copied everything to temp already

			pString->data = temp; //dont free temp because then you'll erase the data you just created-- copying al of the temp data into pString -- array is replaced by larger one now
			pString->capacity *= 2; //doubling capacity
		}
		pString->data[pString->size] = c; //want to keep on copying until it reaches the end
		pString->size++;

		c = fgetc(fp); //process starts all over again
	}
	if (c != EOF)
	{
		ungetc(c, fp);
	} //if its just a space


	return SUCCESS;
}


Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  My_string* pString = (My_string*)hMy_string; 
  char c = 'd'; 
  int i = 0; 
  if (pString == NULL) 
  {
    return FAILURE; 
  } else {
    for (i = 0; i < pString->size; i++) 
    {
      c = pString->data[i]; 
      fprintf(fp, "%c", c); 
    }
      return SUCCESS; 
  }
}


Status my_string_push_back(MY_STRING hMy_string, char item)
{
	My_string* pString = (My_string*) hMy_string;
	char* temp;
	int i;

	if (pString->size >= pString->capacity) //need to restack
	{
		temp = (char*)malloc(2*pString->capacity * sizeof(char)); //want double of capacity
		if (temp == NULL)
		{
			printf("my_string_push_back resize failed\n");
			return FAILURE;
		}
		for (i = 0; i < pString->size; i++)
		{
			temp[i] = pString->data[i];//copying data over
		}
		free(pString->data); //free old data
		pString->data = temp; //putting temp into resized stack
		pString->capacity *= 2;
	}
	pString->data[pString->size] = item; //now that we have room we want to put the stuff into the string
	pString->size++; //want to iterate because just put stuff in

	return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
	My_string* pString = (My_string*) hMy_string;

	if (!(pString->size <= 0))
	{
		pString->size--;
		return SUCCESS;
	}
	return FAILURE;

}

char* my_string_at(MY_STRING hMy_string, int index)
{
	My_string* pString = (My_string*)hMy_string;

	if(index < 0 || index > pString->size)
	{
		return NULL;
	}
	//return &(hMy_string->data[index]); //want to return address of it
	return pString->data+index; //pointer arithmetic bc its address so plus pointer integer itll get the address youre looking for
}

char* my_string_c_str(MY_STRING hMy_string)
{
	My_string* pString = (My_string*) hMy_string;

	if (my_string_push_back(hMy_string, '\0') == FAILURE)
	{
		return NULL;
	}

	pString->size--; //bc dont want null terminator

	return pString->data;
}



Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
	My_string* pResult = (My_string*) hResult;
	My_string* pAppend = (My_string*) hAppend;
	char* temp;

	if (pResult->capacity <= (pResult->size + pAppend->size))
	{
		temp = (char*)malloc((pAppend->size + pResult->size + 1) * sizeof(char));
		if (temp == NULL)
		{
			printf("my_string_concat rezie failed\n");
			return FAILURE;
		}
		for (int i = 0; i < pResult->size; i++)
		{
			temp[i] = pResult->data[i];
		}
		free(pResult->data);
		pResult->data = temp;
		pResult->capacity = pAppend->size + pResult->size + 1;
	}

	for (int i = 0; i < pAppend->size; i++)
	{
		pResult->data[pResult->size] = pAppend->data[i];
		pResult->size++;
	}


	return SUCCESS;
}


Boolean my_string_empty(MY_STRING hMy_string)
{
	My_string* pString = (My_string*) hMy_string;

	return (pString->size <= 0);
}


void my_string_assignment(Item* pLeft, Item Right)
{
  My_string* pLeft_string = (My_string*)*pLeft;
  My_string* pRight_string = (My_string*)Right;
  int i;
  char* temp;
  temp = my_string_c_str((MY_STRING)Right);
  if(pLeft_string == NULL)
    {
      pLeft_string = my_string_init_c_string(temp);
    }
  else
    {
      pLeft_string->size = 0;
      for(i=0; i<pRight_string->size+1; i++)
	{
	  my_string_push_back(pLeft_string, pRight_string->data[i]);
	}
    }
  *pLeft = pLeft_string;
}

Status get_word_key_value( MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess ) {
    int i;
    while(!my_string_empty(new_key))
        my_string_pop_back(new_key);
    for(i = 0; i < my_string_get_size(word); i++)
        if(!my_string_push_back(new_key, *my_string_at(word, i) == guess ? guess : *my_string_at(current_word_family, i)))
            return FAILURE;
    return SUCCESS;   
}
