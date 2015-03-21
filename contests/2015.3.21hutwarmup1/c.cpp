// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年03月21日 星期六 12时08分27秒

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
#define maxn 2000005
using namespace std;
int n , m ; 
int hsn[maxn];
int a[maxn];
int ok[maxn];
int find(int v)
{
	int l = 1;
	int r = n;
	int mid  ; 
	while(l <= r)
	{
		mid = (l+r)>>1;
		if(a[mid] < v)
		{
			l = mid + 1; 
		}else r = mid -1;
	}
	if(l> n)
		l = n; 
	return l;
}
int main(){
	while(scanf("%d",&n)!=EOF)
	{
		memset(ok,0,sizeof(ok));
		memset(hsn,0,sizeof(hsn));
		int tmp ; 
		for(int i = 1;i <= n;++i)
		{
			scanf("%d",&a[i]);
			hsn[a[i]] = 1;
			ok[a[i]] = 1; 
		}
		sort(a+1,a+1+n);
		scanf("%d",&m);
		int sum = 0 ; 
		for(int i = 1;i <= m;++i)
		{
			scanf("%d",&tmp);
			if(ok[tmp] == 1)
			{
				sum ++ ; 
			}else{
				int k = tmp/2;
				for(int j = 1;j <= n;++j)
				{
					if(hsn[tmp-a[j]])
					{
						sum ++;
						ok[tmp] = 1;
						break;
					}
				}
			}
		}
		//printf("%d\n",find(1));
		printf("%d\n",sum);  
	}
	return 0;
}
