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
int mx[2][5005];
int sum[2][5005];
int num[5005];
int n , m; 
int main(){
   scanf("%s %s",&str[0][1],&str[1][1]);
   n = strlen(&str[0][1]);
   m = strlen(&str[1][1]);
   int ans = 0 ; 
   for(int i = 1;i <= n;i ++)
   {
      for(int j = 1;j <= m ; j ++)
	  {
	     if(str[0][i] == str[1][j])
		 {
		    dp[i][j] = sum[0][j-1] + 1;
		 }
		 sum[1][j] = (sum[1][j-1]+dp[i][j]) % M;
		// printf("%d ",dp[i][j]);
	  }
	  //printf("\n");
	  ans = (ans + sum[1][m])%M;
	  memcpy(sum[0],sum[1],sizeof(sum[0]));
	  memset(sum[1],0,sizeof(sum[1]));
   }
   printf("%d\n",ans);
return 0;
}
