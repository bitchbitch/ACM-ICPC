// File Name: a.c
// Author: darkdream
// Created Time: 2013年03月16日 星期六 13时14分59秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int a[1000005];
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int  n; 
   while(scanf("%d",&n)!=EOF)
   {
     int sum = 0 ,t = 0 ;
	 for(int i = 1; i <= n; i ++)
	 { scanf("%d",&a[i]);
	   sum += a[i];
	   for(int i = 0 ; i < n ;i ++)
           
	 }

   }
return 0 ;
}
