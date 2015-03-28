// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 12时13分56秒

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
int t;
int n ;
int sum ;
int dp[10005];
int main(){
    scanf("%d",&t);
	while(t--)
	{
		sum = 0 ; 
		int tt = 0 ;
		scanf("%d",&n);
		int ta, tb; 
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		int tsum = 0 ; 
		for(int i = 1;i <= n; i ++)
		{
		   scanf("%d %d",&ta,&tb);
		   
          if(ta == 2 )
			  sum += tb;
		  else{
			 tsum += tb ;
		     for(int i = tsum;i >= 0 ;i -- )
			 {
			   if(dp[i] != 0 )
			   {
			      dp[i+tb] = 1; 
			   }
			 }
		  }
		}
		//rintf("***%d %d\n",sum,tsum);
		for(int i = tsum /2 ;i >= 0 ;i --)
		{
		  if(dp[i] != 0 )
		  {
			 sum += max(i,tsum-i);
			 break;
		  }
		}
		printf("%d\n",sum);
         	
	}
return 0;
}
