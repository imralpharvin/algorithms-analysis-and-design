/***************************************************************************************
*		Name: Ralph Arvin De Castro
*   Student ID: 0923223
***************************************************************************************/

#include <stdio.h>
#include "P11.h"
#include "P12.h"
#include "P21.h"
#include "P22.h"
#include "P23.h"

int main()
{
  FILE * fp = fopen("data_4.txt", "r");
  //int numArray[30000];
  static char inputArray[30000][20];
  char line[200];
  char * token = NULL;
  int i = 0;
  struct timeb start;
	struct timeb end;

  while(fgets(line,200,fp))
  {
		token = strtok(line, " ");
		strcpy(inputArray[i], token);
		i++;

		for (int j = 1; j <= 4; j++)
    {
			token = strtok(NULL, " ");
			strcpy(inputArray[i], token);
			i++;

		}

	}

  int anagrams = 0;
  double timeElapsed = 0;



  char string1[20];
  printf("\nQuestion 1. Enter string: \n");

  scanf("%s", string1);
    //Brute force algorithm 1.1
  char str[] = "1236890";
  printf("\n1.1 Running Brute force Anagrams\n");
  ftime(&start);
  anagrams = countAnagram(i, 20, inputArray, string1);
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Total number of anagrams = %d\n", anagrams);
  printf("Execution time = %.3lfs\n", timeElapsed);


  printf("\n1.2 Running Presort\n");
  static double numArray[30000];
  ftime(&start);
  preSort(i, 20, inputArray, numArray);
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Execution time = %.3lfs\n", timeElapsed);
  printf("1.2 Running Algorithm\n");
  char string[] = "1236890";
  sortString(string1);
  double num = atof(string1);
  ftime(&start);
  anagrams = countAnagramPS(numArray,num);
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Total number of anagrams = %d\n", anagrams);
  printf("Execution time = %.7lfs\n\n", timeElapsed);


  char string2[20];
  printf("\nQuestion 1. Enter string: \n");

  scanf("%s", string2);
//PART 2
  FILE* file = fopen("data_5.txt", "r");

  fseek(file, 0, SEEK_END);
  int fsize = ftell(file);
  fseek(file, 0, SEEK_SET);
  char* buffer = malloc(fsize);
  fread(buffer, fsize, 1, file);
  fclose(file);
  int occurrences = 0;


  printf("STRING TO SEARCH: \"University\"\n");
  printf("\n2.1 Running Occurrences\n");
  ftime(&start);
  occurrences = countOcurrences(buffer, "University");
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Occurrences = %d\n", occurrences);
  printf("Execution time = %.3lfs\n\n", timeElapsed);

  printf("\n2.2 Running Occurrences HP\n");
  ftime(&start);
  occurrences = countOcurrencesHP(buffer, "University");
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Occurrences = %d\n", occurrences);
  printf("Execution time = %.3lfs\n\n", timeElapsed);

  printf("\n2.3 Running Occurrences BW\n");
  ftime(&start);
  occurrences = search(buffer, "University");
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Occurrences = %d\n", occurrences);
  printf("Execution time = %.3lfs\n\n", timeElapsed);


  printf("STRING TO SEARCH: \"University\"\n");
  printf("\n2.1 Running Occurrences\n");
  ftime(&start);
  occurrences = countOcurrences(buffer, "University");
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Occurrences = %d\n", occurrences);
  printf("Execution time = %.3lfs\n\n", timeElapsed);

  printf("\n2.2 Running Occurrences HP\n");
  ftime(&start);
  occurrences = countOcurrencesHP(buffer, "University");
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Occurrences = %d\n", occurrences);
  printf("Execution time = %.3lfs\n\n", timeElapsed);

  printf("\n2.3 Running Occurrences BW\n");
  ftime(&start);
  occurrences = search(buffer, "University");
  ftime(&end);
  timeElapsed = (end.time + (end.millitm * 0.001)) - (start.time + (start.millitm * 0.001));
  printf("Occurrences = %d\n", occurrences);
  printf("Execution time = %.3lfs\n\n", timeElapsed);


  // free your buffer
  free(buffer);

  return 0;
}
