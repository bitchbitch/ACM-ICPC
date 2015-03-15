// File Name: 416b.cpp
// Author: darkdream
// Created Time: 2014年07月30日 星期三 16时11分13秒

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

using namespace std;
int p[50004][6];
int dp[6];
int main(){
   int m , n ; 
   scanf("%d %d",&m,&n);
   for(int i = 1;i <= m;i ++)
   {
	  for(int j = 1;j <= n ;j ++)
	  {
	     scanf("%d",&p[i][j]);
	  }
   }
   memset(dp,0,sizeof(dp));
   for(int i = 1;i <= m;i ++)
   {
      dp[1] = dp[1] + p[i][1];
      for(int j = 2;j <= n;j ++ )
	  {
	     dp[j] = max(dp[j-1],dp[j]) + p[i][j];  
	  }
	  printf("%d ",dp[n]);
   }

return 0;
}
