// File Name: j.c
// Author: darkdream
// Created Time: 2013年07月18日 星期四 15时35分30秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<limits.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n ,a,b;
   while(scanf("%d %d %d",&n,&a,&b) != EOF)
   {
	int min = INT_MAX;
	int dot = 0;
    int i ;
	for( i = 1 ; ;i ++)
	 {
	   int t = a * i ;
	   if(t/b + i >= n)
	   {
	     min = t ;
		 break;
	   }

	 }
	 dot += i ;
	for( i = 1; ; i ++)
	{
	  int t = b* i;
	  if(t/a+i >= n)
	  {
	    if(t > min)
		{
		  min = t;
		}
		break;
	  }
	}
	dot += i ;

     printf("%d %d\n",dot,min);
   }
return 0 ;
}
