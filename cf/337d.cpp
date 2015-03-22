// File Name: 337d.cpp
// Author: darkdream
// Created Time: 2015年03月13日 星期五 20时18分05秒

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
#define maxn 100010
using namespace std;
int n , m, d; 
vector<int> mp[maxn];
int color[maxn];
int dis[maxn];
int dp[maxn];
int secdis[maxn];
int sum[maxn];
void dfs(int k , int la)
{
    if(color[k] == 1 )
	{
	   dp[k] = 1; 
	}
	dis[k] = d; 
	secdis[k] = d; 
	for(int i= 0;i < mp[k].size();i ++)
	{
	   if(mp[k][i] == la)
		   continue;
	   dfs(mp[k][i],k);
	   if(dis[mp[k][i]] >= 1  && dp[mp[k][i]] != 0) 
	   {
	       dp[k] += dp[mp[k][i]];
		   if(dis[mp[k][i]] - 1 <= dis[k])
		   {
		      secdis[k] = dis[k];
			  dis[k] = dis[mp[k][i]] - 1; 
		   }
	   }
	}
	sum[k] += dp[k];
}
void dfs1(int k,int la,int ladis,int laval)
{
	//printf("%d %d %d %d\n",k,la,ladis,laval);
	if(ladis < 0 || laval == 0)
	{
		laval = 0 ; 
	    ladis = d ; 
	}else{
	   sum[k] += laval;
	}
	for(int i = 0;i < mp[k].size();i ++)
	{
		int tt = laval;
		int ttd = ladis;
	    if(mp[k][i] == la)
			continue;
		//printf("***\n");
		if(dis[mp[k][i]] == dis[k]+1)
		{
		    ttd = min(ladis,secdis[k]);
		}else{
		    ttd = min(ladis,dis[k]);
		}
		if(dis[mp[k][i]] != 0)
		  tt += dp[k] - dp[mp[k][i]];
		else 
		  tt += dp[k];
		dfs1(mp[k][i],k,ttd-1,tt);
	}
}
int main(){
    scanf("%d %d %d",&n,&m,&d);
	int tmp = 0 ; 
	for(int i = 1;i <= m;i ++)
	{
	   scanf("%d",&tmp);
	   color[tmp] = 1;
	}
	int ta, tb;
	for(int i = 1;i < n;i ++)
	{
		scanf("%d %d",&ta,&tb);
		mp[ta].push_back(tb);
		mp[tb].push_back(ta);
	}
	dfs(1,0);
	dfs1(1,0,0,0);
	int ans = 0 ; 
	for(int i = 1;i <= n;i ++)
		if(sum[i] == m)
			ans ++;
	printf("%d\n",ans);
return 0;
}
