// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年11月12日 星期三 10时14分42秒

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
#define M 1000000007
using namespace std;
int d , n ; 
int vis[2005];
vector<int> mp[2005];
int val[2050];
int b[2004];
int cmp(int a, int b)
{
	return val[a] < val[b];
}
int now;
LL find(int x,int fa)
{
	LL sum = 0;
	int num = mp[x].size();
	vector<LL> ans;
	for(int i = 0 ;i < num ;i ++)
	{
		if(mp[x][i] != fa && vis[mp[x][i]] == 0 && val[mp[x][i]] - now <= d)
		{
			ans.push_back(find(mp[x][i],x));
		}
	}
	num = ans.size();
	if(num == 1 )
		sum = ans[0] + 1;
	else {
		sum = 1;
		for(int i = 0;i < num;i ++)
		{
			sum =(sum * (ans[i]+1))%M;
		}
	}
	return sum;  
}
int main(){
    
	scanf("%d %d",&d,&n);
    for(int i=1;i <= n;i ++)
	{
		scanf("%d",&val[i]);
	    b[i] = i ; 
	}
	sort(b+1,b+1+n,cmp);
    int u,v;
	for(int i = 1;i < n;i ++)
	{
	   scanf("%d %d",&u,&v);
	   mp[u].push_back(v);
	   mp[v].push_back(u);
	}
	LL sum = 0 ; 
    for(int i= 1;i <= n;i ++)
	{
	  vis[b[i]] = 1; 
	  now = val[b[i]];
	  //printf("%d\n",val[b[i]]);
	  sum =(sum + find(b[i],0))%M;
	}
	printf("%I64d\n",sum);
	return 0;
}
