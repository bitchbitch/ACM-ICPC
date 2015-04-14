// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年04月14日 星期二 20时35分51秒

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

using namespace std;
int dp[1005][136];
struct node{
  int r,c; 
  node(){}
  node(int _r, int _c)
  {
	r = _r;
	c = _c;
  }
}from[1004][136];
int a[1005];
int m ,s; 
int mp[150][150];
int ABS(int x)
{
  if(x < 0 )
	  return -x;
  return x;
}
int n; 
void print(int r, int c ,int d)
{
   //printf("%d %d\n",r,c);
   if(d == n)
   {
	   printf("%d ",c);
	   return ;
   }
   print(from[n+1-d][r].r,from[n+1-d][r].c, d + 1);
   printf("%d ",c);
}
int main(){
	freopen("quant.in","r",stdin);
	freopen("quant.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&a[i]);
	scanf("%d %d",&m,&s);
	for(int i = 0 ;i < m;i ++)
		for(int j = 0 ;j <  s; j ++)
			scanf("%d",&mp[i][j]);
	memset(dp,-1,sizeof(dp));
	dp[1][0] = 0;
	for(int i= 1;i <= n;i ++)
	{
		for(int j =  0 ;j < m;j ++)
		{
			if(dp[i][j] == -1)
				continue;
			for(int  t = 0 ;t <  s ; t ++)
			{
				if(dp[i+1][t&(m-1)] == -1 || dp[i][j] + ABS(mp[j][t] - a[i]) < dp[i+1][t&(m-1)])
				{
					dp[i+1][t&(m-1)] = dp[i][j] + ABS(mp[j][t] - a[i]);
					from[i+1][t&(m-1)] = node(j,t);
				}
			}
		}
	}
	int mi = 1e9 + 10000; 
	int si = 0 ; 
	for(int i = 0 ;i < m ;i ++ )
	{
		if(dp[n+1][i] != -1 && dp[n+1][i]  < mi)
		{
			mi = dp[n+1][i];
			si = i ; 
		}
	}
	printf("%d\n",mi);
	print(from[n+1][si].r,from[n+1][si].c,1);
return 0;
}
