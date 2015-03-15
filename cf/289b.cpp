// File Name: 289b.cpp
// Author: darkdream
// Created Time: 2014年07月29日 星期二 22时33分11秒

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

using namespace std;
int a[10005];
int sum[10005];
int n , m ,d; 
int find(int x)
{
	int l = 1, r = n;
	while(l <= r)
	{
		int m = (l+r)/2;
		if(a[m] > x)
		{
			r = m -1; 
		}else {
			l = m + 1; 
		}
	}
	return r; 
}
int main(){
	scanf("%d %d %d",&n,&m,&d);
	n = n * m ;
	sum[0] = 0 ; 
	for(int i = 1;i <= n ;i ++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	int M = 1e9 ; 
	int ok = 1;
	sum[1] = a[1];
	for(int i = 2;i <= n;i ++)
	{
		sum[i] = sum[i-1] + a[i];
		if((a[i]-a[i-1])%d != 0 )
			ok = 0; 
	}
	if(ok)
	{
		ok = 0; 
		for(int i = 1 ;i <= 10000;i ++)
		{
			int k =  find(i);
			if(k == 0 )
				continue;
			int ans = i*k - sum[k]  +(sum[n]-sum[k] -(n-k)*i);
			if( ans%d == 0 && ans/d <= M)
			{
				M = ans/d;
			//	printf("%d %d %d %d\n",ans,i,k,M);
				ok = 1; 
			}
		}
	}
	if(ok  ==1  )
		printf("%d\n",M);
	else printf("-1\n");


	return 0;
}
