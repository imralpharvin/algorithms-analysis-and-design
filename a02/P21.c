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

/*Finds convex hull points via brute force algorithm*/
Point ** convexHullBF(Point pointArray[], int n)
{

    Point** convexHullPoints = malloc(sizeof(Point*) * (n + 1));
    int hullCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || (pointArray[i].x == pointArray[j].x && pointArray[i].y == pointArray[j].y))
            {
              continue;
            }

            bool positive = true;
            bool isHull = true;
            double A = 0.0;
            double B = 0.0;
            double C = 0.0;
            createLine(pointArray[i], pointArray[j], &A, &B, &C);
            for (int k = 0; k < n && isHull; k++)
            {
                if (k == i || k == j)
                {
                  continue;
                }
                double distance = findDistance(pointArray[k], A, B, C);
                //printf("A: %lf B: %lf C: %lf dist: %lf\n", A, B, C, distance);

                if (k == 0)
                {
                    if (distance < 0)
                    {
                        positive = false;
                    }
                    else
                    {
                        positive = true;
                    }
                }
                else if ((distance >= 0 && positive == false) || (distance <= 0 && positive == true))
                {

                    isHull = false;
                    continue;
                }
            }
            if (isHull == true)
            {
                convexHullPoints[hullCount++] = &pointArray[i];
                break;
            }
        }
    }
    convexHullPoints[hullCount] = NULL;
    return convexHullPoints;
}


//Creates line variables Ax + By + C = 0
void createLine(Point one, Point two, double *A, double *B, double *C)
{
  *A = one.y - two.y;
  *B = two.x - one.x;
  *C = (one.x * two.y) - (two.x * one.y);
}

//Finds distance between a line and a point
double findDistance(Point one, double A, double B, double C)
{
   double num = A * one.x + B * one.y + C;
   double den = sqrt(pow(A, 2) + pow(B, 2));
   double dist = num/den;

   return dist;
}
