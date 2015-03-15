// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月15日 星期一 14时29分39秒

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
LL dp[200][200];
#define M 1000000007
int main(){
	freopen("out","w",stdout);
   int t; 
   scanf("%d",&t);
   for(int ca = 1; ca <= t; ca ++)
   {
     int n , m ;
	 scanf("%d %d",&n,&m);
	 memset(dp,0,sizeof(dp));
	 dp[1][1] = n; 
	 for(int i = 2;i <= m;i ++)
	 {
		for(int j = 1;j <= n;j ++)
	     dp[i][j] = (dp[i-1][j] *j)%M + dp[i-1][j-1]*(n-j+1)%M ;
	 }
    printf("Case #%d: %lld\n",ca,dp[m][n]%M); 
   }
return 0;
}
