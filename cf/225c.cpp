// File Name: 225c.cpp
// Author: darkdream
// Created Time: 2015年03月09日 星期一 09时49分05秒
#include<climits>
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
char str[1005][1005];
int dp[1005][2][1005];
int cw[1005];
int cb[1005];
int main(){
  int n , m ,x ,y;
  memset(dp,-1,sizeof(dp)) ;
  scanf("%d %d %d %d",&n,&m,&x,&y);
  for(int i = 1;i <= n;i ++)
  {
     scanf("%s",&str[i][1]);
  }
  for(int i = 1;i <= m;i ++)
  {
    for(int j = 1;j <= n;j ++)
	{
	  if(str[j][i] == '#')
		  cw[i] ++ ;
	}
	cb[i] = n - cw[i];
  }
  dp[1][0][1] = cb[1];
  dp[1][1][1] = cw[1];
  for(int i= 2;i <= m;i ++)
  {
     int mxcb = -1;
     for(int j = 1;j <= y ;j ++)
	 {
	      if(dp[i-1][0][j] != -1)
		  {
		    dp[i][0][j+1] = dp[i-1][0][j] + cb[i];
		    if(j >= x)
			{
			 if(mxcb == -1)
				 mxcb = dp[i-1][0][j];
			 else 
			     mxcb = min(mxcb,dp[i-1][0][j]);
			}
		  }
	 }
	 int mxcw = -1; 
     for(int j = 1;j <= y ;j ++)
	 {
	      if(dp[i-1][1][j] != -1)
		  {
		    dp[i][1][j+1] = dp[i-1][1][j] + cw[i];
		    if(j >= x)
			{
			 if(mxcw == -1)
				 mxcw = dp[i-1][1][j];
			 else 
			     mxcw = min(mxcw,dp[i-1][1][j]);
			}
		  }
	 }
	 //printf("%d %d\n",mxcw,mxcb);
	 if(mxcw != -1)
		 dp[i][0][1] = mxcw + cb[i];
	 if(mxcb != -1)
		 dp[i][1][1] = mxcb + cw[i];
  }
  int ans = INT_MAX; 
  for(int i = 0 ;i < 2;i ++)
	  for(int j = x; j <= y; j ++)
	  {
		if(dp[m][i][j] != -1)
	      ans = min(dp[m][i][j],ans);
	  }
  /*for(int i = 1;i <= m;i ++)
  {
   for(int s = 0 ; s <= 1 ; s ++)
   {
    for(int j= 1;j <= y ;j ++)
		printf("%d ",dp[i][s][j]);
     printf("****");
   }
	printf("\n");
  }*/
  printf("%d\n",ans);
return 0;
}
