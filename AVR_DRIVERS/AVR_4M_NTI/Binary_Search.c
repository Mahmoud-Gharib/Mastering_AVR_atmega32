#include <stdio.h>

int BinarySearch(unsigned int arr[], int Size, unsigned int Number) ;
void main(void) 
{
    unsigned int array[] = {1, 2, 3, 5, 9 , 13};
    int Size = sizeof(array) / sizeof(array[0]);
    unsigned int Number = 1;

    int result = BinarySearch(array, Size, Number);

    if (result == -1) 
	{
        printf("Element not found\n");
    } 
	else 
	{
        printf("Element found at index %d\n", result);
    }
}

int BinarySearch(unsigned int arr[], int Size, unsigned int Number) 
{
	int State = -1;
	int Left = 0;
    int Right = Size - 1;
	int Mid = Left + ( Right- Left) / 2;
	
	do{
        Mid = Left + ( Right- Left) / 2;

        if (arr[Mid] == Number) 
		{
			State = Mid;
			break;
        }
        else if (arr[Mid] < Number) 
		{
            Left = Mid + 1;
        }
        else 
		{
            Right = Mid - 1;
        }
    }while (Number != arr[Mid] && Left <= Right) ;

    return State; 
}




