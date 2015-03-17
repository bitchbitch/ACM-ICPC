// File Name: c.1.cpp
// Author: darkdream
// Created Time: 2015年03月17日 星期二 09时15分20秒

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
int t,n;
struct point{
  int x, y ; 
}p[555];
double dp[555][555];
double dis(int a, int b)
{
   return sqrt(1.0*(p[a].x - p[b].x) *(p[a].x -p[b].x) + 1.0*(p[a].y - p[b].y)*(p[a].y -p[b].y));
}
int main(){
	scanf("%d",&t);
    while(t--)
	{
       scanf("%d",&n);
	   for(int i = 1;i <= n;i ++)
	   {
	      scanf("%d %d",&p[i].x,&p[i].y);
	   }
	   if(n == 1)
	   {
	     printf("%f",0.0);
		 continue;
	   }
	   dp[2][1] = dis(1,2);
	   for(int i = 2;i < n;i ++)
	   {
		  dp[i+1][i] = 100000000; 
	      for(int j = 1; j < i ;j ++)
		  {
		     dp[i+1][j] = dp[i][j] + dis(i,i+1);
			 dp[i+1][i] = min(dp[i+1][i],dp[i][j] + dis(j,i+1));
		  }
	   }
	   printf("%f\n",dp[n][n-1] + dis(n,n-1));
	}
	return 0;
}
