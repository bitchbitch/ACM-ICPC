// File Name: b.c
// Author: darkdream
// Created Time: 2014年03月05日 星期三 19时08分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[200];
int cmp(const void * a ,const void *b)
{
  return *(int *)a - *(int *)b;
}
int main(){
  int n ; 
  while(scanf("%d",&n) != EOF)
  {
    if(n == 0 )
		break;
    for(int i = 1;i <= n;i ++)
	{
	  scanf("%d",&a[i]);
	}
	qsort(a+1,n,sizeof(int),cmp);
	int sum =0 ; 
	for(int i = 1;i <= n/2 + 1; i ++ )
	{
	  sum  += a[i]/2 + 1;
	}
	printf("%d\n",sum);
  }
return 0 ;
}
