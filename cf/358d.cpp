// File Name: 358d.cpp
// Author: darkdream
// Created Time: 2015年03月24日 星期二 18时51分20秒

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
#define maxn 3005
using namespace std;
int dp[maxn][8];
int c[maxn];
int b[maxn];
int a[maxn];
int n; 
int main(){
     scanf("%d",&n);
	 for(int i= 1;i <= n;i ++)
	 {
	    scanf("%d",&a[i]);
	 }
	 for(int i= 1;i <= n;i ++)
	 {
	    scanf("%d",&b[i]);
	 }
	 for(int i= 1;i <= n;i ++)
	 {
		 scanf("%d",&c[i]);
	 }
	 if(n != 1)
	 dp[1][2] = b[1];
	 dp[1][3] = a[1];
	 for(int i = 2; i< n;i ++)
	 {
	    dp[i][0] = max(dp[i-1][3],dp[i-1][1]) + c[i];
		dp[i][1] = max(dp[i-1][3],dp[i-1][1]) + b[i];
	    dp[i][2] = max(dp[i-1][2],dp[i-1][0]) + b[i];
		dp[i][3] = max(dp[i-1][2],dp[i-1][0]) + a[i];
	 }
	 if(n != 1 )
	 {
		dp[n][1] = max(dp[n-1][3],dp[n-1][1]) + b[n];
		dp[n][3] = max(dp[n-1][2],dp[n-1][0]) + a[n];
	 }
	 /*for(int i = 1; i <= n;i ++)
	 {
	     for(int j = 0 ;j <= 3 ;j ++)
		 {
		    printf("%d ",dp[i][j]);
		 }
		 printf("\n");
	 }*/
	 int mx = 0 ;
	 for(int i= 0 ;i<= 3 ;i ++)
		 mx = max(mx,dp[n][i]);
	 printf("%d\n",mx);
return 0;
}
