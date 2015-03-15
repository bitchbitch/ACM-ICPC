// File Name: 164.c.c
// Author: darkdream
// Created Time: 2013年01月29日 星期二 00时42分17秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
	int n , m , temp ,i;
	scanf("%d %d",&n,&m);
	if (n > m )
	{
	  printf("%d\n",m+1);
	  for (i = 0 ;i <= m; i++)
	  {
	     printf("%d %d\n",i , m-i);
	  }
	}
	else
	{
	
	  printf("%d\n",n+1);
	  for (i = n ;i >= 0; i--)
	  {
	     printf("%d %d\n",n-i , i);
	  }
	}
return 0 ;
}
