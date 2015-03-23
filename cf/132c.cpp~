// File Name: 132c.cpp
// Author: darkdream
// Created Time: 2015年03月22日 星期日 19时43分45秒

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
char str[1000];
int k;
int dp[105][105][2];
int main(){
   scanf("%s",str);
   scanf("%d",&k);
   int len = strlen(str);
   memset(dp,1000,sizeof(dp));
   dp[0][0][1] = 0 ; 
   for(int i = 0 ;i < len ;i ++)
   {
	   if(str[i] == 'F')
	   {
          for(int j = 0 ;j <= k;i ++)
		  {
		      if(dp[i-1][j][0] != 1000)
			  {
				 dp[i][j+1][1] = dp[i-1][j][0];
			     if(dp[i][j] == 1000 ) 
				    dp[i][j][0]  = dp[i-1][j][0] -1 ;  
				 else 
				    dp[i][j][0] = min(dp[i][j][0],dp[i-1][j]-1) ;
			  }
			  if(dp[i-1][j][1] != 1000)
			  {
				 dp[i][j+1][1] = dp[i-1][j][0];
			     dp[i][j][1]  = dp[i-1][j][1] +1 ;  
			  }
		  }
	   }else{
	   
	   }
   }
return 0;
}
