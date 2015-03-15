// File Name: a.c
// Author: darkdream
// Created Time: 2014年04月27日 星期日 23时27分53秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000];
int cmp(const void * a ,const void *b)
{
  return *(int *)a - *(int *)b;
}
int main(){
   int n , m ; 
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= n;i ++)
	   scanf("%d",&a[i]);
   qsort(a+1,n,sizeof(int),cmp);
   int sum = 0 ; 
   for(int i =1 ;i < n;i++)
      sum += a[i];
   if(sum <= m )
	   printf("YES\n");
   else printf("NO\n");
return 0 ;
}
