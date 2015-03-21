// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年03月21日 星期六 14时55分57秒

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
int dp[500005][2];
vector<int> mp[500005];
int hs[500005];
int mxfrom[500005];
void dfs(int k)
{
	if(mp[k].size() == 0 )
	{
		dp[k][1] = 1;
		dp[k][0] = 0 ;
		return ; 
	}
	dp[k][1] = 1;
	for(int i = 0 ;i < mp[k].size();i ++)
	{
		dfs(mp[k][i]);
		dp[k][0] += dp[mp[k][i]][0];
		dp[k][1] += dp[mp[k][i]][0];
	}
	int tt = dp[k][0];
	for(int i = 0 ;i < mp[k].size();i ++)
	{
		if(tt < dp[k][0] - dp[mp[k][i]][0] + dp[mp[k][i]][1])
		{
			mxfrom[k] = mp[k][i];
			tt = dp[k][0] - dp[mp[k][i]][0] + dp[mp[k][i]][1];
		}
	}
	dp[k][0] = tt; 
}
int tt; 
int a[500005];
void findans(int k,int v)
{
	if(v == 1)
	{
		tt ++ ; 
		a[tt] = k ; 
	}
	for(int i = 0 ;i < mp[k].size(); i ++) 
	{
		if(mp[k][i] == mxfrom[k])
			findans(mp[k][i],1);
		else 
			findans(mp[k][i],0);
	}
}
int main(){
	freopen("grant.in","r",stdin);
	freopen("grant.out","w",stdout);
	int n; 
	scanf("%d",&n);
	int tmp ;
	for(int i= 2;i <= n;i ++)
	{
		scanf("%d",&tmp);
		mp[tmp].push_back(i);
	}
	dfs(1);
	printf("%d\n",dp[1][0]*1000);
	findans(1,0);
	sort(a+1,a+1+tt);
	for(int i = 1;i <= tt;i ++)
	{
		printf(i == 1?"%d":" %d",a[i]) ;    
	}
	printf("\n");
	return 0;
}
