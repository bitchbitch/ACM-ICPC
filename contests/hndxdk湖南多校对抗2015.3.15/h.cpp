// File Name: h.cpp
// Author: darkdream
// Created Time: 2015年03月16日 星期一 15时22分06秒

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
#define maxn 100001
using namespace std;
struct node{
	int l , r,m, v, lazy,mx,mi ; 
}tree[maxn*4];
int mp[4590000];
int mpt;
int mpa[maxn];
int n,m,q;
char str[100];
struct que{
	int status,l,r,v;
}qu[maxn];
int L(int x)
{
	return 2* x; 
}
int R(int x)
{
	return 2 * x +1;
}
void build(int c, int l ,int r)
{
	tree[c].l = l ; 
	tree[c].r = r; 
	tree[c].m = (tree[c].l + tree[c].r)/2;
	if(l == r)
	{
		return; 
	}
	build(L(c),l,tree[c].m);
	build(R(c),tree[c].m+1,r);
}
int mx;
int mi;
void push_down(int c)
{
	tree[L(c)].lazy += tree[c].lazy;
	tree[R(c)].lazy += tree[c].lazy;
	tree[L(c)].mi += tree[c].lazy; 
	tree[L(c)].mx += tree[c].lazy; 
	tree[R(c)].mi += tree[c].lazy; 
	tree[R(c)].mx += tree[c].lazy; 
	tree[c].lazy = 0 ;
}
void push_up(int c)
{
	tree[c].mi = min(tree[L(c)].mi,tree[R(c)].mi);
	tree[c].mx = max(tree[L(c)].mx,tree[R(c)].mx);
}
void query(int c, int l , int r)
{
	if(l <= tree[c].l && r >= tree[c].r)
	{
		mi = min(mi,tree[c].mi);
		mx = max(mx,tree[c].mx);
		return ;
	}
	push_down(c);
	if(l <= tree[c].m)
		query(L(c),l,r);
	if(r > tree[c].m)
		query(R(c),l,r);
	push_up(c);
}
void update(int c, int l ,int r,int v)
{
	//printf("update ! c= %d l = %d r = %d tree[c].l = %d tree[c].r = %d v = %d \n",c,l,r,tree[c].l ,tree[c].r,v);
	if(l <= tree[c].l && r >= tree[c].r)
	{
		//	printf("update ! c= %d v = %d \n",c,v);
		tree[c].mi +=v; 
		tree[c].mx +=v;
		tree[c].lazy += v;
		return;
	}
	push_down(c);
	if(l <= tree[c].m)
		update(L(c),l,r,v);
	if(r > tree[c].m)
		update(R(c),l,r,v);
	push_up(c);
}
int main(){
	//freopen("large-crafted2.in","r",stdin);
	//freopen("out","w",stdout);
	while(scanf("%d %d %d",&n,&m,&q)!= EOF)
	{
		mpt = 0 ; 
		int ta, tb; 
		for(int i = 1; i <= q;i ++)
		{
			scanf("%s",str) ;
			if(str[0] == 's')
			{
				qu[i].status = 1; 
				scanf("%d",&qu[i].l);
				mpt ++ ; 
				mpa[mpt] =  qu[i].l ; 
			}else if(str[0] == 'c')
			{
				qu[i].status = 2; 
				scanf("%d %d",&qu[i].l ,&qu[i].v);
				mpt ++ ; 
				mpa[mpt] = qu[i].l ; 

			}else{
				qu[i].status = 3; 
				scanf("%d %d %d",&qu[i].l,&qu[i].r,&qu[i].v);
				mpt ++ ; 
				mpa[mpt] = qu[i].l ; 
				mpt ++ ; 
				mpa[mpt] = qu[i].r ; 
			}
		}
		sort(mpa +1 ,mpa + mpt + 1);
		int tt = 0  ; 
		for(int i = 1;i <= mpt ;i ++)
		{
			if(i != 1 && mpa[i] == mpa[i-1])
				continue;
			mp[mpa[i]]  = ++tt ; 
		}
		build(1,1,tt);
		int tmp ,tmpa,tmpb;
		for(int i = 1;i <= q;i ++)
		{
			mi = 1e9;
			mx = 0 ;
			if(qu[i].status == 1)
			{
				 tmp = mp[qu[i].l];
				query(1,tmp,tmp);
				printf("%d\n",mx);
			}else
			{
				 tmpa = mp[qu[i].l];
				 tmpb = tmpa; 

				if(qu[i].status == 3)
					tmpb = mp[qu[i].r];
				query(1,tmpa,tmpb);
				//printf("%d %d**%d %d %d\n",tmpa,tmpb,mi,mx,min(m-mx,qu[i].v));
				if(qu[i].v > 0){
					update(1,tmpa,tmpb,min(m-mx,qu[i].v)) ;
					printf("%d\n",min(m-mx,qu[i].v));
				}else{
					update(1,tmpa,tmpb,max(-mi,qu[i].v)) ;
					printf("%d\n",max(-mi,qu[i].v));
				}
			}
		}
	}
	return 0;
}
