// File Name: a.c
// Author: darkdream
// Created Time: 2013年08月16日 星期五 23时50分34秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int a[100];
int cmp(const void *a ,const void *b)
{
  return *(int *)a - *(int *)b;
}
int main(){


	 //freopen("/home/plac/problem/input.txt","r",stdin);
     //freopen("/home/plac/problem/output.txt","w",stdout);
  int n , m;
  scanf("%d %d",&n,&m);
  for(int i =1 ;i<= m;i ++)
	  scanf("%d",&a[i]);
  qsort(a+1,m,sizeof(int),cmp);
  int min = 10000 ;
  for(int i = n;i <= m; i ++)
     if(a[i] - a[i-n+1] < min)
		 min = a[i] - a[i-n+1];
  printf("%d\n",min);
return 0 ;
}
