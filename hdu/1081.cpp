// File Name: 1081.cpp
// Author: darkdream
// Created Time: 2015年04月01日 星期三 16时57分14秒

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
#define maxn 1005
using namespace std;
int n ;
int mp[maxn][maxn];
int dp[maxn];
int mx = -1e9 ; 
void  solve(int l , int r)
{
   memset(dp,0,sizeof(dp));
  for(int j = 1;j <= n;j ++)
	for(int i = l ;i <= r ;i ++)
	{
		dp[j] += mp[i][j];
	}
  int sum = 0 ; 
  for(int i = 1;i <= n;i ++)
  {
     if(sum < 0 )
	 {
	   sum = 0 ; 
	 }
	 sum += dp[i];
	 if(sum > 0 )
		 mx = max(sum,mx);
  }
}
int main(){
   while(scanf("%d",&n) != EOF)
   {
	   mx = -1e9;
     for(int i = 1;i <= n;i ++)
		 for(int j = 1;j <= n ;j ++)
		 {
		   scanf("%d",&mp[i][j]);
		   mx = max(mx,mp[i][j]);
		 }
	 for(int i = 1;i <= n;i ++)
		 for(int j = i ;j <= n; j ++)
		 {
		   solve(i,j);
		 }
      printf("%d\n",mx);
   }
return 0;
}
