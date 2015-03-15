// File Name: inflate.c
// Author: darkdream
// Created Time: 2014年01月14日 星期二 15时22分59秒
/*
ID: dream.y1
PROG: inflate
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int dp[10005];
int main(){
	freopen("inflate.in","r",stdin);
	freopen("inflate.out","w",stdout);
	
	int n , m; 
	scanf("%d %d",&n,&m);
	memset(dp,-1,sizeof(dp));
	dp[0] = 0 ; 
	for(int i = 1;i <= m; i++)
	{
	   int ta,tb;
	   scanf("%d %d",&ta,&tb);
	   for(int j = 0 ;j <=n ; j ++ )
	   {
	       if(j + tb <=n && dp[j] != -1)
		   {
		      if(dp[j+tb] < dp[j] + ta)
				 dp[j+tb] = dp[j] + ta;
		   }
	   }
	
	}
	int max = 0 ; 
	for(int i= 1;i <= n;i ++)
		if(dp[i] > max)
			max = dp[i];
	printf("%d\n",max);

	return 0 ;
}
