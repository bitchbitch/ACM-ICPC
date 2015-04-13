// File Name: d.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 01时30分17秒

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
#include<queue>
#define LL long long

using namespace std;
int n ;
int a[200005];
int point[2000005];
int ans[200005];
queue<int> qu[200000];
int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		qu[a[i]].push(i);
	}
	int j = 0 ; 
	for(int i = 1;i <= n;i ++){
	    while(qu[j].empty() && j >= 3)
			j -= 3; 
		if(qu[j].empty())
		{
			puts("Impossible\n");
			return 0 ; 
		}
		ans[i] = qu[j].front();
		qu[j].pop();
		++ j;
	}
	puts("Possible\n");
	for(int i = 1;i <= n;i ++)
		printf(i == 1?"%d":" %d",ans[i]);
return 0;
}
