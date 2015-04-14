// File Name: hdu2763.2.cpp
// Author: darkdream
// Created Time: 2015年04月14日 星期二 15时32分22秒

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
#define maxn 100005
using namespace std;

int sz[maxn];
int deep[maxn];
int fa[maxn];
int top[maxn];
int w[maxn];
int son[maxn];
int dis[maxn];
int fw[maxn];
int num[maxn];
int totw;
struct node{
	int l ,r,m, sum;
}tr[maxn*4];
struct next{
	int ne,v,rank;
	next(){}
	next(int _ne,int _v,int _rank){
		ne = _ne ; 
		v = _v; 
		rank = _rank;
	}
};
vector<next> mp[maxn];
inline int L(int x)
{
  return 2 * x; 
}
inline int R(int x)
{
 return 2 * x + 1; 
}
void push_up(int x){
	tr[x].sum = tr[L(x)].sum + tr[R(x)].sum;
}
void build(int c,int l ,int r ){
	tr[c].l = l ; 
	tr[c].r = r ; 
	tr[c].m = (l + r)/2;
	tr[c].sum = 0 ; 
	if(l == r)
		return ;
	build((c<<1),l,tr[c].m);
	build((c<<1|1),tr[c].m+1,r);
}
void update(int c,int p , int v){
	//printf("%d %d %d\n",c,p,v);
	if(tr[c].l == tr[c].r ){
		tr[c].sum = v; 
		return ;
	} 
	if(p <= tr[c].m)
		update((c<<1),p,v);
	else update((c<<1|1),p,v);
	push_up(c);
}
int getsum(int c, int l ,int r){
	if(l <= tr[c].l && r >= tr[c].r){
		return tr[c].sum;
	}
	int sum = 0 ; 
	if(l <= tr[c].m)
		sum += getsum((c<<1),l,r);
	if(r > tr[c].m)
		sum += getsum((c<<1|1),l,r);
	return sum ; 
}
int s, n ,q ; 
void dfs_1(int k ,int la, int d){
	sz[k] = 1; 
	deep[k] = d; 
	fa[k] = la ; 
	son[k] = -1;	
	dis[k] = 0 ; 
	for(int i = 0 ;i < mp[k].size() ;i ++){
		if(mp[k][i].ne == la)
			continue;
		dfs_1(mp[k][i].ne,k,d+1);
		sz[k] += sz[mp[k][i].ne];
		if(son[k] == -1  || sz[mp[k][i].ne] > sz[son[k]]){
			son[k] = mp[k][i].ne;
			dis[k] = mp[k][i].v;
			num[k] = mp[k][i].rank;
		}
	}
}
void dfs_2(int k ,int sp,int d,int rk){
	top[k] = sp;
	if(son[k] != -1){
		w[k] = ++totw;
	    fw[rk] = w[k];
		update(1,w[k],d);
		dfs_2(son[k],sp,dis[k],num[k]);
	}else{
		w[k] = ++ totw;
		fw[rk] = w[k];
		update(1,w[k],d);
		return ; 
	}
	for(int i = 0 ;i < mp[k].size() ;i ++){
		if(mp[k][i].ne == fa[k] || mp[k][i].ne == son[k])
			continue;
		dfs_2(mp[k][i].ne,mp[k][i].ne,mp[k][i].v,mp[k][i].rank);
	}
}
void make(){
	totw =0 ; 
	build(1,1,n+1);
    dfs_1(1,0,1);
	dfs_2(1,1,0,0);
}
int find(int u,int v){
   int f1 = top[u],f2 = top[v];
   int sum = 0 ; 
   while(f1 != f2){
		if(deep[f1] < deep[f2])
		{
			swap(u,v);
			swap(f1,f2);
		}
		sum += getsum(1,w[f1],w[u]);
		u = fa[f1];
		f1 = top[u];
   }
   if(deep[u] > deep[v]){
		swap(u,v);
   }
   sum += getsum(1,w[u]+1,w[v]);
   return sum; 
}
int main(){
   while(scanf("%d %d %d",&n,&q ,&s) !=  EOF){
	   for(int i = 1;i <= n;i ++)
		   mp[i].clear();
	   int ta,tb,tw;
	   for(int i = 1;i < n;i ++)
	   {
			scanf("%d %d %d",&ta,&tb,&tw);
			mp[ta].push_back(next(tb,tw,i));
			mp[tb].push_back(next(ta,tw,i));
	   }
	   make();
	   int op;
	   while(q--){
			scanf("%d",&op);
			if(op){
				scanf("%d %d",&ta,&tb);
				update(1,fw[ta],tb);
			}else{
			    scanf("%d",&ta);	
				printf("%d\n",find(s,ta));
				s = ta;  
			}
		   /*for(int i = 1 ;i <= n;i ++ )
			   printf("%d ",getsum(1,i,i));
		   printf("\n");*/
	   }
   }
return 0;
}
