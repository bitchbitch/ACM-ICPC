/* ***********************************************
Author        :kuangbin
Created Time  :2013/8/17 2:58:51
File Name     :F:\2013ACM练习\专题学习\数链剖分\POJ2763.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 100010;
struct Edge
{
	int to,next;
}edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
void init()
{
	tot = 0;
	memset(head,-1,sizeof(head));
	pos = 0;
	memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
	edge[tot].to = v; edge[tot].next = head[u]; head[u] = tot++;
}
void dfs1(int u,int pre,int d)
{
	deep[u] = d;
	fa[u] = pre;
	num[u] = 1;
	for(int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if(v != pre)
		{
			dfs1(v,u,d+1);
			num[u] += num[v];
			if(son[u] == -1 || num[v] > num[son[u]])
				son[u] = v;
		}
	}
}
void getpos(int u,int sp)
{
	top[u] = sp;
	p[u] = pos++;
	fp[p[u]] = u;
	if(son[u] == -1)return;
	getpos(son[u],sp);
	for(int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if( v != son[u] && v != fa[u])
			getpos(v,v);
	}
}
struct Node
{
	int l,r;
	int sum;
}segTree[MAXN*3];
void build(int i,int l,int r)
{
	segTree[i].l = l;
	segTree[i].r = r;
	segTree[i].sum = 0;
	if(l == r)
		return;
	int mid = (l+r)/2;
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
}
void push_up(int i)
{
	segTree[i].sum = segTree[i<<1].sum + segTree[(i<<1)|1].sum;
}
void update(int i,int k,int val)
{
	if(segTree[i].l == k && segTree[i].r ==k)
	{
		segTree[i].sum = val;
		return;
	}
	int mid = (segTree[i].l + segTree[i].r )/2;
	if(k <= mid)
		update(i<<1,k,val);
	else update((i<<1)|1,k,val);
	push_up(i);
}
int querysum(int i,int l,int r)
{
	if(l == segTree[i].l && segTree[i].r == r)
		return segTree[i].sum;
	int mid = (segTree[i].l + segTree[i].r)/2;
	if(r <= mid)return querysum(i<<1,l,r);
	else if(l > mid)return querysum((i<<1)|1,l,r);
	else return querysum(i<<1,l,mid) + querysum((i<<1)|1,mid+1,r);
}
int find(int u,int v)
{
	int f1 = top[u],f2 = top[v];
	int tmp = 0;
	while(f1 != f2)
	{
		if(deep[f1] < deep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}
		tmp += querysum(1,p[f1],p[u]);
		u = fa[f1];f1 = top[u];
	}
	if(u ==v )return tmp;
	if(deep[u] > deep[v])swap(u,v);
	return tmp + querysum(1,p[son[u]],p[v]);
}
int e[MAXN][3];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,q,s;
	freopen("out","r",stdin);
	freopen("2763.1","w",stdout);
	int be = clock();
	while(scanf("%d%d%d",&n,&q,&s) ==3)
	{
		init();
		for(int i = 1;i < n;i++)
		{
			scanf("%d%d%d",&e[i][0],&e[i][1],&e[i][2]);
			addedge(e[i][0],e[i][1]);
			addedge(e[i][1],e[i][0]);
		}
		dfs1(1,0,0);
		getpos(1,1);
		build(1,0,pos-1);

		for(int i = 1;i < n;i++)
		{
			if(deep[e[i][0]] > deep[e[i][1]])
				swap(e[i][0],e[i][1]);
			update(1,p[e[i][1]],e[i][2]);
		}
		int op,u,v;
		while(q--)
		{
			scanf("%d%d",&op,&u);
			if(op == 0)
			{
				printf("%d\n",find(s,u));
				s = u;
			}
			else 
			{
				scanf("%d",&v);
				update(1,p[e[u][1]],v);
			}
		}
	}
	int en = clock();
	printf("%d\n",en - be);
    return 0;
}
