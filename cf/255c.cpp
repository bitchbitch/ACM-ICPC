// File Name: 255c.cpp
// Author: darkdream
// Created Time: 2015年03月10日 星期二 16时26分53秒

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
#define maxn 4005
using namespace std;
int dp[maxn][maxn];
int pre[maxn][maxn]; 
int a[maxn];
int hs[1000005];
int main(){
    int n ; 
    scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
	     scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i ++)
	{
	     for(int j = i+1 ;j <= n  ;j ++)
		 {
		      pre[i][j] = hs[a[j]]; 
		 }
		 hs[a[i]] = i ; 
	}
    memset(dp,0,sizeof(dp));
	int ans = 1 ; 
	for(int i = 1;i<=n;i ++)
	{
	   dp[i][0] = 1; 
	   for(int j = 1;j < i;j ++)
	   {
	      dp[i][j] = dp[j][pre[j][i]] + 1;
	      ans = max(ans,dp[i][j]);
	   }
	}
    printf("%d\n",ans); 
return 0;
}
