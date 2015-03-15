// File Name: lanqiao.c
// Author: darkdream
// Created Time: 2014年03月11日 星期二 20时30分11秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int temp;
int hs[2000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int n ;
  scanf("%d",&n);
  int t = 0 ; 
  int max = -1, min = 1e8;
  int a, b ; 
  while(scanf("%d",&temp)!= EOF);
  {
	if(temp < min )
		min = temp;
	if(temp > max )
		max = temp;

	if(hs[temp])
		b = temp;
    hs[temp] ++; 
  } 
  for(int i = min;i <= max; i ++)
	  if(!hs[i])
		  a = i ; 
  printf("%d %d\n",a,b);
return 0 ;
}
