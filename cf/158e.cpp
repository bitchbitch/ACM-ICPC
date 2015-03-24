// File Name: 158e.cpp
// Author: darkdream
// Created Time: 2015年03月24日 星期二 16时35分24秒

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
struct work{
  int si ,di;
}works[5000];
int dp[5000][5000];
int n , k ; 
int main(){
	scanf("%d %d",&n,&k);
	int tx, ty;
	int mx = 0 ; 
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d %d",&tx,&ty);
		for(int j = 0 ;j <= k ;j ++)
		   dp[i][j] = 1e9;
		for(int j = 0 ;j <= k ;j ++)
		{
		    if(dp[i-1][j] <= tx ) 
			{
				mx = max(tx - dp[i-1][j]-1,mx);
			    dp[i][j] =min(tx + ty-1,dp[i][j]);
			}else{
			    dp[i][j] =min(dp[i-1][j] + ty,dp[i][j]);
			}
			dp[i][j+1] = min(dp[i][j+1],dp[i-1][j]);
		    //printf("%d ",dp[i][j]);
		}
		//printf("\n");
	}
//	printf("%d\n",dp[4][1]);
	mx = max(86400 -  dp[n][k],mx);
	printf("%d\n",mx);
return 0;
}
