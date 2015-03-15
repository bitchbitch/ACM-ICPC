// File Name: a.c
// Author: darkdream
// Created Time: 2014年04月06日 星期日 23时27分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int a[200];
int b[200];
int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n , m ; 
   scanf("%d %d",&n,&m);
   memset(b,0,sizeof(b));
   for(int i = 1;i <= m;i ++)
	  {   int temp ; 
		  scanf("%d",&temp);
		  for(int i = temp ;i <= n;i ++)
		  {
		    if(b[i])
				break;
			else b[i] = temp ; 
		  }
	  }
   for(int i = 1;i<= n;i ++)
	   printf("%d ",b[i]);
return 0 ;
}
