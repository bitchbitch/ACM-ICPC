/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2015-03-09 20:32
 * Filename : 294b.cpp
 * Description :
 * *********************************************************/
// File Name: 294b.cpp
// Author: darkdream
// Created Time: 2015年03月09日 星期一 20时04分53秒

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
struct node{
  int t , w; 
}a[200];
int dp[200][300];
int main(){
    int n; 
	scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
	int total = 0 ; 
	for(int i = 1;i <= n;i ++)
	{
	  scanf("%d %d",&a[i].t,&a[i].w);
	  total += a[i].t ;
	}
	dp[0][0] = 0 ;
	int mi = 1e9 ; 
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 0 ;j <= total;j ++)
		{
		   dp[i][j]  = dp[i-1][j];
		}
        for(int j = 0 ;j <= total;j ++)
		{
	       if(dp[i-1][j] != -1)
		   {
		      if(dp[i-1][j+a[i].t] == -1)
				  dp[i][j+a[i].t] = dp[i-1][j] + a[i].w; 
			  else dp[i][j+a[i].t] =  min(dp[i][j+a[i].t],dp[i-1][j] + a[i].w);
		   }
		}
	}
	for(int i = 1;i <= n;i ++)
	{
		for(int j= 0 ;j <= total ;j ++)
		{
		 // printf("%d ",dp[i][j]);
		  if(dp[i][j] <= total -j && dp[i][j] != -1)
			  mi = min(mi,total - j );
		}
		//printf("\n");

	}
	printf("%d\n",mi);
return 0;
}
