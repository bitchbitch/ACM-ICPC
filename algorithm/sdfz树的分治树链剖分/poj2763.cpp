// File Name: spoj375.cpp
// Author: darkdream
// Created Time: 2014年10月09日 星期四 19时50分56秒

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
#define maxn 100006 
using namespace std;
struct node{
	int ne ; 
	int w; 
	node(int _ne, int _w)
	{
		ne = _ne ;
		w = _w;
	}
};
int tr[maxn];
int value[maxn];
int lowbit(int x)
{
	return  x & (-x);
}
int n;
int getsum(int x);
void update(int x, int v)
{
	while(x <= n)
	{
		tr[x] += v; 
		x += lowbit(x);
	}
}
int getsum(int x)
{
	int sum = 0 ; 
	while(x >= 1)
	{
		sum += tr[x];
		x -=lowbit(x);
	}
	return sum; 
}
vector<node> mp[maxn];
int siz[maxn]; // 子节点的个数
int fa[maxn];  // 父亲节点
int son[maxn];  // 儿子节点
int dep[maxn];  // 深度
int top[maxn];  // 
int w[maxn];
int totw;
void dfs_1(int k , int la,int d)
{
	dep[k] = d; 
	fa[k] = la;
	siz[k] = 1 ;
	for(int i = 0 ;i < mp[k].size() ;i ++)
	{
		if(mp[k][i].ne != la)
		{
			dfs_1(mp[k][i].ne,k,d+1);
			siz[k] += siz[mp[k][i].ne];
			if(son[k] == -1 || siz[mp[k][i].ne] > siz[son[k]])
				son[k] = mp[k][i].ne ;
		}
	}
}
void dfs_2(int k,int sp )
{
	top[k] = sp;
	w[k] = totw ++ ;
    if(son[k] == -1) return;
	  dfs_2(son[k],sp);
	for(int i = 0 ;i < mp[k].size() ;i ++)
	{
		//		printf("%d\n",mp[k][i].ne);
	//	if(mp[k][i].ne!= son[k] && mp[k][i].ne != fa[k]) 
	//		dfs_2(mp[k][i].ne,mp[k][i].ne);	       
	   int v = mp[k][i].ne;
	   if(v != son[k] && v != fa[k])
		   dfs_2(v,v);
	}
}
void make()
{
	totw = 0 ; 
	memset(son,-1,sizeof(int)*(n+2));
	memset(tr,0,sizeof(tr));
	dfs_1(1,0,1);
	//	printf("***\n");
	dfs_2(1,1);
}
struct edges{
	int u,v,w;
}edge[maxn];
int find(int u ,int v)
{
	int f1 = top[u],f2 = top[v];
	int tmp = 0 ;

	while(f1 != f2)
	{
		if(dep[f1] < dep[f2])
		{
			swap(f1,f2);
			swap(u,v);
		}
		tmp +=getsum(w[u]) - getsum(w[f1]- 1);
		u = fa[f1]; // f1 是他的top
		f1 = top[u];
	}
	//	printf("%d %d\n",f1,f2);
	if(u == v )  return tmp;
	if(dep[u] > dep[v])
		swap(u,v);
	//	printf("%d %d\n",w[son[u]],w[v]);
	tmp += getsum(w[v]) - getsum(w[son[u]] -1);
	return tmp;
}
int main(){
	int q , s;
	scanf("%d %d %d",&n,&q,&s);
	for(int i = 1; i <= n;i ++)
		mp[i].clear();
	for(int i = 1;i < n ;i ++)
	{
		//	printf("***\n");
		scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
		mp[edge[i].v].push_back(node(edge[i].u,edge[i].w));
		mp[edge[i].u].push_back(node(edge[i].v,edge[i].w));
	}
	make();
	//printf("***\n");
	for(int i = 1;i < n;i ++)
	{
		if(dep[edge[i].u] > dep[edge[i].v])
			swap(edge[i].u,edge[i].v);
		//printf("%d %d*\n",w[edge[i].v],edge[i].w);
		update(w[edge[i].v],edge[i].w);
		value[w[edge[i].v]] = edge[i].w;
	}
	int op;
	int u,v,uv;
	u = s; 
	while(q--)
	{

		scanf("%d",&op);
		if(op == 0 )
		{
			scanf("%d",&v);
			//      printf("****\n");
			printf("%d\n",find(u,v));
			u = v; 
		}else{
			scanf("%d %d",&v,&uv);
			int tt = uv - value[w[edge[v].v]];
			value[w[edge[v].v]] = uv;
			update(w[edge[v].v],tt);
		} 
	}
	return 0;
}
