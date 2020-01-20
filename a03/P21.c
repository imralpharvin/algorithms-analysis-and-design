/***************************************************************************************
*		Name: Ralph Arvin De Castro
*   Student ID: 0923223
***************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <math.h>

#include "P21.h"

int countOcurrences(char *str, char *sub)
{
  int i, j, found, count;
  int p = 0;
      int stringLen, searchLen;

      stringLen = strlen(str);      // length of string
      searchLen = strlen(sub); // length of word to be searched

      count = 0;

      for(i=0; i <= stringLen-searchLen; i++)
      {
          /* Match word with string */
          found = 1;
          for(j=0; j<searchLen; j++)
          {

              if(str[i + j] != sub[j])
              {
                  found = 0;
                  break;
              }
          }

          if(found == 1)
          {
              count++;
          }
      }

    printf("Number of Pattern Shifts = %d\n", i);
    return count;
}
