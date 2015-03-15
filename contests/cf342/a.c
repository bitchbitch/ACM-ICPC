// File Name: a.c
// Author: darkdream
// Created Time: 2013年09月07日 星期六 15时41分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int a[10];
int main(){
	int n ; 
	scanf("%d",&n);
    memset(a,0,sizeof(a));
    for(int i = 1;i <= n;i ++)
	{
	  int temp ;
	  scanf("%d",&temp );
	  if(temp == 5 || temp == 7)
	  {
	    printf("-1\n");
		return 0 ; 
	  }
	  a[temp] ++;
	}
	if(a[1] != a[2] + a[3])
	{
	  printf("-1\n");
	  return 0 ; 
	}
	if(a[4] + a[6] !=  a[2] + a[3])
	{
	  printf("-1\n");
	  return 0 ;
	}
	if(a[2] < a[4])
	{
	  printf("-1\n");
	  return 0 ;
	}
	for(int i =1 ;i <= a[4];i ++)
		printf("1 2 4\n");
	for(int i =1 ;i <= a[2]-a[4];i ++)
		printf("1 2 6\n");
	for(int i =1 ;i <= a[3];i ++)
		printf("1 3 6\n");



return 0 ;
}
