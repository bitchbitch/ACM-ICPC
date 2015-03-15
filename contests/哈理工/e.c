// File Name: e.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 14时36分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
 
	int n ;
	while(scanf("%d",&n) != EOF)
	{
	   int i , a;
	   long long sum = 0 ;
	   for (i =1 ; i <= n;i ++)
	   {	   scanf("%d",&a);
	      sum = sum +a;
	   }
	   if (sum %n == 0)
		   printf("%d\n",n);
	   else 
		   printf("%d\n",n-1);
	}

return 0 ;
}
