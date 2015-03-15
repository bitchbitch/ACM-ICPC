// File Name: 1421.cpp
// Author: darkdream
// Created Time: 2014年07月12日 星期六 16时25分31秒

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
#include<climits>
#include<queue>

using namespace std;
int a[2005];
int cmp(int a, int b)
{
  return a < b ; 
}
int dp[2001][2001];
int main(){

   int n , k ; 
   while(scanf("%d %d",&n,&k) != EOF)
   {
      for(int i =1 ;i<= n;i ++)
	  {
	      scanf("%d",&a[i]);
	  }
	  sort(a+1,a+1+n,cmp);
	  memset(dp,0,sizeof(dp));
	  for(int i = 1;i <= n;i ++)
		  for(int j = 1;j <= k;j ++)
			  dp[i][j] = 1<<30;
	  for(int i = 2;i <= n;i ++)
	   for(int j = 1; j *2 <= i;j ++)
	   {  
	       dp[i][j] = min(dp[i-1][j],dp[i-2][j-1] + (a[i] - a[i-1]) * (a[i] - a[i-1]));
	   }
	  printf("%d\n",dp[n][k]);

   }
return 0;
}
