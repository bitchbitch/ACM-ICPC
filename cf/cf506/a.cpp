// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年01月18日 星期日 20时44分46秒

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
#define maxn 30005
using namespace std;
int dp[30010][545];
int hs[maxn];
int main(){
      int n , d; 
	  scanf("%d %d",&n,&d);
	  memset(hs,0,sizeof(hs));
	  for(int i = 1;i <= n;i ++) 
	  {
	    int tmp;
		scanf("%d",&tmp);
		hs[tmp] ++ ; 
	  }
	  memset(dp,-1,sizeof(dp));
	  int mx  = hs[d] ;
	  dp[d][250] = hs[d];
	  for(int i = d + 1;i < maxn ;i ++)
	  {
	      for(int j = 1;j <= 500;j ++)
		  {
			  int dis = j - 250 + d ; 
			  if(i - dis > 0 && i - dis < i )
			  {
				if(dp[i-dis][j+1] != -1)
			     dp[i][j] = max(hs[i] + dp[i-  dis][j+1],dp[i][j]);

				if(dp[i-dis][j] != -1)
			     dp[i][j] = max(hs[i] + dp[i - dis][j] ,dp[i][j]);

				if(dp[i-dis][j-1] != -1)
			     dp[i][j] = max(hs[i] + dp[i - dis][j-1] ,dp[i][j]);
			  }
			  mx = max(dp[i][j],mx);
		  } 
	  }
	  //printf("%d\n",dp[21][171]);
	  printf("%d\n",mx);
return 0;
}
