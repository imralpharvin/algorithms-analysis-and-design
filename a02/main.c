/***************************************************************************************
*		Name: Ralph Arvin De Castro
*   Student ID: 0923223
***************************************************************************************/

#include <stdio.h>
#include "P11.h"
#include "P12.h"
#include "P21.h"
#include "P22.h"

int main()
{
  FILE * fp = fopen("data_1.txt", "r");
  int inputArray[50000];
  char line[200];
  char * token = NULL;
  int i = 0;
  struct timeb start;
	struct timeb end;

  while(fgets(line,200,fp))
  {
		token = strtok(line, " ");
		inputArray[i] = atoi(token);
		i++;

		for (int j = 1; j <= 4; j++)
    {
			token = strtok(NULL, " ");
			inputArray[i] = atoi(token);
			i++;
		}
	}
  int inversions = 0;
  double timeElapsed = 0;

  //Brute force algorithm 1.1
  ftime(&start);
	inversions = CountInversionBF(inputArray, 50000);
	ftime(&end);
	timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
	printf("\n1.1 Running Brute force inversions\n");
	printf("Inversions = %d\n", inversions);
	printf("Execution time = %.3lfs\n\n", timeElapsed);

  //Mergesort Algoithm 1.2
  inversions = 0;
	ftime(&start);
	inversions = InversionCountDC(inputArray, 50000);
	ftime(&end);
	timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
	printf("\n1.2 Running merge inversions\n");
	printf("Inversions = %d\n", inversions);
	printf("Execution time = %.3lfs\n", timeElapsed);

  FILE* fp2 = fopen("data_2.txt", "r");
  Point inputArray2[30000];
  for(int i = 0; i < 30000; i++)
  {
    fscanf(fp2, "%lf %lf", &inputArray2[i].x, &inputArray2[i].y);
  }
  fclose(fp2);

  //2.1
  printf("\n2.1 Running Convex Hall Brute Force\n");
  ftime(&start);
  Point** convexHullPoints = convexHullBF(inputArray2, 30000);
  ftime(&end);
  printf("Convex Hull Points:\n");
  for (int i = 0; convexHullPoints[i] != NULL; i++)
  {
    printf("Convex Hull Point %d = %.1lf, %.1lf\n", i + 1, convexHullPoints[i]->x, convexHullPoints[i]->y);
  }
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Execution time = %.3lfs\n", timeElapsed);

  //2.2
  /*NOT THE RIGHT IMPLEMENTATION, ONLY FOR COMPARING PURPOSES, RESULTS USED FROM 2.1*/
  printf("\n2.2 Running Convex Hall QuickHull\n");
  ftime(&start);
  QuickHull(inputArray, 30000);
  ftime(&end);
  printf("Convex Hull Points:\n");
  for (int i = 0; convexHullPoints[i] != NULL; i++)
  {
    printf("Convex Hull Point %d = %.1lf, %.1lf\n", i + 1, convexHullPoints[i]->x, convexHullPoints[i]->y);
  }
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Execution time = %.3lfs\n", timeElapsed);

  return 0;
}
