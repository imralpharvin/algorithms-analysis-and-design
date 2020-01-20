#ifndef P23_H
#define P23_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

# define NO_OF_CHARS 256
int max (int a, int b);
void badCharHeuristic( char *str, int size,
                        int badchar[NO_OF_CHARS]);
int search( char *txt,  char *pat);

#endif
