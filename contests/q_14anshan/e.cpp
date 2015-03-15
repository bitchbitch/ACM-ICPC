// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年10月22日 星期三 12时16分10秒

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
int dp[200][60];
int mp[60][60];
int main(){
     int t; 
	 scanf("%d",&t);
	 while(t--)
	 {
		memset(mp,0,sizeof(mp));
		memset(dp,-1,sizeof(dp));
	    int n , m ; 
		scanf("%d %d",&n,&m);
		for(int i = 1;i <= m;i ++ )
			for(int j = 1;j <= m ;j ++)
				scanf("%d",&mp[i][j]);
		int t;
		scanf("%d",&t);
		dp[1][t] = 0 ;
		if(t == -1)
			for(int i = 1;i <= m;i ++)
				dp[1][i] = 0 ; 
		for(int i = 2;i <= n;i ++)
		{
	       	 scanf("%d",&t);
			 if(t == -1)
			 {
			    for(int j = 1; j <= m ;j ++)
				{
				  if(dp[i-1][j] != -1)
				  for(int s = 1;s <= m ;s ++)
					  dp[i][s] = max(dp[i][s],dp[i-1][j] + mp[j][s]);
				}
			 }else {
			    for(int s = 1;  s <= m; s ++)
				{
				  if(dp[i-1][s] != -1)
				    dp[i][t] = max(dp[i][t],dp[i-1][s] + mp[s][t]);
				}
			 }
			 //for(int j = 1;j <= m;j ++)
		}
		int mx = -1;
		for(int i = 1;i <= m;i ++)
			if(dp[n][i] > mx)
				mx = dp[n][i];
		printf("%d\n",mx);
		
	 }
return 0;
}
