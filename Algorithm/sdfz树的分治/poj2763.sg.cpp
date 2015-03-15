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
//#pragma comment(linker,"/STACK:102400000,102400000")
#define debug
#define LL long long
#define maxn 100006 
using namespace std;
struct sgnode{
	int l,r ;
	int mx;
}tr[maxn << 2];
void pushup(int c)
{
	tr[c].mx =tr[c<<1].mx + tr[(c<<1)|1].mx;
}
void build(int c, int l ,int r )
{
	tr[c].l = l ; 
	tr[c].r = r; 
	tr[c].mx = 0 ;
	if(l ==  r)
		return ; 
	int m = (l+r)>>1;
	build(c<<1,l,m);
	build((c<<1)|1,m+1,r);
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
		update(c<<1,k,v);
	else 
		update((c<<1)|1,k,v);
	pushup(c);
}
int query(int c, int l ,int r)
{
	
	if(tr[c].l >=  l && tr[c].r <=  r)
	{
		return tr[c].mx;
	}
	int m = (tr[c].l + tr[c].r) >> 1;
	if(r <= m)
	 return query(c<<1,l,r);
	if(l > m)
	  return 	query((c<<1)|1,l,r);
	else  return query(c <<1,l,m) + query((c<<1)|1,m+1,r);
}
vector<int> mp[maxn];
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
		if(mp[k][i] != la)
		{
			dfs_1(mp[k][i],k,d+1);
			siz[k] += siz[mp[k][i]];
			if(son[k] == -1 || siz[mp[k][i]] > siz[son[k]])
				son[k] = mp[k][i] ;
		}
	}
}
void dfs_2(int k,int sp )
{
	top[k] = sp;
    w[k] = totw ++ ;
	if(son[k] == -1) return;
	dfs_2(son[k],sp);
	int num = mp[k].size();
	for(int i = 0;i < num ;i ++ )
	{
		//		printf("%d\n",mp[k][i]);
		if(mp[k][i]!= son[k] && mp[k][i] != fa[k]) 
			dfs_2(mp[k][i],mp[k][i]);	       
	}
}
void make()
{
	totw = 0 ; 
	dfs_1(1,0,1);
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
		tmp +=query(1,w[f1],w[u]);
		u = fa[f1]; // f1 是他的top
		f1 = top[u];
	}
	if(u == v )  return tmp;
	if(dep[u] > dep[v])
		swap(u,v);
	tmp +=query(1,w[son[u]],w[v]);
	return tmp;
}
int main(){
	int q , s;
#ifdef debug

	freopen("out","r",stdin);
	freopen("2763","w",stdout);

	int be = clock();
#endif
	int ti = 0;
	while(scanf("%d %d %d",&n,&q,&s) != EOF)
	{
//	fclose(stdout);
	//	printf("******%d\n",++ti);
	//freopen("2763","w",stdout);
		for(int i = 1; i <= n;i ++)
			mp[i].clear();
		for(int i = 1;i < n ;i ++)
		{
		//	printf("***\n");
			scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
			mp[edge[i].v].push_back(edge[i].u);
			mp[edge[i].u].push_back(edge[i].v);
		}
		make();
		//printf("***\n");
		build(1,1,totw-1);
		for(int i = 1;i < n;i ++)
		{
			if(dep[edge[i].u] > dep[edge[i].v])
				swap(edge[i].u,edge[i].v);
			//printf("%d %d*\n",w[edge[i].v],edge[i].w);
			update(1,w[edge[i].v],edge[i].w);
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
		      update(1,w[edge[v].v],uv);
		   } 
		}
	}
	//freopen(stdout,"w",stdout);
#ifdef debug
	int en = clock();
    printf("%d\n",en-be);	
#endif
	return 0;
}
