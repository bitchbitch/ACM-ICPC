// File Name: i.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 19时11分31秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
long long int a[100000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    a[1] = 1;
	for(int i = 3; ; i = i+2)
	{
	   a[i] = a[i-2] + i*i;
	   if(a[i] > INT_MAX)
		   break;
	}
	int n ;
	while(scanf("%d",&n) != EOF)
	{
	  printf("%I64d\n",a[n]);
	}
return 0 ;
}
