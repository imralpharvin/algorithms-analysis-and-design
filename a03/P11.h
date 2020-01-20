#ifndef P11_H
#define P11_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

int checkAnagram (char * a1, char * a2);

int countAnagram (int rows , int columns,  char inputArray[rows][columns], char * str);
void swap1(char *x, char *y);

void permute(char *a, int l, int r, int rows , int columns,  char inputArray[rows][columns], int * count);
#endif
