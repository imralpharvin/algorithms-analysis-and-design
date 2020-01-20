/***************************************************************************************
*		Name: Ralph Arvin De Castro
*   Student ID: 0923223
*   Algorithm followed from mergesort textbook and GeeksforGeeks.com
*		Title: Count Inversion in an array source code
*		Date: February 2019
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <math.h>
#include "P12.h"

// A utility function to swap two elements
void swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
double partition (double arr[], int low, int high)
{
    double pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        double pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void sortString(char string[])
{
	char temp;

	int i, j;
	int n = strlen(string);

	for (i = 0; i < n-1; i++) {
	 for (j = i+1; j < n; j++) {
			if (string[i] < string[j]) {
				 temp = string[i];
				 string[i] = string[j];
				 string[j] = temp;
			}
	 }
}
}

void preSort(int rows, int columns, char inputArray[rows][columns], double* numArray)
{
	int i = 0;
	for(i = 0; i < rows; i ++)
	{
		sortString(inputArray[i] );
		numArray[i] = atof(inputArray[i]);
	}

	quickSort(numArray, 0, rows);

}

int countAnagramPS(double* numArray, double num)
{
	int count = 0;
	int i = 0;

  printf("Anagrams (PreSorted):\n");

	for(i = 0; numArray[i] <= num; i++)
	{
		if(num == numArray[i])
		{
      printf("%d\n", (int)numArray[i]);
			count++;
		}
	}


	return count;
}
