// File Name: 1005.cpp
// Author: darzdream
// Created Time: 2014年08月12日 星期二 12时25分19秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
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
LL n ,x , y , z , t ;
LL ans = 0 ; 
LL dp[1600][1602];// 前I 个塔选多少个y塔。
void solve()
{
	 for(int i = 0;i <= n ;i ++ )
		 for(int j =0 ;j <= n;j ++)
		 {
		    dp[i][j] = 0; 
		 }
	 ans = x*n*t;
	 for(int i = 1 ;i <= n;i ++)
	 {
	   for(int j = 0;j <= i ;j ++)
	    {
			if(j >= 1)
			{
				dp[i][j] = max(dp[i-1][j-1] + y*(j-1)*(t+(i-j)*z), dp[i-1][j] + y*j*(t+(i-1-j)*z)); // maybe wa
			    if(i == j )
				{
				   dp[i][j] = dp[i-1][j-1] + y*(j-1)*(t+(i-j)*z); // maybe wa
				}
			}
			if(dp[i][j] + (x + j* y)*(t+(i-j)*z)*(n-i)  > ans)
			{
			  ans = dp[i][j] + (x + j * y)*(t+(i-j)*z)*(n-i) ;
			}
		}
	 }
}
int main(){
   int T;
  //freopen("input","r",stdin);
   //freopen("output1","w",stdout);
   scanf("%d",&T);
   for(int ca = 1; ca <= T ;ca ++)
   {
      scanf("%I64d %I64d %I64d %I64d %I64d",&n,&x,&y,&z,&t);
      solve(); 
	  printf("Case #%d: %I64d\n",ca,ans);
   }
return 0;
}
