// File Name: uva591.c
// Author: darkdream
// Created Time: 2013年02月04日 星期一 20时22分44秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int n ,a[1000], k = 1;
   while (scanf("%d",&n),n)
   {
       int sum = 0 , i , t ;
	   for (i = 1;i <= n; i++)
	   {	   scanf("%d",&a[i]);
	      sum  += a[i] ;
	   }
	   t = sum / n; 
	   sum = 0 ;
	   for (i = 1 ;i <= n;i ++)
		   if (a[i] > t)
			   sum = sum +a[i]-t;
	   printf("Set #%d\n",k);
	   printf("The minimum number of moves is %d.\n\n",sum);
      k++;
   }
return 0 ;
}
