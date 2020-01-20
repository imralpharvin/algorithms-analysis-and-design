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

/*Counts inversions via divide and conqure algorithm*/
int InversionCountDC(int A[], int n)
{
	int* tempArray = (malloc(sizeof(int) * n));
	return InversionCountRecursion(A, tempArray, 0, n - 1);
}
/*Counts inversions recursively via divide and conqure algorithm*/
int InversionCountRecursion(int A[], int temp[], int p, int q)
{
	int r, inversionCount = 0;
	if (q > p)
	{
		r = (q + p) / 2;

		inversionCount = InversionCountRecursion(A, temp, p, r);
		inversionCount += InversionCountRecursion(A, temp, r + 1, q);
		inversionCount += InversionMerge(A, temp, p, r + 1, q);
	}
	return inversionCount;
}
//Merges arrays and inversions
int InversionMerge(int A[], int temp[], int p, int r, int q)
{
	int i = p, j = r, k = p;
	int inversionCount = 0;

	while ((i <= r - 1) && (j <= q))
	{
		if (A[i] <= A[j])
		{
			temp[k++] = A[i++];
		}
		else
		{
			temp[k++] = A[j++];
			inversionCount += (r - i);
		}
	}

	while (i <= r - 1)
	{
		temp[k++] = A[i++];
	}

	while (j <= q)
	{
		temp[k++] = A[j++];
	}

	for (i = p; i <= q; i++)
	{
		A[i] = temp[i];
	}

	return inversionCount;
}

/*Implementation below used from mergesort algorithm,
somehow not giving the exact results as my brute force algorithm,
Code above derived from geeksforgeeks which follows a divide and conquer mergesort algorithm*/

/*
int InversionMerge (int B[], int C[], int A[], int p, int q)
{
	int i = 0, j = 0, k = 0, invCount = 0;

	while (i < p && j < q)
  {
		if (B[i] <= C[j])
    {
			A[k] = B[i];
			i++;
      k++;
		}
		else
    {
			A[k] = C[j];
			j++;
      k++;
			invCount = invCount + p - i;
		}
	}


	if (i == p) 	//copy C[j...q-1] to A[k...p+q-1]
  {
    while(j < q)
    {
      	A[k] = C[j];
        k++;
        j++;
    }
	}
	else 	//copy B[i...p-1] to A[k...p+q-1]
  {
    while(i < p)
    {
        A[k] = B[i];
        k++;
        i++;
    }
	}
	return invCount;
}


int InversionCountDC(int A[], int n)
{

	if (n > 1)
  {

		int B[(int)floor(n/2)];
		int C[(int)ceil(n/2)];
    int invCount = 0;

		for (int i = 0; i < floor(n/2); i++)
    {
			B[i] = A[i];
		}

		//copy A[floor(n/2)..n-1] to C[0..ceiling(n/2)-1]
		for (int i = floor(n/2), j = 0; i < n; i++, j++)
    {
			C[j] = A[i];
		}

		invCount = InversionCountDC(B, floor(n/2));
		invCount = invCount + InversionCountDC(C, ceil(n/2));
		invCount = invCount + InversionMerge(B, C, A,floor(n/2) , ceil(n/2));

    return invCount;
	}

  return 0;
}*/
