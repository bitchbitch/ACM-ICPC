// File Name: 454d.cpp
// Author: darkdream
// Created Time: 2014年08月02日 星期六 18时29分50秒

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
int n ; 
int hs[40];
int b[40];
int lb = 0 ; 
int p2[30];
int fuck[66];
void init()
{
	memset(hs,0,sizeof(hs));
	for(int i = 2 ;i <= 60 ;i ++)
	{
		int ok = 1 ; 
		for(int j =2;j < i ;j ++)
			if(i % j == 0 )
				ok = 0 ; 
		if(ok == 1)
		{
			lb ++ ;
			b[lb] = i ; 
		}
	}
	p2[1] = 1;
	for(int i= 2;i <= 20;i ++)
		p2[i] = p2[i-1] * 2;
	memset(fuck,0,sizeof(fuck));
	for(int i =2;i <= 60 ;i ++)
	{
	    for(int j = 1;j <= lb ;j ++)
			if(i % b[j] == 0 )
				fuck[i] += p2[j];
	}
}
const int mx = 1 << 17;
int  dp[101][mx+10];
struct node{
	int from;
	int num;
}exdp[101][mx+10];
int rans[40] = {0};
int a[104];
void dfs(int n,int k)
{
	if(k == 0 )
		return;
    dfs(exdp[k][n].from,k-1);
	printf("%d ",exdp[k][n].num);
}
int main(){
	init();
	//printf("%d",sizeof(dp)/4);
	scanf("%d",&n);
	for(int i =1 ;i <= n;i ++)
	{
		int temp ; 
		scanf("%d",&a[i]);
		hs[a[i]] ++;	     
	}
	memset(dp,0xff,sizeof(dp));
	dp[0][0] = 0 ;
	for(int i =1;i <= n;i ++)
	{
		for(int j = 0 ;j <= mx;j ++)
		{
			if(dp[i-1][j] != -1)
			{
				for(int s = 2;s <= 60;s ++)
				{
					if((j & fuck[s]) == 0 )  
					{
						int t = j^fuck[s]; 
						int ans = dp[i-1][j] + abs(s-a[i]);
						if(ans < dp[i][t] || dp[i][t] == -1 )
						{
							dp[i][t] =  ans ; 
							exdp[i][t].from = j;
							exdp[i][t].num = s;
						}
					}
				}
				int ans = dp[i-1][j] + abs(1-a[i]);
			    if(ans  < dp[i][j] || dp[i][j] == -1) 
				{
					dp[i][j] =  ans ; 
					exdp[i][j].from = j;
					exdp[i][j].num = 1;
				}
			}
		}
	}
	int anssum = 1e9 ; 
	int ansnum = 0 ;
	for(int i = 0 ;i <= mx ;i ++)
	{
		if(dp[n][i] != -1 && anssum > dp[n][i])
		{	
			anssum = dp[n][i];
			ansnum = i ; 
		}
	}
	dfs(ansnum,n);
	return 0;
}
