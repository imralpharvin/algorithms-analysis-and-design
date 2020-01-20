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

int checkAnagram (char * a1, char * a2)
{
		int count1[10] = { 0 };
    int count2[10] = { 0 };
    int i;

		if(strlen(a1) != strlen(a2))
		{
			return 0;
		}

    for (i = 0; a1[i] && a2[i]; i++) {
        count1[(int)(a1[i] - 48)]++;
        count2[(int)(a2[i]- 48)]++;
    }


    // Compare count arrays
    for (i = 0; i < 10; i++)
        if (count1[i] != count2[i])
            return 0;

    return 1;
}

int countAnagram (int rows , int columns,  char inputArray[rows][columns], char * str)
{
	int count = 0;
	int i = 0;

  printf("Anagrams:\n");
	for(i = 0; i < rows; i++)
	{

		if(checkAnagram(inputArray[i], str) == 1)
		{
      printf("%s\n",inputArray[i]);
			count++;
		}


	}
	return count;
}

void swap1(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r, int rows , int columns,  char inputArray[rows][columns], int * count)
{
   int i;
	 int j;
   if (l == r)
	 {
		 for(j = 0; j < rows; j++)
	 	{

	 		if(strcmp(inputArray[j], a) == 0)
	 		{
				printf("%s\n",inputArray[j]);
	 			(*count)++;
	 		}

	 	}
	 }

   else
   {

       for (i = l; i <= r; i++)
       {
          swap1((a+l), (a+i));
          permute(a, l+1, r, rows, columns, inputArray , count);
          swap1((a+l), (a+i));
       }
   }
}

/*
int countAnagram (int rows , int columns,  char inputArray[rows][columns], char * str)
{
	int * count;

	int i = 0;

	count = &i;

  printf("Anagrams:\n");

	permute(str, 0, strlen(str)-1, rows, columns,inputArray, count );


	return *count;
}
*/
