// File Name: hiho7.cpp
// Author: darkdream
// Created Time: 2014年08月18日 星期一 08时54分25秒

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
int n[505];
int v[505];
int dp[100006];
int main(){
  int k , m ; 
  scanf("%d %d",&k,&m);
  memset(dp,-1,sizeof(dp));
  dp[0] = 0 ; 
  for(int i =1;i <= k;i ++)
  {
      scanf("%d %d",&n[i],&v[i]);
	  for(int j =0 ;j <= m;j ++)
	  {
	     if(dp[j] != -1 && j + n[i] <= m)
		 {
		    dp[j+n[i]] = max(dp[j+n[i]],dp[j]+v[i]);
		 }
	  }
  }
  int mx = 0 ; 
  for(int j = 0 ;j <= m;j ++)
  {
    if(dp[j] > mx)
		mx = dp[j];
  }
  printf("%d\n",mx);
return 0;
}

