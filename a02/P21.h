/*Counts inversions via brute force algorithm*/

#ifndef P21_H
#define P21_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/timeb.h>
#include <stdbool.h>

typedef struct{
    double x;
    double y;
} Point;

Point ** convexHullBF(Point pointArray[], int n);
void createLine(Point one, Point two, double *A, double *B, double *C);
double findDistance(Point one, double A, double B, double C);

#endif
