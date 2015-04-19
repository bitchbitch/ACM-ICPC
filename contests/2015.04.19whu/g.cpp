// File Name: g.cpp
// Author: darkdream
// Created Time: 2015年04月19日 星期日 13时23分49秒

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
LL a[1000];
LL ans[100];
double mi = 1e100;
double solve()
{
	double ave = 0 ; 
	double sum = 0 ; 
	for(int i = 1;i <= m;i++)
	{
	   sum += ans[i];	
	}
	ave = sum / m; 
	double re = 0 ;
	for(int i = 1;i <= m;i ++)
	{
	   re += (ans[i] - ave) * (ans[i] -ave);
	}
	re /= m ;
	return re;
}
int main(){
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i =1 ;i <= n;i ++)
			scanf("%lld",&a[i]);
		mi = 1e100;
		sort(a+1,a+1+n);
		for(int i = 1;i <= n-m+1;i ++)
		{
			for(int j = i ;j <= i+m-1;j ++)
				ans[j-i+1] = a[j];
			/*for(int i = 1;i <= m;i ++)
				printf("%lld ",ans[i]);
			printf("\n");
			*/mi = min(solve(),mi);
		}
		printf("%.3f\n",mi);

	}

return 0;
}
