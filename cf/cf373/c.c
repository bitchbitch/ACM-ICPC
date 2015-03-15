// File Name: c.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 22时44分30秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int cmp(const void *a ,const void *b)
{
  return *(int *)a - *(int *)b;
}
int a[500005];
int b[500005];
int main(){
  int n ;
  scanf("%d",&n);
  for(int i = 1;i <= n;i ++)
	  scanf("%d",&a[i]);
  qsort(a+1,n,sizeof(int),cmp);
/*  for(int i = 1;i <= n;i ++)
	  printf("%d ",a[i]);
  printf("\n");*/
  int k = 0 ; 
  for(int i = n/2+1;i <= n;i ++)
  {
    b[++k] = a[i]/2;
  }
/*  for(int i = 1;i <= k;i ++)
	  printf("%d ",b[i]);
  printf("\n");*/
  int j = 1 ;
  int i;
  for(i = 1;i <= n/2;i ++)
  {
	 if(j >  k )
		 break;
     while(b[j] < a[i])
	 {
	   j ++;
	   if(j > k)
		   break;
	 }
	 if(j > k )
		 break;
	 j++;
  }
  //printf("%d\n",i);
  printf("%d\n",n-i+1);
  return 0 ;
}
