// File Name: a.c
// Author: darkdream
// Created Time: 2014年02月26日 星期三 23时27分59秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int hs[200];
int main(){
    int n ; 
	scanf("%d",&n);
	int a,b;
	scanf("%d %d",&a,&b);
    for(int i =2 ;i <= n;i ++)
	{
		int c, d; 
		scanf("%d %d",&c,&d);
		for(int i = c;i <= d -1 ;i ++)
			hs[i] = 1; 
	}
	int sum = 0; 
	for(int i = a;i <= b-1;i ++)
		if(!hs[i])
			sum ++ ;
	printf("%d\n",sum);
return 0 ;
}
