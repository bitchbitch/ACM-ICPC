// File Name: c.cpp
// Author: darkdream
// Created Time: 2013年02月25日 星期一 01时20分11秒

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
int a[200001];
int b[200001];
int cmp(const int a, const int b)
{
   if(a>b) return 0;
   else return 1;
};
int main()
		
{int n , m ;
		scanf("%d %d",&n,&m);
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		memset(b,0,sizeof(b));
	    long long sum  = 0 ;
		for(int i = 1;i <= m ;i++)
		{
			int x, y ;
			scanf("%d %d",&x,&y);
			for( x;  x <= y ; x++)
				b[x-1] ++;

		}

		sort(a,a+n);
		sort(b,b+n);

		for(int i = n-1 ;i >=0 ;i-- )
		{ if(b[i] == 0)
			break;
			sum += b[i]*a[i];
		}
		printf("%lld",sum);

		return 0 ;

	}
