// File Name: 163a.cpp
// Author: darkdream
// Created Time: 2015年03月22日 星期日 17时09分33秒

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
#define M 1000000007
using namespace std;
char str[2][5005];
int dp[5005][5005];
int num[5005];
int n , m; 
int main(){
   scanf("%s %s",&str[1][1],&str[0][1]);
   n = strlen(&str[0][1]);
   m = strlen(&str[1][1]);
   num[1] = 1; 
   for(int i = 2;i <= n;i ++)
	   num[i] = num[i-1] + i;  
   printf("%d %d\n",n,m);
   for(int i = 1;i <= n;i ++)
   {
      for(int j = 1;j <= m;j ++ )
	  {
	    if(str[0][i] == str[1][j])
		{
		   dp[i][j] = 1;
		}
		dp[i][j] += dp[i-1][j-1];
		dp[i][j] = max(dp[i-1][j],dp[i][j]);
		dp[i][j] = max(dp[i][j-1],dp[i][j]);
	  }
   }
   int sum = 0; 
   for(int i = 1;i <= n;i ++)
   {
       for(int j = 1;j <= m;j ++)
	   {
		   printf("%d ",dp[i][j]);
		   
	      if(dp[i][j] != 0 && dp[i+1][j+1] == 0 )
		  {
                   sum =(sum+ num[dp[i][j]])%M;		  
		  }
	   }
	   printf("\n");
   }
   printf("%d\n",sum);
return 0;
}
