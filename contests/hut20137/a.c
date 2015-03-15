// File Name: a.c
// Author: darkdream
// Created Time: 2013年09月09日 星期一 16时26分46秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
LL dp[1000][1000][2];
LL n, k;

int main(){
	while(scanf("%lld %lld",&n,&k) != EOF)
	{
      memset(dp,0,sizeof(dp));
	  dp[1][0][0] = 1;
	  for(LL i = 2;i <= 2*n ;i ++)
	   for(LL j = 0 ; j <= n; j ++)
	   {
           
	   }
	 printf("%lld\n",dp[2*n][n][1]);
	}

return 0 ;
}
