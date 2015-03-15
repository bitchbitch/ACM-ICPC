// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月11日 星期四 20时09分52秒

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
int a[10005];
int dp[10005][102];
int main(){
  int n, m; 
  scanf("%d %d",&n,&m);
  for(int i = 1;i <= n;i ++)
  {
     scanf("%d",&a[i]);
	 a[i] = a[i] % m; 
  }
  memset(dp,0,sizeof(dp));
  dp[1][abs(a[1])] = 1;
  for(int i = 2;i <= n;i ++)
  {
      for(int j = 0 ;j < m;j ++)
	  {
        if(dp[i-1][j])
		{
			  dp[i][abs(j-a[i])%m] = 1; 
			  dp[i][abs(j+a[i])%m] = 1; 
		}
	  }
  }
  if(dp[n][0])
	  printf("Divisible\n");
  else printf("Not divisible\n");
  
return 0;
}
