// File Name: 463b.cpp
// Author: darkdream
// Created Time: 2015年03月10日 星期二 08时28分49秒

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
#include<queue>
#define LL long long

using namespace std;
int dp[6][1005][1005];
int a[1005];
vector<int> mp[1005];
int vis[1005];
int ans[1005];
int ru[1005];
int n, k ;
queue<int> qu;
void solve()
{
    qu.clear();	
    memset(vis,0,sizeof(vis));
	for(int i = 1;i <= n;i ++)
	{
        if(ru[i] == 0)
		{
			qu.push(i);
		}
	}
	while(!qu.empty())
	{
	   int tmp = qu.front();
	   qu.pop();
	   
	}
}
int main(){
   scanf("%d %d",&n,&k);
   for(int i = 1;i <= k;i ++)
   {
      for(int j = 1;j <= n;j ++)
	  {
		  scanf("%d",&a[j]);
		  for(int s = 1; s < j ;s ++)
		  {
		       if(a[j] > a[s])
			   {
			      dp[i][a[s]][a[j]] = 1; 
			   }
		  }
	  }
   }
   for(int i = 1;i <= n;i ++)
   {
      for(int j = 1;j <= n;j ++)
	  {
		dp[0][i][j] = dp[1][i][j];
	    for(int s = 2; s <= k ;s ++)
		{
		  dp[0][i][j] = dp[0][i][j] & dp[s][i][j];
		}
	    if(dp[0][i][j] ==  1)
		{
			ru[j] ++ ; 
			mp[i].push_back(j);
		}
	  }
   }
   solve()
   printf("%d\n",ans);
return 0;
}
