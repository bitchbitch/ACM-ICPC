// File Name: a.c
// Author: darkdream
// Created Time: 2013年03月13日 星期三 23时34分42秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);

   int n; 
   scanf("%d",&n);
   getchar();
   int x;
   while(n--)
   {
   
	 x = 0 ; 
		char a[100];
		gets(a);
		if(strchr(a,'-'))
			x--;
		else
			x ++;
		
   }
   printf("%d",x);
return 0 ;
}
