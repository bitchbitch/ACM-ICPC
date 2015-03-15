// File Name: 164div2.a.c
// Author: darkdream
// Created Time: 2013年01月28日 星期一 23时29分14秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int  n ; 
   scanf("%d",&n);
   
	   int a[100],b[100];
	   int i ,j,sum = 0;
	   for (i = 1;i <=  n; i ++)
		   scanf("%d %d",&a[i],&b[i]);
	   for (i = 1;i <= n;i++)
		   for (j = 1;j <= n;j++)
			   if (a[i] == b[j])
				   sum ++;
	   printf("%d\n",sum);
   
return 0 ;
}
