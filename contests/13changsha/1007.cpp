// File Name: 1007.cpp
// Author: darkdream
// Created Time: 2014年11月11日 星期二 13时57分33秒
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
#define maxn 500
using namespace std;
double dp[2][500];
double  mp[maxn][maxn];
int main(){
   int m,n;  
   while(scanf("%d",&m) != EOF)
   {
      int n = (m)*(m-1)*(m-2)/6;
	  for(int i = 0;i < n;i ++)
		  for(int j = 0;j < n ;j ++)
			  scanf("%lf",&mp[i][j]);
	  memset(dp,0,sizeof(dp));
	  for(int i = 0 ;i < n;i ++)
	  {
	      dp[0][i] = 1; 
	  }
	  int q; 
	  int t; 
	  scanf("%d",&q);
	  for(int i = 1;i <= q;i ++)
	  {
	    scanf("%d",&t);
		for(int j = 0 ;j < n ;j ++)
		{
		  double k = dp[0][j] * mp[j][t];
		  if(k > dp[1][j])
			  dp[1][j] = k ; 
		  if(k > dp[1][t])
			  dp[1][t] = k ; 
		}
		memcpy(dp[0],dp[1],sizeof(dp[0]));
		memset(dp[1],0,sizeof(dp[1]));
	/*	for(int j = 0 ;j < n ;j ++)
			printf("%lf ",dp[i][j]);
		printf("\n");*/
	  }
	  double mx = 0 ; 
	  for(int i = 0;i< n;i ++)
		  mx = max(dp[0][i],mx);
	  printf("%.7lf\n",mx);
   }
return 0;
}
