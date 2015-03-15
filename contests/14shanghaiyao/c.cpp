// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年11月15日 星期六 17时02分24秒

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
#define maxn  200
using namespace std;

int fr[maxn][maxn];
int dp[maxn][maxn];
int main(){
   int t; 
   scanf("%d",&t);
   for(int ca = 1;ca <= t ;ca ++)
   {
     int  n , m; 
	 scanf("%d %d",&n,&m);
	 memset(dp,0,sizeof(dp));
	 memset(fr,0,sizeof(fr));
	 for(int i = 1;i <= n;i ++)
	 {
	    for(int j= 1;j <= m ; j++)
		{
	       int r = min(m,j +1);
		   int l = max(1,j-1);
		}
	 }
   
   }
return 0;
}
