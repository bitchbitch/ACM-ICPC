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
#define maxn 10006 
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
struct sgnode{
	int l,r ;
	int mx;
}tr[maxn << 2];
int L(int x)
{
	return 2*x;
}
int R(int x)
{
	return 2*x +1;
}
void pushup(int c)
{
	tr[c].mx = max(tr[L(c)].mx,tr[R(c)].mx);
}
void build(int c, int l ,int r )
{
	tr[c].l = l ; 
	tr[c].r = r; 
	tr[c].mx = 0 ;
	if(l ==  r)
		return ; 
	int m = (l+r)>>1;
	build(L(c),l,m);
	build(R(c),m+1,r);
}
void update(int c, int k,int v)
{
	if(tr[c].l == tr[c].r && tr[c].l == k)
	{
		tr[c].mx = v; 
		return;
	}
	int m = (tr[c].l +tr[c].r) >> 1;
	if(k <= m )
		update(L(c),k,v);
	else 
		update(R(c),k,v);
	pushup(c);
}
int qans;
void query(int c, int l ,int r)
{
	if(tr[c].l >=  l && tr[c].r <=  r)
	{
		qans = max(qans,tr[c].mx);
		return;
	}
	int m = (tr[c].l + tr[c].r) >> 1;
	if(l <= m)
		query(L(c),l,r);
	if(r > m)
		query(R(c),l,r);
}
vector<node> mp[maxn];
int siz[maxn]; // 子节点的个数
int fa[maxn];  // 父亲节点
int son[maxn];  // 儿子节点
int dep[maxn];  // 深度
int top[maxn];  // 
int w[maxn];
int totw;
int n;
void dfs_1(int k , int la,int d)
{
	int num = mp[k].size();
	//	printf("%d %d %d\n",k,la,num);
	dep[k] = d; 
	fa[k] = la;
	siz[k] = 1 ;
	son[k] = -1;
	for(int i = 0 ;i < num ;i ++)
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
	if(son[k] != -1){
		w[k] = totw ++ ;
		dfs_2(son[k],sp);
	}else{
		w[k] = totw ++ ; 
		return;
	}
	int num = mp[k].size();
	for(int i = 0;i < num ;i ++ )
	{
		//		printf("%d\n",mp[k][i].ne);
		if(mp[k][i].ne!= son[k] && mp[k][i].ne != fa[k]) 
			dfs_2(mp[k][i].ne,mp[k][i].ne);	       
	}
}
void make()
{
	totw = 0 ; 
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
		qans = 0 ;
		query(1,w[f1],w[u]);
		tmp = max(qans,tmp);
		u = fa[f1]; // f1 是他的top
		f1 = top[u];
	}
	//	printf("%d %d\n",f1,f2);
	if(u == v )  return tmp;
	if(dep[u] > dep[v])
		swap(u,v);
	qans = 0 ;
//	printf("%d %d\n",w[son[u]],w[v]);
	query(1,w[son[u]],w[v]);
	return max(qans,tmp);
}
int main(){
	int T; 
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1; i <= n;i ++)
			mp[i].clear();
		for(int i = 1;i< n ;i ++)
		{
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
			mp[edge[i].v].push_back(node(edge[i].u,edge[i].w));
			mp[edge[i].u].push_back(node(edge[i].v,edge[i].w));
		}
		make();
		//printf("***\n");
		build(1,1,totw);
		for(int i = 1;i < n;i ++)
		{
			if(dep[edge[i].u] > dep[edge[i].v])
				swap(edge[i].u,edge[i].v);
			//printf("%d %d*\n",w[edge[i].v],edge[i].w);
			update(1,w[edge[i].v],edge[i].w);
		}
		char op[10];
		int u,v;
		while(scanf("%s",op) != EOF)
		{
			if(op[0] == 'D') break;
			scanf("%d%d",&u,&v);
			if(op[0] == 'Q')
				printf("%d\n",find(u,v));
			else update(1,w[edge[u].v],v);
		}
	}
	return 0;
}
