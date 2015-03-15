// File Name: game2.c
// Author: darkdream
// Created Time: 2014年04月09日 星期三 20时54分08秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
struct node{
  int a, b; 
}dp[300][300];
int max(int a, int b)
{
  if(a > b )
	  return a; 
  return b ;
}
int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n ;
   scanf("%d\n",&n);
   int a[200];
   memset(dp,0,sizeof(dp));
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
   }

   for(int i = 1;i <= n;i ++)
	   for(int j = n-i;j >= 0;j --)
	   {
	       if((n - j ) % 2== 0 )
		   {
			  dp[i][j].b = max()
              dp[i][j].a = max(dp[i][j+1].a + a[i+j+1], dp[i-1][j].a + dp[i][j+1].a); 
		   }else{
              dp[i][j].b = max(dp[i][j+1].b + a[i+j+1], dp[i-1][j].a + dp[i][j+1].b); 
		   
		   }
	   }
   for(int i = 1;i <= n;i ++)
	   printf("%d %d\n",dp[i][0].a,dp[i][0].b);
return 0 ;
}
