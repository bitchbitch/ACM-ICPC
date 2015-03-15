// File Name: 1042.cpp
// Author: darkdream
// Created Time: 2014年08月10日 星期日 01时09分52秒

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
int n , m; 
int a[1000];
bool dp[204][104][2011];
bool dp1[204][104][2011];
int main(){
	memset(dp,0,sizeof(dp));
	memset(dp1,0,sizeof(dp1));
    scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i ++)
	{
        int ta,tb;
		scanf("%d %d",&ta,&tb);
		a[i] = ta - tb;
	}
	if(m > n )
	{
	   printf("0\n");
	   return 0 ;
	}
	dp[0][0][0] = dp1[0][0][0] = 1;  
    for(int i =1;i <= n;i ++)
	{
	   for(int j= 1;j <= m+1;j ++)
	   {
	     for(int s = 0 ; s <= 2000;s++)
		 {
		    if(dp[i-1][j-1][s] == 1)
			{
			  // printf("%d %d %d\n",i-1,j-1,s);
			   dp[i][j-1][s] = 1;
			   if(s + a[i] >= 0 )
				  dp[i][j][s+a[i]] = 1;
			   else dp1[i][j][abs(s+a[i])] = 1;
			}
			if(dp1[i-1][j-1][s] == 1)
			{
			 //  printf("%d %d %d\n",i-1,j-1,-s);
			   dp1[i][j-1][s] = 1;
			   if(a[i] - s >= 0 )
				   dp[i][j][a[i]-s] = 1; 
			   else dp1[i][j][abs(a[i]-s)] = 1;
			}
		 }
	   }
	}
    int ok = 0 ;
    for(int i = 0 ;i <= 2000;i ++)
	{
	    if(dp[n][m][i] || dp1[n][m][i])
		  {
			ok = 1; 
		    printf("%d\n",i);
			break;
		  }
	}
	if(!ok)
		printf("0\n");

return 0;
}
