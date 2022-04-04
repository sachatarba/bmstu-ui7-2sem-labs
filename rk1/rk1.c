//вариант 1
#include <stdio.h>

#define ERR_OK 0
#define ERR_INP 1

int input_array(int *array, int *size);

void modify_array(int *array, int size);

void print_array(int *array, int size);

int main(void)
{
	int size = 0;
	int array[10] = { 0 };
	
	int rc = ERR_INP;
	
	if (input_array(array, &size))
	{
		modify_array(array, size);
		print_array(array, size);
		rc = ERR_OK;
	}
	
	return rc;
}

int input_array(int *array, int *size)
{
	int rc = scanf("%d", size);
	
	if (rc)
	{
		for (int i = 0; i < *size; ++i)
		{
			rc = scanf("%d", array + i);
		}
	
	}
	
	return rc;
}

void print_array(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
}

void modify_array(int *array, int size)
{
	int array_null[10];
	int array_neg[10];
	int array_pos[10];
	
	int c_null = 0;
	int c_neg = 0;
	int c_pos = 0;
	
	for (int i = 0; i < size; ++i)
	{
		if (array[i] == 0)
		{
			array_null[c_null] = array[i];
			++c_null;
		}
		
		if (array[i] < 0)
		{
			array_neg[c_neg] = array[i];
			++c_neg;
		}
		
		if (array[i] > 0)
		{
			array_pos[c_pos] = array[i];
			++c_pos;
		}
	}	
		
	int c = 0;
		
	for (int i = 0; i < c_null; ++i)
	{
		array[c] = array_null[i];
		++c;
	}
		
	for (int i = 0; i < c_neg; ++i)
	{
		array[c] = array_neg[i];
		++c;
	}
		
	for (int i = 0; i < c_pos; ++i)
	{
		array[c] = array_pos[i];
		++c;
	}
}

