// File Name: c.c
// Author: darkdream
// Created Time: 2014年03月02日 星期日 00时28分40秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   long long n , m; 
   long long ans = 0 ; 
   scanf("%lld %lld", &n,&m);
   if(n > m )
   {
	   
	   printf("%lld\n",(n-m+1)*(n-m+1) -1);
	   printf("%lld\n",n*n- m * m);
	   for(int i = 1;i<= n;i ++)
		   printf("o");
	   for(int i = 1;i<= m;i ++)
		   printf("x");
       
   }else{
	  //printf("%lld\n",-(m-n)*(m-n));
      long long t =(m-n)/2;
      long long p = (m-n) - t;
	  if(n)
	  printf("%lld\n",-((t+1)*(t+1)+p*p-1));
	  else printf("%lld\n",-m*m);
	  for(int i = 1;i<= t; i ++)
		  printf("x");
	  for(int i = 1;i <= n;i ++)
		  printf("xo");
	  for(int i = 1;i <= (m-n) - t; i ++)
		  printf("x");
   }
return 0 ;
}
