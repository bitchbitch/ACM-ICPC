// File Name: a.c
// Author: darkdream
// Created Time: 2013年06月03日 星期一 16时04分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ;
   scanf("%d",&n);
   while(n--)
   {
     long long b; 
	 scanf("%lld",&b);
     if(b %2 == 1 )
	 {
	    printf("%lld\n",(b-1)/2*(b-1)/2);
	 }
	 else
	 {
	    if((b-2)/2 %2 == 1)
		{
		  printf("%lld\n",(b-4)/4*(b-4)/4);
		}
		else
			printf("%lld\n",(b-2)/2*(b-2)/2/2);
	 
	 }
   }
return 0 ;
}
