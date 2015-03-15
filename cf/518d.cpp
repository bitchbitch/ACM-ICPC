// File Name: 518d.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 20时57分25秒

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
double dp[2005][2005];
int main(){
 int n ,t;
 double p; 
 scanf("%d %lf %d",&n,&p,&t);
 dp[0][0] = 1; 
 for(int i = 0;i <= t;i ++)
 {
   for(int j = 0 ;j < n ;j ++)
   {
      dp[i+1][j] += dp[i][j]*(1- p) ; 
	  dp[i+1][j+1] += dp[i][j] * p ; 
   }
   dp[i+1][n] += dp[i][n];
 }
 double ans = 0; 
 for(int i = 0 ;i <= n;i ++)
 {
   ans += dp[t][i] * i ; 
 }
 printf("%.6lf",ans);
return 0;
}
