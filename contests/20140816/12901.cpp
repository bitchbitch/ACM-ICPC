// File Name: 12901.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 14时18分16秒

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
int dp[1000005][5];
int a[3];
int max3(int x, int y,int z)
{
	if(y > x )
		x = y ;
	if(z > x )
		x = z ; 
	return x;
}
int main(){
	int n ;
	while(scanf("%d",&n)!= EOF)
	{
		int ans = 0 ;
		memset(dp,0,sizeof(dp));
		for(int i =1 ;i <= n;i ++)
		{
			scanf("%d %d %d",&a[0],&a[1],&a[2]); 
			dp[i][0] = max3(dp[i-1][0],dp[i-1][1],dp[i-1][2]); 
			dp[i][1] = dp[i-1][0] + a[0];
			if(i != 1)
				dp[i][2] = a[1] + max(dp[i-1][3],dp[i-1][4]);
			if(i != n)
			{ 
				dp[i][3] = a[1] + dp[i-1][0];
				if(i !=1)
			      dp[i][4] = a[2] + max(dp[i-1][3],dp[i-1][4]); 
			}
			for(int j = 0;j <= 4;j ++)
			{ 
				ans = max(dp[i][j],ans);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
