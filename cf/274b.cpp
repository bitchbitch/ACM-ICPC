// File Name: 274b.cpp
// Author: darkdream
// Created Time: 2015年03月12日 星期四 21时26分55秒

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
#define maxn 100105
using namespace std;
vector<int> mp[maxn];
LL v[maxn];
LL dp[maxn][2];
LL ans = 0 ;
void dfs(int k , int la)
{
  
   LL maxi = 0 ; 
   LL maxd = 0 ; 
  for(int i = 0 ;i < mp[k].size();i ++)
   {
       if(mp[k][i] == la)
		   continue;
	   dfs(mp[k][i],k);
	   maxi = max(maxi,dp[mp[k][i]][1]);
	   maxd = max(maxd,dp[mp[k][i]][0]);
   }
   v[k] += maxi;
   v[k] -= maxd;
   dp[k][0] = maxd;
   dp[k][1] = maxi;
   if(v[k] > 0)
	   dp[k][0] += v[k];
   else dp[k][1] += (-v[k]);
}
int main(){
   int n;
   scanf("%d",&n);
   for(int i = 1;i <n;i ++)
   {
	  int ta , tb; 
      scanf("%d %d",&ta,&tb);
	  mp[ta].push_back(tb);
	  mp[tb].push_back(ta);
   }
   for(int i = 1;i <= n;i ++)
   {
      cin >> v[i];
   }
   dfs(1,0);
  // for(int i = 1;i <= n;i ++)
  // {
  //    cout << dp[i][0] << " " << dp[i][1] << endl; 
  // }
   cout << dp[1][0] + dp[1][1] ;
return 0;
}
