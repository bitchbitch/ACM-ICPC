// File Name: 4727.c
// Author: darkdream
// Created Time: 2013年09月11日 星期三 18时02分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int a[110000];
int main(){
    int t;
	scanf("%d",&t);
    for(int ca = 1; ca <= t; ca ++)
	{
	 int n; 
	 scanf("%d",&n);
	 int set = 0 ;
	 for(int i = 1;i <= n;i ++)
	 {
	   scanf("%d",&a[i]);
	   if(i!= 1)
	     if(a[i]!= a[i-1]+1)
			 set = i ; 
	 }
	 
	 printf("Case #%d: %d\n",ca,set);
	 
	}

return 0 ;
}
