// File Name: 461c.cpp
// Author: darkdream
// Created Time: 2015年03月11日 星期三 10时53分22秒

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
#define M 1000000007
using namespace std;
int color[100005];
LL dp[100005][2];
int n; 
vector<int> mp[100005]; 
int dfs(int k ,int la)
{
	 if(color[k])
	    dp[k][1] = 1; 
	 dp[k][0] = dp[k][1]^1;
	 for(int i = 0 ;i < mp[k].size(); i ++)
	 {
	     if(mp[k][i] == la ) 
			 continue;
		 int y = mp[k][i];
		 dfs(y,k);
         LL t1 = dp[k][0] *(dp[y][0]+dp[y][1]) ;
		 LL t2 = dp[k][1] *(dp[y][0] + dp[y][1]) + dp[k][0]*dp[y][1];
		 dp[k][0] = t1 % M; 
		 dp[k][1] = t2 % M;
		 
	 }
     
}
int main(){
      scanf("%d",&n);
	  for(int i = 0;i < n - 1;i ++)
	  {
	     int p ; 
		 scanf("%d",&p);
		 mp[p].push_back(i+1);
		 mp[i+1].push_back(p);
	  }
	  for(int i = 0 ;i < n;i ++)
	  {
	     scanf("%d",&color[i]);
	  }
	  dfs(0,0);
      printf("%I64d\n",dp[0][1]);	
return 0;
}
