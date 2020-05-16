#include <stdio.h>
#include "Sort.h"

void printIn(int array[], int len)
{
	int i;

	for (i=0; i<len; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}


void main()
{
	int array[] = {32, 45, 12, 42, 26, 37};
	int len = sizeof(array) / sizeof(array[0]);

 	printIn(array, len);

// 	SelectSort(array, len);

//	InsertSort(array, len);

//	BubbleSort(array, len);

//	ShellSort(array, len);

//	Quicksort(array, len);

	MergeSort(array, len);

 	printIn(array, len);
}