// File Name: gam3.c
// Author: darkdream
// Created Time: 2014年04月15日 星期二 19时49分52秒
/*
ID: dream.y1
PROG: game1
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
int sum[300][300];
int dp[300][300];
int min(int a, int b)
{
   return b > a ?a:b;
}
int main(){

   freopen("game1.in","r",stdin);
   freopen("game1.out","w",stdout);
   int n ; 
   scanf("%d",&n);
   int a[300];
   memset(sum,0,sizeof(sum));
   for(int i = 1;i <= n;i ++)
   {
       scanf("%d",&a[i]);
	   for(int s = i ;s >= 1; s--)
	   for(int j = i ;j <= n; j ++)
	   {
	     sum[s][j] += a[i];
	   }
   }
   for(int i = n;i >= 1;i --)
   {
      for(int j = i; j <= n; j ++)
		  dp[i][j] = sum[i][j] - min(dp[i][j-1],dp[i+1][j]);
   }
   printf("%d %d\n",dp[1][n],sum[1][n] - dp[1][n]);
return 0 ;
}
