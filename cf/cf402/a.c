// File Name: a.c
// Author: darkdream
// Created Time: 2014年03月16日 星期日 23时30分20秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int k,a,b,v;
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   scanf("%d %d %d %d",&k,&a,&b,&v);
   int sum = 0 ; 
   while(a > 0)
   {
      if(b )
	  {
	    if(b >= k - 1)
		{
		   b = b - (k-1);
		   a = a - (k) * v;
		}else {
		  a = a - v*(b+1);
		  b = 0 ; 
		}
	  }else{
		  a -= v; 
	  }
	 // printf("a = %d, b = %d\n", a,b);
	  sum ++ ; 
   }
   printf("%d\n",sum);
return 0 ;
}
