// File Name: 372b.cpp
// Author: darkdream
// Created Time: 2015年03月29日 星期日 20时52分13秒

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
#define maxn 45
using namespace std;
int n , m, q;
int dp[maxn][maxn][maxn];
int val[maxn][maxn];
int ans[maxn][maxn][maxn][maxn];
int mp[maxn][maxn];
void solve(int lx,int ly)
{
  memset(dp,0,sizeof(dp));
  for(int i = lx ;i <= n;i ++)
	 for(int j = ly ;j <= m;j ++)
	 {
	      for(int s = i ;s >= lx ; s --)
		  {
			if(mp[s][j] == 0 )
			{
		       dp[i][j][s] = dp[i][j-1][s] + 1; 
			   ans[lx][ly][i][j] += dp[i][j][s];
			}else{
			  break;
			}
		  }
		  ans[lx][ly][i][j] += ans[lx][ly][i-1][j] + ans[lx][ly][i][j-1] -  ans[lx][ly][i-1][j-1] ;
	 }
}
int main(){
    scanf("%d %d %d",&n,&m,&q);
    for(int i = 1;i <= n;i ++)
	{
	   for(int j = 1;j <= m;j ++)
	   {
		   scanf("%1d",&mp[i][j]);
	   }
	}
	for(int i =1 ;i <= n;i ++)
		for(int  j = 1;j <= m;j ++)
		{
			solve(i,j);
		}
	int lx,ly,rx,ry;
	while(q--)
	{
	    scanf("%d %d %d %d",&lx,&ly,&rx,&ry) ;
       printf("%d\n",ans[lx][ly][rx][ry]);
	}
return 0;
}
