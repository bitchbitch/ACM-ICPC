// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年04月15日 星期三 01时04分48秒

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
LL a, b, n;
LL l , t, m; 
LL be; 
int ok(LL k)
{
	if(((be + (k-1) * b ) + be)*k/2 <= m * t && be + (k-1) * b <= t)
		return 1;
	return 0 ; 
}
int solve(LL low ,LL high)
{
	while(low <= high)
	{
		LL mid = (low + high)/2;
		if(ok(mid))
		{
		   low = mid + 1;
		}else high = mid -1;
	}
	return high;
}
int main(){
	scanf("%lld %lld %lld",&a,&b,&n);
	for(LL i = 1;i <= n;i ++){
		scanf("%lld %lld %lld",&l,&t,&m);
		be = (l - 1) * b + a; 
		int k = solve(1,1e6);
		if(k < 1)
			printf("-1\n");
		else printf("%lld\n",k+l-1);
	}
return 0;
}
