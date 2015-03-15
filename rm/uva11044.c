// File Name: uva11044.c
// Author: darkdream
// Created Time: 2013年02月18日 星期一 21时54分45秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int n ;
   scanf("%d",&n);
   while(n--)
   {
       int  a , b ;
	   scanf("%d %d",&a,&b);
	   a =ceil((a-2)/3.0);
	   b =ceil((b-2)/3.0);
	   printf("%d\n",a*b);
   }

return 0 ;
}
