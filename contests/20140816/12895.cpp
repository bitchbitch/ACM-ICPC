// File Name: 12895.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 23时41分13秒

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
struct node{
	int x, y , c,ok;
}a[1005];
int cmp(node a, node b)
{
	return a.c > b.c ; 
}
int main(){
	int n ; 
	while(scanf("%d",&n)!= EOF)
	{
		memset(a,0,sizeof(a));
		for(int i = 1;i <= n;i ++)
		{
			scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].c) ;
			a[i].ok = 1;
		}
		sort(a+1,a+1+n,cmp);
		LL ans = 0 ; 
		for(int i = 1;i <= n;i ++)
		{
			int site = 0 ; 
			int mx = 0;
			for(int j = 1;j <= n;j ++)
			{
				if(a[j].ok && a[i].y  >  a[j].x )
				{
					if(a[j].x > mx)
					{
						mx = a[j].x;
						site = j ; 
					}
				}
			}
			if(site)
			{
				a[site].ok = 0 ;
			}
			ans += (a[i].y - mx)*a[i].c ; 
		}
		printf("%I64d\n",ans);
	}        
	return 0;
}
