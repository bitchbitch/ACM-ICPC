// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 00时10分50秒

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
LL n ,k,d;
int dp[1004][1004];
int check()
{
   LL t = 1;
   for(int i = 1;i <= d ;i ++)
   {
      t = t * k ; 
	  if(t >= n)
		  return 0 ;
   }
   printf("-1\n");
   return 1;
}
int main(){
	scanf("%I64d %I64d %I64d",&n,&k,&d);
	if(check())
		return 0 ;
	for(int i =1;i <= d;i ++)
		dp[i][1] = 1; 
    int t = 0 ; 
	for(int i = 2;i <= n;i ++)
	{	
		t = 1 ; 
		for(int j = 1;j <= d;j ++)
		{
	       t = dp[j][i-1] + t; 
           if(t == k+1)
		   {
		     dp[j][i] = 1; 
		   }else {
		     dp[j][i] = t;
		   }
		   t = t /(k+1);
		}
	}
	for(int i = 1;i <= d;i ++)
	{	
		for(int j = 1;j <= n;j ++)
	      printf("%d ",dp[i][j]);
		printf("\n");
	}	
	return 0;
}
