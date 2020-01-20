/***************************************************************************************
*		Name: Ralph Arvin De Castro
*   Student ID: 0923223
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <sys/types.h>

/*Counts inversions via brute force algorithm*/
int CountInversionBF (int A[], int n)
{

	int c = 0;

	for (int i = 0; i < n; i++)
  {
		for (int j = i + 1; j < n ; j++)
    {
			if (A[i] > A[j])
      {
				c++;
			}
		}
	}
	return c;
}
