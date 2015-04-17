// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月17日 星期五 10时05分38秒

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
int T;
char str[1005];
int dp[1005][1005];
int main(){
	scanf("%d",&T);
	for(int ca = 1;ca <= T;  ca ++){
		scanf("%s",&str[1]);
		int n = strlen(&str[1]);
		memset(dp,0,sizeof(dp));
		for(int i = n ;i >= 1 ;i --)
			for(int  j = i;j <= n;j ++)
			{
				dp[i][j] = (dp[i][j] + dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1])%100007;
				if(str[i] == str[j]){
					dp[i][j] = (dp[i][j] + 1 + dp[i+1][j-1])%100007;
				}
			}
		printf("Case #%d: %d\n",ca,dp[1][n]);
	}
   
return 0;
}
