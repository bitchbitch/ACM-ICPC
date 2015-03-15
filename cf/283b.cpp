// File Name: 283b.cpp
// Author: darkdream
// Created Time: 2015年03月12日 星期四 10时59分22秒

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
int a[200005];
int vis[200005][2];
LL dp[200005][2];
int n ;
void dfs(int k ,int t,int color)
{
     if(t == 1)
	 {
		dp[k][t] = a[k];
		if(k +a[k] > n)
		{
		   return ;
		}
		if(vis[k + a[k]][t^1] != 0  )
		{
			if(vis[k+a[k]][t^1] == color)
				dp[k][t] = -1;
			else{
				if(dp[k+a[k]][t^1] == -1)
					dp[k][t] = -1;
				else dp[k][t] += dp[k+a[k]][t^1];
			}
			return ;
		}
		vis[k+a[k]][t^1] = color; 
		dfs(k+a[k],0,color);
	    if(dp[k+a[k]][t^1] == -1)
			dp[k][t] = -1;
		else dp[k][t] += dp[k+a[k]][t^1];
	 }else if(t == 0 ){
	  	dp[k][t] = a[k];
		if(k - a[k] <= 0)
		{
		   return ;
		}
		if(k - a[k] ==  1)
		{
		   dp[k][t] = -1;
		   return ;
		}
	    if(vis[k - a[k]][t^1] != 0  )
		{
			if(vis[k-a[k]][t^1] == color)
				dp[k][t] = -1;
			else{
				if(dp[k-a[k]][t^1] == -1)
					dp[k][t] = -1;
				else dp[k][t] += dp[k-a[k]][t^1];
			}
			return ;
		
		}
		vis[k-a[k]][t^1] = color; 
		dfs(k-a[k],1,color);
	    if(dp[k-a[k]][t^1] == -1)
			dp[k][t] = -1;
		else dp[k][t] += dp[k-a[k]][t^1];
	 }
}
int main(){
	scanf("%d",&n);
	for(int i = 2 ; i <= n;i ++)
	{
       	scanf("%d",&a[i]);   	
	}
	for(int i = 2;i <= n;i ++)
	{
         if(vis[i][0] == 0)
		 {
			vis[i][0] = i; 
		    dfs(i,0,i);
		 }
		 if(vis[i][1] == 0 )
		 {
			vis[i][1] = i; 
		    dfs(i,1,i);
		 }
	}
	for(int i = 1;i < n;i ++)
	{
	    if(1 + i > n)
		{
			printf("%d\n",i);
		    continue;
		}else{
			if(dp[1+i][0] != -1)
	        printf("%lld\n",i+dp[1+i][0]);	
			else printf("-1\n");
		}
	}
    
return 0;
}
