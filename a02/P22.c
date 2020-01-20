#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <math.h>

#include "P22.h"

/*Not a real Implementation of convex hull, only for simulation and compilation purposes*/
int FindHull (int B[], int C[], int A[], int p, int q)
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
	else 	//copy B[i...p-1] to A[k...p+q-1]*/
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

/*Not a real Implementation of convex hull, only for simulation and compilation purposes*/
int QuickHull(int A[], int n)
{


	if (n > 1)
  {

		int B[(int)floor(n/2)];
		int C[(int)ceil(n/2)];
    int invCount = 0;

		//copy A[0..floor(n/2)-1] to B[0..floor(n/2)-1]
		for (int i = 0; i < floor(n/2); i++)
    {
			B[i] = A[i];
		}

		//copy A[floor(n/2)..n-1] to C[0..ceiling(n/2)-1]
		for (int i = floor(n/2), j = 0; i < n; i++, j++)
    {
			C[j] = A[i];
		}

		invCount = QuickHull(B, floor(n/2));
		invCount = invCount + QuickHull(C, ceil(n/2));
		invCount = invCount + FindHull(B, C, A,floor(n/2) , ceil(n/2));

    return invCount;
	}

  return 0;
}
