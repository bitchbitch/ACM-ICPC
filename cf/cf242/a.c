// File Name: a.c
// Author: darkdream
// Created Time: 2014年04月25日 星期五 14时56分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
char str[100000];
int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n ;
    scanf("%d",&n);
	scanf("%s",str);
	n = n / 2; 
	int len = strlen(str);
	int x, y ; 
	x = y =0 ; 
	
	for(int i = 0 ;i < len;i ++)
	{
	   if(str[i] == 'X')
		   x ++ ; 
	   else y ++ ; 
	}
	if(x < n)
	{
	   int num = 0 ; 
	   printf("%d\n",n - x );
	   for(int i = 0 ;i < len;i ++)
		   if(str[i] == 'x')
		   {
			  if(num != n-x)
			  {
		      printf("X");
			   num ++ ; 
			  }else printf("x");
		   }else printf("X");
	}else {
	   int num = 0 ; 
	   printf("%d\n",n - y );
	   for(int i = 0 ;i < len;i ++)
		   if(str[i] == 'X')
		   {
			  if(num != n-y)
			  {
		       printf("x");
			   num ++ ; 
			  }else printf("X");
		   }else printf("x");
	}
	printf("\n");

return 0 ;
}
