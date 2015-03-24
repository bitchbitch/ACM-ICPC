// File Name: 120F.cpp
// Author: darkdream
// Created Time: 2015年03月24日 星期二 14时51分16秒

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
#define maxn 105
using namespace std;
int dp[maxn];
int n;
int mx;
vector<int> mp[maxn];
void dfs(int k ,int la)
{
    for(int i = 0 ;i < mp[k].size() ;i ++)
	{
	   if( mp[k][i] == la)
		   continue;
	   dfs(mp[k][i],k);
	   mx = max(mx,dp[k] + dp[mp[k][i]]+1);
	   dp[k] = max(dp[k],dp[mp[k][i]] + 1);
	}
}
int main(){
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
	int t; 
  scanf("%d",&t);
  int sum = 0; 
  while(t--)
  {
     scanf("%d",&n);
     for(int i= 1 ;i <= 100 ;i ++)
		 mp[i].clear();
	 memset(dp,0,sizeof(dp));
	 for(int i = 1;i < n;i ++)
	 {
	   int ta , tb ; 
	   scanf("%d %d",&ta,&tb);
	   mp[ta].push_back(tb);
	   mp[tb].push_back(ta);
	 }
	 mx = 0 ; 
	 dfs(1,0);
	 //printf("***%d\n",mx);
	 sum += mx;
  }
  printf("%d\n",sum);
  
return 0;
}
