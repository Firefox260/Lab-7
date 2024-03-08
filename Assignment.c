// C program for implementation of Bubble sort

//reason for wh the swaps are not equal to the sum of swaps:
//since we are moving two values, we are in fact moving 2 elements at once
//which means that the count will be at least double the total
#include <stdio.h>
#include <stdlib.h>

// Swap function
void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// A function to implement bubble sort
int bubbleSort(int arr[], int n, int countr[])
{
	int i, j, k = 0;
	for (i = 0; i < n - 1; i++)
	{

		// Last i elements are already
		// in place
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				countr[j]++;
				countr[j + 1]++;
				swap(countr, j, j + 1);
				k++;
			}
		}
	}
	return k;
}

// Function to implement selection sort
int selectionSort(int arr[], int n, int countr[])
{
	int i, j, low_bound, k = 0;

	for (i = 0; i < n - 1; i++)
	{
		low_bound = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[low_bound])
			{
				low_bound = j;
			}
		}
		swap(arr, i, low_bound);
		countr[i]++;
		countr[low_bound]++;
		swap(countr, i, low_bound);
		k++;
	}

	return k;
}
// Function to print an array
void printArray(int arr[], int countr[], int total, int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d: %d\n", arr[i], countr[i]);
	printf("%d\n\n", total);
}

// Driver code
int main()
{
	int totals[] = {0, 0, 0, 0, 0};
	int arr1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
	int n = sizeof(arr1) / sizeof(int);
	int count1[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	totals[1] = bubbleSort(arr1, n, count1);
	printf("array1 bubble sort: \n");
	printArray(arr1, count1, totals[1], n);

	int arr2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	n = sizeof(arr2) / sizeof(int);
	int count2[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	totals[2] = bubbleSort(arr2, n, count2);
	printf("array2 bubble sort: \n");
	printArray(arr2, count2, totals[2], n);

	int arr3[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
	n = sizeof(arr3) / sizeof(int);
	int count3[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	totals[2] = selectionSort(arr3, n, count3);
	printf("array1 selection sort: \n");
	printArray(arr3, count3, totals[2], n);

	int arr4[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
	n = sizeof(arr4) / sizeof(int);
	int count4[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	totals[4] = selectionSort(arr4, n, count4);
	printf("array2 selection sort: \n");
	printArray(arr4, count4, totals[4], n);
	return 0;
}
