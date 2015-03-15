// File Name: a.c
// Author: darkdream
// Created Time: 2014年03月22日 星期六 22时33分00秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int n ; 
int a[200];
int cmp(const void * a ,const void *b)
{
   return *(int *)a - *(int *)b ; 
}
int main(){
    
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
	   scanf("%d",&a[i]);
   qsort(a+1,n,sizeof(int),cmp);
   for(int i =1 ;i <=n;i ++)
	   printf("%d ",a[i]);

return 0 ;
}
