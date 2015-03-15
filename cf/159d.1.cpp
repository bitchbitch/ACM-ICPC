// File Name: 159d.cpp
// Author: darkdream
// Created Time: 2014年07月30日 星期三 16时37分50秒

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

using namespace std;
#define LL long long 
char str[2005];
LL sum[2004];
LL tans[2004];
int dp[2000][2000];
int main(){
    scanf("%s",&str[1]);
	LL ans = 0 ; 
	int len =  strlen(&str[1]);
    memset(tans,0,sizeof(tans));
	for(int i = 1;i <= len ;i ++)
		dp[i][0] = 0; 
	sum[0] = 0 ;
	dp[1][1] = 1; 
	tans[1] = 1;
	sum[1] = 1; 
	for(int i = 2 ;i <=len ;i ++)
	{
		 dp[i][1] = 1; 
		 tans[i] = 1; 
		 ans += sum[i-1];
		 for(int j = 0;j <= tans[i-1];j ++)
		 {
		      if(str[i-dp[i-1][j]-1] == str[i])
			  {
			     ans += sum[i-dp[i-1][j]-2];
                 tans[i] ++ ;
				 dp[i][tans[i]] = dp[i-1][j] + 2;
			  }
		 }
		 sum[i] = sum[i-1] + tans[i];
	}
//	printf("%I64d\n",tans[2]);
	printf("%I64d\n",ans);
	return 0;
}

