/*
   Dijkstra的算法思想：
   在所有没有访问过的结点中选出dis(s,x)值最小的x
   对从x出发的所有边(x,y),更新
   dis(s,y)=min(dis(s,y),dis(s,x)+dis(x,y))
   */
/*
ID: dream.y1
PROG: butter
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
const int Ni = 1000;
const int INF = 1<<27;
struct node{
	int x,d;
	node(){}
	node(int a,int b){x=a;d=b;}
	bool operator < (const node & a) const
	{
		if(d==a.d) return x<a.x;
		else return d > a.d;
	}
};
vector<node> eg[Ni];
int dis[Ni],n;
void Dijkstra(int s)
{
	int i;
	for(i=0;i<=n;i++) dis[i]=INF;
	dis[s]=0;
	priority_queue<node> q;
	q.push(node(s,dis[s]));
	while(!q.empty())
	{
		node x=q.top();q.pop();
		for(i=0;i<eg[x.x].size();i++)
		{
			node y=eg[x.x][i];
			if(dis[y.x]>x.d+y.d)
			{
				dis[y.x]=x.d+y.d;
				q.push(node(y.x,dis[y.x]));
			}
		}
	}
}
int ans[1000];
int main()
{
	freopen("butter.in","r",stdin);
	freopen("butter.out","w",stdout);
	int a,b,d,p,c;
	scanf("%d %d %d",&p,&n,&c);
    for(int i = 1;i <= p; i ++)
		scanf("%d",&ans[i]);
	for(int i=0;i<= n;i++) eg[i].clear();
	while(c--)
	{
		scanf("%d%d%d",&a,&b,&d);
		eg[a].push_back(node(b,d));
		eg[b].push_back(node(a,d));
	}
	int min = INT_MAX;
	for(int i = 1;i <= n ;i ++ )
	{	
	  Dijkstra(i);
	  int tsum = 0  ;
    	for(int j = 1;j <= p;j ++)
    	  tsum += dis[ans[j]];
	   if(tsum < min)
		   min = tsum ; 
	}
	printf("%d\n",min);
	return 0;
}
/*
// File Name: butter2.cpp
// Author: darkdream
// Created Time: 2014年04月03日 星期四 22时11分17秒

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
#include<limits>

using namespace std;

int dis[800][800];
int M[800][800];
int a[1000];
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);

int n , p , c; 
for(int i = 1;i <= n;i ++)
{
scanf("%d",&a[i]);
}
for(int i = 1;i <= n;i ++)
for(int j = 1;j <= n;j ++)

for(int i = 1;i <= c;i ++)
{
int ta,tb,tc;
M[ta][tb] = tc;
M[tb][ta] = tc; 
}

return 0;
}*/
