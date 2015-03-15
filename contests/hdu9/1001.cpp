// File Name: 1001.cpp
// Author: darkdream
// Created Time: 2014年08月19日 星期二 16时18分00秒

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
LL a[5006];
struct node{
	LL x, y ; 
}dp[6000];
LL ans[6000];
LL hs[6000];
int main(){
	LL n ;
	while(scanf("%I64d",&n)!= EOF,n)
	{
		for(LL i =1 ;i <=n ;i ++)
			scanf("%I64d",&a[i]);
		for(int i = 1;i <= n;i ++)
			scanf("%I64d",&hs[i]);
		LL t= n ;
		LL tsum = 0;
		LL sum = 0 ;
		LL k = 0 ; 
		for(LL i = 1;i <= n;i ++)
		{
			sum += a[i];
			if(sum > tsum )
			{
				for(;t >= 1,tsum < sum;t --)
				{
					tsum += a[t];
				}
			}
			if(t < i )
				break;
			if(sum == tsum){
				k ++ ; 
				dp[k].x = i ; 
				dp[k].y = n - t;
			}
		}
		if(k == 0 ||  dp[k].x + dp[k].y < n-1)
		{
			printf("%I64d\n",hs[n]);
		    continue;
		}
		ans[0] = 0 ;
		for(int i = 1;i <= k ;i ++)
		{
			ans[i] = 1e18;
			for(int j = 0;j < i ;j ++)
			{
				ans[i] = min(ans[i],ans[j] + hs[dp[i].x-dp[j].x] + hs[dp[i].y -dp[j].y]) ;
			}
		}
		printf("%I64d\n",min(ans[k],hs[n]));
	}
	return 0;
}
