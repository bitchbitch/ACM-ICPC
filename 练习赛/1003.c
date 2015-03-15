// File Name: 1003.c
// Author: darkdream
// Created Time: 2013年03月08日 星期五 19时07分54秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000000];
int comp(const void *a, const void *b)
{
  return  *(int*)b -*(int *)a;
}
int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
    int n , j = 0 ;
	while(scanf("%d",&n) != EOF)
	{
	  int t = j ;
	  for(; j < t + n ; j ++)
	  {
	   scanf("%d",&a[j]);

	  }
	}
	qsort(a,j,sizeof(int), comp);
	printf("%d",a[0]);
	for(int i = 1 ;i <  j ; i++)
		printf(" %d",a[i]);
return 0 ;
}
