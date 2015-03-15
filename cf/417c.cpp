// File Name: 417c.cpp
// Author: darkdream
// Created Time: 2015年03月12日 星期四 19时59分52秒

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
int n ,m  , c, d,k; 
int dp[111000];
int main(){
	scanf("%d %d %d %d %d",&c,&d,&n,&m,&k);
	memset(dp,-1,sizeof(dp));
	dp[0] = 0; 
	for(int i = 0 ;i <= n*m + d;i ++)
	{
      if(dp[i] != -1)
	  {
	      if(dp[i+n] ==-1)
			  dp[i+n] = dp[i] + c; 
		  else 
			  dp[i+n] = min(dp[i+n],dp[i] +c);
	  }
      if(dp[i] != -1)
	  {
	      if(dp[i+n] ==-1)
			  dp[i+n] = dp[i] + c; 
		  else 
			  dp[i+n] = min(dp[i+n],dp[i] +c);
		  if(dp[i+1] == -1)
			  dp[i+1] = dp[i] + d; 
		  else 
			  dp[i+1] = min(dp[i+1],dp[i] +d);
	  }
	}
	int mi = dp[n*m-k] ;
	for(int i= n*m-k;i <= n*m +n ;i ++)
	{
        mi = min(mi,dp[i]);	
	}
	printf("%d\n",mi);
return 0;
}
