/*
******************************************************************************************************* 
* Filename     : Sort.c
* Author       : Peterson
* Created      : 2014/02/24
* Description  : 排序算法汇总C文件，选择排序、插入排序、冒泡排序、希尔排序、快速排序等函数定义
******************************************************************************************************** 
*/ 
#include <stdio.h>
#include <malloc.h>
#include "Sort.h"

static void swap(int array[], int i, int j)
{
	int temp = array[i];
	
	array[i] = array[j];
	
	array[j] = temp;
}


void SelectSort(int array[], int len)//O(n^2)
{
	int i = 0;
	int j = 0;
	int min = -1;
	
	for (i=0; i<len; i++)
	{
		for (min=i, j=i; j<len; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		
		if (min != i)
		{
			swap(array, i, min);
		}
	}
}


void InsertSort(int array[], int len)//O(n^2)
{
	int i = 0;
	int j = 0;
	int inser = -1;
	int temp = -1;
	
	for (i=1; i<len; i++)
	{
		inser = i;
		temp = array[inser];
		
		for (j=i-1; (j>=0) && (array[j]>temp); j--)
		{
			array[inser] = array[j];
			inser = j;
		}
		
		array[inser] = temp;
	}
}


void BubbleSort(int array[], int len)//O(n^2)
{
	int i = 0;
	int j = 0;
	int exchange = 1;
	
	for (i=0; (i<len) && exchange; i++)
	{
		exchange = 0;
		
		for (j=len-1; j>i; j--)
		{
			if (array[j] < array[j-1])
			{
				exchange = 1;
				swap(array, j, j-1);
			}
		}
	}
}


void ShellSort(int array[], int len)//O(nlog^n)
{
	int i = 0;
	int j = 0;
	int k = -1;
	int temp = -1;
	int gap = len;
	
	do 
	{
		gap = gap/3 + 1;
		
		for (i=gap; i<len; i+=gap)
		{
			k = i;
			temp = array[k];
			
			for (j=i-gap; (j>=0) && (array[j]>temp); j-=gap)
			{
				array[j+gap] = array[j];
				k = j;
			}
			
			array[k] = temp;
		}

	} 
	while (gap > 1);
}


static int partition(int array[], int low, int high)
{
	int pv = array[low];

	while(low < high)
	{
		while((low < high) && (array[high] >= pv))
		{
			high--;
		}

		swap(array, low, high);

		while((low < high) && (array[low] <= pv))
		{
			low++;
		}

		swap(array, low, high);
	}

	return low;
}

static void QSort(int array[], int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, low, high);

		QSort(array, low, pivot-1);
		QSort(array, pivot+1, high);
	}
}

void Quicksort(int array[], int len)//O(nlog^n)
{
	QSort(array, 0, len-1);
}


static void Merge(int src[], int des[], int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;

	while((i <= mid) && (j <= high))
	{
		if (src[i] < src[j])
		{
			des[k++] = src[i++];
		}
		else
		{
			des[k++] = src[j++];
		}
	}
	while(i <= mid)
	{
		des[k++] = src[i++];
	}
	
	while(j <= high)
	{
		des[k++] = src[j++];
	}
}

static void MSort(int src[], int des[], int low, int high, int max)
{
	if (low == high)
	{
		des[low] = src[low];
	}
	else
	{
		int mid = (low + high) / 2;
		int *space = (int*)malloc(sizeof(int) * max);

		if (space != NULL)
		{
			MSort(src, space, low, mid, max);
			MSort(src, space, mid+1, high, max);
			Merge(space, des, low, mid, high);
		}

		free(space);
	}
}

void MergeSort(int array[], int len)//O(n*log^n)
{
	MSort(array, array, 0, len-1, len);
}



















