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
int secdp[maxn];
void dfs(int k , int la)
{
    
    if(color[k] == 1 )
	{
	   dp[k] = 1; 
	}
	dis[k] = d; 
	for(int i= 1;i < mp[k].size();i ++)
	{
	   if(mp[k][i] == la)
		   continue;
	   dfs(mp[k][i].k);
	   if(dis[mp[k][i]] >= 1  && dp[mp[k][i]] != 0) 
	   {
	       dp[k] += dis[mp[k][i]];
		   if(dis)
	   }
	}
}
int main(){
    scanf("%d %d %d",&n,&m,&d);
	for(int i = 1;i <= m;i ++)
	{
	   scanf("%d",&color[i]);
	}
	int ta, tb;
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d %d",&ta,&tb);
		mp[ta].push_back(tb);
		mp[tb].push_back(ta);
	}
return 0;
}
