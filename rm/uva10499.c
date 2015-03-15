// File Name: uva10499.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 11时06分53秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   long long n; 
   while(scanf("%lld",&n)!=EOF)
   {
      if (n < 0)
		  break;
	  if(n == 1)
		  printf("0%%\n");
	  else
		  printf("%lld%%\n",n*25);

   }
return 0 ;
}
