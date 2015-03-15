// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年09月18日 星期四 23时54分49秒

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
int n , m , k ; 
LL sum[5005];
LL dp[5005][5005];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    memset(dp,0,sizeof(dp));
	int temp ;
	for(int i = 1;i <= n;i ++)
	{
	   scanf("%d",&temp);
	   sum[i] = sum[i-1] + temp;
	}
	int tt = n/m;
	for(int i = m;i <= n;i ++)
	{
	  for(int k = 1;k <= tt; k ++)
		{
		  dp[i][k] = max(dp[i-m][k-1] + sum[i] -sum[i-m],dp[i-1][k]);
		}
	}
	printf("%lld\n",dp[n][k]);
return 0;
}
