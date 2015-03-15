// File Name: 295b.cpp
// Author: darkdream
// Created Time: 2015年03月11日 星期三 19时13分13秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

using namespace std;
LL dp[505][505];
int de[505];
int hs[505];
int tmp[505][505];
LL ans[505];
int main(){
	int n ;  
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		for(int j= 1;j <= n ;j ++)
			scanf("%d",&tmp[i][j]);
	}
	for(int i = 1;i <= n;i ++)
		scanf("%d",&de[i]);
	for(int i = n ;i >= 1;i --)
	{
       hs[n-i+1]  = de[i];	
	}
    for(int i= 1;i <= n;i ++)
	{
	  for(int j = 1;j <= n; j ++)
	  {
	    dp[i][j] = tmp[hs[i]][hs[j]]; 
	  }
	}
	
    for(int k = 1; k <= n;k ++)
	{
	   for(int i = 1;i <= k;i ++)
	   {
	      for(int j = 1;j <= k;j ++)
		  {
             dp[i][j] = min(dp[i][j],dp[i][k] + dp[k][j]);
	//	     printf("%I64d ",dp[i][j]);
		  }
	//	  printf("\n");
	   }
	   LL sum = 0 ;
	   for(int i = 1;i <= k; i ++)
	   {
	      for(int j = 1;j <= k;j ++)
		  {
		     sum += dp[i][j];
		  }
	   }
	   ans[k] = sum; 
	}
	for(int i =n;i >=1; i --)
	{
	   printf("%I64d ",ans[i]);
	}
	printf("\n");

return 0;
}
