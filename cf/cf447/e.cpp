// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年07月14日 星期一 19时51分54秒

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
#include<climits>
#include<queue>
#define LL long long 
using namespace std;
LL n , m, k, p ; 
struct cmp1{
	bool operator()(LL x, LL y)
	{
		return x < y ; 
	}
};
priority_queue<LL,vector<LL>,cmp1>q;
priority_queue<LL,vector<LL>,cmp1>q1;

LL sumh[1005];
LL suml[1005];
long long  dp[1000005][3];
int main(){  
	scanf("%I64d %I64d %I64d %I64d",&n,&m,&k,&p);
	memset(sumh,0,sizeof(sumh));
	memset(suml,0,sizeof(suml));
    memset(dp,0,sizeof(dp))	;
    LL  temp = 0 ; 
	for(LL i = 1;i <= n; i ++)
		for(LL j = 1;j <= m;j ++)
		{
			scanf("%I64d",&temp) ;
			sumh[i] += temp;
			suml[j] += temp;
		}

	for(LL i = 1;i<= n;i ++)
	{
	   q.push(sumh[i]);
	}

	for(LL i = 1;i<= m;i ++)
	{
	   q1.push(suml[i]);
	}
    long long t;	
	for(LL i = 1;i <= k;i ++)
	{
	    t = q.top();
		q.pop();
		dp[i][1] = dp[i-1][1] + t;
		q.push(t - m*p);
	}
	for(LL i = 1;i <= k;i ++)
	{
	    t = q1.top();	
		q1.pop();
		dp[i][2] = dp[i-1][2] + t;
		q1.push(t - n*p);
	}
	LL ans = - 1e17;
	for(LL i= 0;i <= k;i ++)
	{
        ans = max(ans,dp[i][1]+ dp[k-i][2] - i*(k-i)*p);
	}
    printf("%I64d\n",ans);
	return 0;
}
