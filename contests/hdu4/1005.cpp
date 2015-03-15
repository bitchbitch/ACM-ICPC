// File Name: 1005.cpp
// Author: darkdream
// Created Time: 2014年07月31日 星期四 15时38分31秒

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
#define M 1000000007
LL dpy[1002][2155];
LL dpx[1002][2155];
int a[1002];

int main(){
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int n; 
		scanf("%d",&n);
		memset(dpy,0,sizeof(dpy));
		memset(dpx,0,sizeof(dpx));
		int temp ; 
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d",&a[i]);
			dpy[i][a[i]] = 1; 
			for(int j = 0;j <= 1050;j ++)
			{ 
				if(dpy[i-1][j])
				{
					dpy[i][j] =(dpy[i][j]+dpy[i-1][j])%M;
					dpy[i][j^a[i]] = (dpy[i][j^a[i]]+dpy[i-1][j]) % M; 
				}
			}
		}
		LL ans = 0 ; 
		for(int i = n;  i >= 2 ;i -- )
		{
			dpx[i][a[i]] = 1 ; 
			ans = (ans+dpy[i-1][a[i]])% M;
			int tsum[1058];
			memset(tsum,0,sizeof(tsum));
			for(int j = 0 ;j <= 1048;j ++)
			{
				if(dpx[i+1][j])
				{
					ans = (ans + dpy[i-1][j&a[i]]*dpx[i+1][j])%M;
					tsum[j&a[i]] = (tsum[j&a[i]] + dpx[i+1][j]) % M;
				}
			}
			for(int j = 0;j <= 1050 ;j ++)
				dpx[i][j] = (dpx[i+1][j] + dpx[i][j] + tsum[j])%M;
		}
		printf("%I64d\n",ans%M); 
	}
	return 0;
}
