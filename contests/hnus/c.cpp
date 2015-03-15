// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年09月12日 星期五 09时24分44秒

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
char str[1000];
int a[600];
int dp[505][505];
int main(){
	int n ; 
	while(scanf("%d",&n) != EOF,n)
	{
		scanf("%s",str);
		//n = strlen(str);
		for(int i = 1;i <= n;i ++)
		{
			if(str[i-1] == 'A')
			{
				a[i] = 1;
			}else if(str[i-1] == 'U'){
				a[i] = -1;
			}else if(str[i-1] == 'G'){
				a[i] = 2;
			}else if(str[i-1] == 'C'){
				a[i] = -2;
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i = 3;i <= n; ++i)
		{
			for(int j = i-2;j >= 1; --j)
			{
				int t = 0 ; 
				for(int s = j + 1; s < i ;++s)
					if(dp[i][s] + dp[s-1][j] > t)
					{
						t = dp[i][s] + dp[s-1][j];
					}
				dp[i][j] = t ;
				if(a[i] + a[j] == 0 )
				{
					dp[i][j] = max(dp[i][j],dp[i-1][j+1] + 1);
				}
			}
		}
		printf("%d\n",dp[n][1]);
	}
	return 0;
}
