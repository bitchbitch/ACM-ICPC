// File Name: g.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 14时48分02秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main()
{

  long long int  a[1000];
   int i ;
	a[0] = 0;
   a[1] = 1;
   for (i =1 ;i < 500;i ++)
	   a[i*2] = a[i],a[i*2+1] = a[i]+1;
   for (i = 1; i< 100 ;i ++)
	   printf("%lld %d\n",a[i],i);

return 0 ;
}
