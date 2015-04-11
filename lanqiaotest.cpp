/************************************************************
 * Author : darkdream
 * Email : cijianzy@gmail.com 
 * Last modified : 2015-04-11 19:06
 * Filename : lanqiaotest.cpp
 * Description :
 * *********************************************************/
// File Name: lanqiaotest.cpp
// Author: darkdream
// Created Time: 2015年04月11日 星期六 18时56分47秒

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
LL dp[15][15][15];
int main(){

	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= 13; i ++)
		dp[0][i][0] = 1; 
	for(int i = 1;i <= 13 ;i ++)
	{
	   for(int j = 1;j <= 13; j ++)
	   {
	      for(int s = 1; s <= 4 ; s ++)
			  dp[i][j][s] += dp[i-1][j][s-1];
		  for(int k = 1;k <  j ;k ++)
		  {
		    for(int s = 1; s <= 4; s ++)
			{
			  dp[i][j][1] += dp[i-1][k][s];
			}
		  }
	   }
	}
	LL sum = 0 ; 
   for(int i = 1;i <= 13 ;i ++)
   {
	   for(int j = 1;j <= 4; j ++)
	   {
		   printf("%lld ",dp[13][i][j]);
		   sum += dp[13][i][j];
	   }
	   printf("\n");
   }
   printf("%lld\n",sum);
return 0;
}
