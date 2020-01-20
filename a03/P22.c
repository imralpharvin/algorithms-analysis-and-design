#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>
#include <sys/types.h>
#include <math.h>

#include "P22.h"
//#include<conio.h>
#define MAX 500
int t[MAX];
void shifttable(char p[])
{
 int i;
 int j;
 int m;

 m=strlen(p);
 for(i=0;i<MAX;i++)
 {
   t[i]=m;
 }

 for(j=0;j<m-1;j++)
 {
   t[(int)p[j]]=m-1-j;
  }
}
int horspool(char src[],char p[])
{
 int i,j,k,m,n;
 int count = 0;
 n=strlen(src);
 m=strlen(p);
 i=m-1;
 while(i<n)
 {
  k=0;
  while((k<m)&&(p[m-1-k]==src[i-k]))
  {
     k++;
  }
  if(k==m)
	{
		count++;
    i += m;
 	}
  else
  {
    i+=t[(int)src[i]];
  }
  //  printf("%d\n", i);
 }
 return count;
}

int countOcurrencesHP(char * src, char * p)
{
int pos;
 shifttable(p);
 pos=horspool(src,p);

 /*if(pos>=0)
  printf("n The desired pattern was found starting from position %d\n",pos+1);
 else
  printf("n The pattern was not found in the given textn");*/
 //getch();

 return pos;
}
