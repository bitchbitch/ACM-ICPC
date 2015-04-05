// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月05日 星期日 10时00分34秒

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
int dp[1000000];
int a[4];
int w[4];
int main(){
	printf("%d\n",1/2*3);
    w[1] = 1007 ;
	w[2] = 1005;
	a[1] = 9063;
    a[2] = 9045;
	memset(dp,-1,sizeof(dp));
	dp[0] = 1; 
	for(int i = 1;i <= 2;i ++)
	{
	    for(int j =0 ; j <= 150000 ;j ++)
		{
		   if(dp[j] != -1)
		   {
		     dp[j+w[i]] = max(dp[j+w[i]],dp[j] + a[i]);}
		}
	}
	int mx =0 ; 
	for(int i = 112411;i >= 0 ;i --)
	{
		mx = max(dp[i],mx);
	}
	printf("%d\n",mx);
return 0;
}
