// File Name: nocows.cpp
// Author: darkdream
// Created Time: 2013年12月12日 星期四 09时07分51秒

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
/*
ID: dream.y1
PROG: nocows
LANG: C++
*/
using namespace std;
#define M 9901
int dp[105][150][205];
int n , m ;
int ans = 0 ;
int f[150][150];
int main(){
	freopen("nocows.in","r",stdin);
	freopen("nocows.out","w",stdout);
	memset(f,0,sizeof(f));
	memset(dp,0,sizeof(dp));
	clock_t be,en;
	for(int i = 1;i <= 100;i ++)
		f[i][i] = f[i][0] = 1;
	for(int i= 2;i <= 100;i ++)
		for(int j = 1;j < i; j ++)
			f[i][j] = (f[i-1][j] + f[i-1][j-1])%M;
	scanf("%d %d",&n,&m);
	dp[1][1][n-1] = 1; 
	for(int i = 2;i <= m;i ++)
	{
	   for(int j= 1;j <= 150 ;j ++)
		   for(int t = 2;t <= n-j; t += 2)
		   {
		     if(dp[i-1][j][t])
			 {
			    for(int s = 2;s <= t && s/2 <= j;s += 2)
				{
				    dp[i][s][t-s] = (dp[i][s][t-s] +dp[i-1][j][t]* f[j][s/2]) % M;
				}
			 }
		   }

	}
	for(int i = 1;i <= 100;i ++)
         ans += dp[m][i][0] ;
	printf("%d\n",ans % M);
	return 0;
}
