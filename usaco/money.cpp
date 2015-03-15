// File Name: money.cpp
// Author: darkdream
// Created Time: 2013年12月11日 星期三 12时48分34秒
/*
ID: dream.y1
PROG: money
LANG: C++
*/

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
long long dp[20000];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
   int n ,m ; 
   scanf("%d %d",&n,&m);
   int a[40];
   for(int i = 1;i <= n;i ++)
      scanf("%d",&a[i]);
   dp[0] = 1;
   for(int j = 1;j <= n;j ++)
   for(int i = 0;i <= m;i ++)
   {
      if(dp[i] && i + a[j] <= m)
	  {
	     dp[a[j] + i] += dp[i];
	  }
   }
   printf("%lld\n",dp[m]);
return 0;
}
