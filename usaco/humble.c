// File Name: humble.c
// Author: darkdream
// Created Time: 2014年01月14日 星期二 15时51分00秒
/*
ID: dream.y1
PROG: humble
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int num[2000000];
long long  big ;
int n ,m; 
int a[200];
int k = 0; 
void dfs(int t,int l)
{
   k ++; 
   for(int i = l;i <= n;i ++)
	   if( t  *1ll *a[i] < big)
		   dfs(t*a[i],i);
}
int cmp(const void * a, const void *b)
{
   if(*(int *)a > *(int *)b )
	     return 1;
   else return 0;
}
int main(){ 
   freopen("humble.in","r",stdin);
   //freopen("humble.out","w",stdout);
  big = 1LL << 31;
  scanf("%d %d",&n,&m);
  for(int i =1;i <= n;i ++)
	  scanf("%d",&a[i]);
  dfs(1,1);
  //qsort(num+1,k,sizeof(int),cmp);
  printf("%d\n",k);
  return 0 ;
}
