// File Name: g.c
// Author: darkdream
// Created Time: 2013年09月04日 星期三 12时54分05秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int ans[1005];
	int n, m , y ;
int some(double t)
{
	return t/1;
}
struct node{
	int x;
	int num;
	int ans;
	double  p; 
}a[1005];
int cmp1(const void * a ,const void * b)
{
	return
	(fabs(((*(node*)b).ans+1)*1.0/m - (*(node*)b).x/y ) - 
	fabs(((*(node*)b).ans)*1.0/m - (*(node*)b).x/y ) ) 
	-
	(fabs(((*(node*)a).ans+1)*1.0/m - (*(node*)a).x/y ) - 
	fabs(((*(node*)a).ans)*1.0/m - (*(node*)a).x/y ) ); 
}
int main()
{
   printf("%d\n",(int)3.6);
   return 0 ;
}
