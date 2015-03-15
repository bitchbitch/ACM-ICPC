// File Name: 2544_1.cpp
// Author: darkdream
// Created Time: 2014年04月04日 星期五 22时37分45秒
/*
ID: dream.y1
PROG: butter
LANG: C++
*/
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
#include<climits>
#include<queue>
using namespace std;

struct node{
	int x, d ; 
	node()
	{}
	node(int p,int q)
	{
		x = p; 
		d = q; 
	}
};
vector <node> edge[1000];
int n , m ; 
int dis[1000];
queue <int> lis;
int SPFA(int s)
{
	for(int i = 1;i <= n;i ++) dis[i] = 1 << 27; 
	dis[s] = 0 ; 
	lis.push(s);
	while(!lis.empty())
	{
		int k = lis.front();
	//	printf("%d\n",k);
		lis.pop();
		int n = edge[k].size();
		for(int i = 0 ;i < n ;i ++)
		{
			if(dis[edge[k][i].x] > dis[k] + edge[k][i].d)
			{
				dis[edge[k][i].x] = dis[k] + edge[k][i].d;
				lis.push(edge[k][i].x);
			}
		}
	}
	return 1;   
}
int main(){
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	int p ;     
	scanf("%d %d %d",&p,&n,&m);

	int a[3000];
	for(int i = 1;i <= p;i ++)
       scanf("%d",&a[i]);      
	for(int i =1 ;i <= n;i++)
		edge[i].clear();
	for(int i = 1;i <= m ;i ++)
	{ 
		int a, b, c;
		scanf("%d %d %d",&a,&b,&c);
		edge[a].push_back(node(b,c));
		edge[b].push_back(node(a,c));
	}
	int min = INT_MAX;
	for(int i= 1;i <= n;i ++)
	{   SPFA(i);
		int tsum = 0 ; 
	    for(int j = 1;j <= p ;j ++)
			tsum += dis[a[j]];
		if(tsum < min )
			min = tsum ; 
	}
	printf("%d\n",min);
	return 0;
}
