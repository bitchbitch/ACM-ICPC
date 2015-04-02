// File Name: poj1741.cpp
// Author: darkdream
// Created Time: 2014年10月05日 星期日 08时06分24秒

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
#define maxn 20010
using namespace std;
int ans; 
int ansv;
int mx[maxn];
int sum[maxn];
int visit[maxn];
vector<int> mp[maxn];
void dfs(int k)
{
	//printf("%d\n",k);
	int num = mp[k].size();
	sum[k] = 1;
    for(int i = 0; i < num;i ++ )
	{
       if(!visit[mp[k][i]])
	   {
		 visit[mp[k][i]] = 1;
	     dfs(mp[k][i]);
		 mx[k] = max(sum[mp[k][i]],mx[k]);
		 sum[k] += sum[mp[k][i]]; 
	   }
	}
}
int main(){
   int t; 
   scanf("%d",&t);
   while(t--)
   {
      int n ;
	  scanf("%d",&n);
	  int u, v;
	  for(int i = 1;i <= n;i ++)
		  mp[i].clear();
	  for(int i = 1;i < n;i ++ )
	  {
	    scanf("%d %d",&u,&v);
        mp[u].push_back(v);
        mp[v].push_back(u);
	  }
	  memset(mx,0,sizeof(int)*(n+1));
	  memset(visit,0,sizeof(int)*(n+1));
	  visit[1] = 1;
	  dfs(1);
	  ansv = 1e9; 
	  for(int i = 1;i <= n;i ++)
	  {
		 int tmx = max(sum[1] - sum[i],mx[i]);
	     if(tmx < ansv)
		 {
		   ans  = i;
		   ansv = tmx;
		 }
	  }
	  printf("%d %d\n",ans,ansv);
   }
return 0;
}
