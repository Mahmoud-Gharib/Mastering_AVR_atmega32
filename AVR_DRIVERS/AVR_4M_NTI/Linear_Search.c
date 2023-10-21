#include <stdio.h>

int LinearSearch(unsigned int arr[], int Size, unsigned int Number) ;
void main(void) 
{
    unsigned int array[] = {5, 2, 3, 1, 9};
    int Size = sizeof(array) / sizeof(array[0]);
    unsigned int Number = 3;

    int result = LinearSearch(array, Size, Number);

    if (result == -1) 
	{
        printf("Element not found\n");
    } 
	else 
	{
        printf("Element found at index %d\n", result);
    }
}

int LinearSearch(unsigned int arr[], int Size, unsigned int Number) 
{
	int State = -1;
    for ( int i = 0 ; i < Size ; i++ )
	{
        if (arr[i] == Number) 
		{
            State = i; 
        }
    }
    return State; 
}