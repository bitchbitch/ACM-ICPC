// File Name: 245h.dp.cpp
// Author: darkdream
// Created Time: 2015年03月30日 星期一 15时27分10秒

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
#define maxn 5005
using namespace std;
int dp[maxn][maxn];
char str[maxn];
int n; 
int main(){
	scanf("%s",&str[1]);
    n = strlen(&str[1]);
    for(int i = 1;i <= n;i ++)
	{
	  if(str[i] == str[i+1]) 
		  dp[i][i+1] = 1;
	  dp[i][i] = 1; 
	}
	for(int i = n;i >= 1;i --)
	{
       for(int j = i+1;j <= n;j ++)
	   {
	      if(dp[i+1][j-1] == 1&& str[i] == str[j]) 
		  {
		    dp[i][j] = 1; 
		  }
	   }
	}
	for(int i = n;i >= 1;i --)
      for(int j = i ;j <= n ;j ++)
	  {
	    dp[i][j] += dp[i+1][j] + dp[i][j-1] -dp[i+1][j-1];
	  }
	int q; 
	scanf("%d",&q);
	while(q--)
	{
	  int l , r ;
	  scanf("%d %d",&l,&r);
	  printf("%d\n",dp[l][r]);
	}
return 0;
}
