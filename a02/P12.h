#ifndef P12_H
#define P12_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>

int InversionCountDC(int A[], int n);
int InversionCountRecursion(int A[], int temp[], int p, int q);
int InversionMerge (int A[], int temp[], int p, int r, int q);
#endif
