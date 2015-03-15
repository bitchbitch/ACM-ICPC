// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年02月03日 星期二 01时16分07秒

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
map<LL,int>  dp[400];
map<LL,int> ::iterator it;
LL a[400];
LL ABS(LL x)
{
  if(x < 0)
	  return -x;
  else return x; 
}
LL gcd(LL a ,LL b)
{
  return b == 0 ?a:gcd(b,a%b);
}
int b[400];
int main(){
 int n; 
 scanf("%d",&n);
 for(int i = 1;i <= n;i ++)
 {
   scanf("%lld",&a[i]);
 }
 for(int i = 1;i <=n;i ++)
	 scanf("%d",&b[i]);
 dp[0][0] = 0;
 for(int i = 1;i <= n;i ++)
 {
   for(it = dp[i-1].begin(); it!=dp[i-1].end(); ++ it)
   {
	 LL k = it->first;
	 LL x = gcd(max(a[i],k),min(a[i],k));
	 if(dp[i].find(k) == dp[i].end())
	 {
	    dp[i][k] = it->second; 
	 }else{
	    dp[i][k] = min(dp[i-1][k],dp[i][k]);
	 }
	 if(dp[i].find(x) == dp[i].end())
	 {
	    dp[i][x] = it->second + b[i]; 
	 }else{
	    dp[i][x] = min(it->second + b[i],dp[i][x]);
	 }
	 /*if(dp[i].find(y) == dp[i].end())
	 {
	    dp[i][y] = it->second + b[i]; 
	 }else{
	    dp[i][y] = min(it->second + b[i],dp[i][y]);
	 }*/
	// printf("%lld %d %lld %d\n",x,dp[i][x],y,dp[i][y]);
   }
 }
 if(dp[n].find(1) == dp[n].end())
	 printf("-1\n");
 else printf("%d\n",dp[n][1]);
return 0;
}
