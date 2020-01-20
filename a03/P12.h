#ifndef P12_H
#define P12_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

void swap(double* a, double* b);
double partition (double arr[], int low, int high);
void quickSort(double arr[], int low, int high);

void sortString(char string[]);
void preSort(int rows, int columns, char inputArray[rows][columns], double * numArray);
int countAnagramPS(double* numArray, double num);



#endif
