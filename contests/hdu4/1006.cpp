// File Name: 1006.cpp
// Author: darkdream
// Created Time: 2014年07月31日 星期四 12时46分19秒

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

using namespace std;
#define maxn 100005 
struct node{
	int l , r ; 
	int is1;
	int limits;
}tree[maxn << 2];
int a[maxn];
int L(int x)
{
	return 2*x; 
}
int gcd(int a, int b)
{
	return b == 0 ?a:gcd(b,a%b);
}
int R(int x)
{
	return 2 * x + 1; 
}
void pushup(int c)
{
	tree[c].limits = max(tree[L(c)].limits,tree[R(c)].limits);
}
void pushdown(int c)
{
	if(tree[c].is1)
	{
		tree[L(c)].is1 = 1; 
		tree[R(c)].is1 = 1;
		tree[c].is1 = 0;
		tree[L(c)].limits = tree[R(c)].limits = tree[c].limits;
	}
}
void build(int c , int l ,int r)
{
	tree[c].l = l ; 
	tree[c].r = r;
	tree[c].is1 = 0 ; 
	if(l == r)
	{
		tree[c].limits = a[l];
		return ;
	}
	int m = (l+r)/2;
	build(L(c),l,m);
	build(R(c),m+1,r);
	pushup(c);
}
void update1(int c, int l , int r,int x)
{
	if(l <= tree[c].l && r >= tree[c].r)
	{
		tree[c].is1 = 1;
		tree[c].limits = x; 
		return ;
	}
	int m = (tree[c].l+ tree[c].r)/2;
	pushdown(c);
	if(l <= m)
		update1(L(c),l,r,x);
	if( r > m )
		update1(R(c),l,r,x);
	pushup(c);
}
void update2(int c, int l , int r,int x)
{
	if(tree[c].limits < x)
	{
		return ; 
	}
	if(tree[c].is1 && l <= tree[c].l && r >= tree[c].r)
	{
		tree[c].limits = gcd(tree[c].limits,x);
		return ;
	}
	if(tree[c].l == tree[c].r)
	{
		tree[c].is1 = 0 ; 
		tree[c].limits = gcd(x,tree[c].limits);
		return; 
	}
	int m = (tree[c].l+ tree[c].r)/2;
	pushdown(c);
	if(l <= m)
		update2(L(c),l,r,x);
	if( r > m )
		update2(R(c),l,r,x);
	pushup(c);
}
void put(int l , int r , int x)
{
//	printf("****%d %d\n",l,r);
	for(int i =l ;i <= r;i ++ )
		a[i] = x;
	return; 
}
void get(int c )
{
	if(tree[c].is1) 
	{
		put(tree[c].l,tree[c].r,tree[c].limits);
		return; 
	}
	if(tree[c].l == tree[c].r)
	{
		a[tree[c].l] = tree[c].limits;
		return; 
	}
	pushdown(c);
	get(L(c));
	get(R(c));
}
int main(){
	int t;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		//memset(tree,0,sizeof(tree));
		int n ,m;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++)
	    {		
			scanf("%d",&a[i]);
		 //   printf("%d ",a[i]);
		}
		//printf("\n");
		build(1,1,n);
		scanf("%d",&m);
		int ta,tb,tc,td;
		for(int i = 1;i <= m;i ++)
		{
			scanf("%d %d %d %d",&ta,&tb,&tc,&td);
			if(ta == 1)
			{
				update1(1,tb,tc,td);
			}else{
				update2(1,tb,tc,td);
			}
		}
		get(1);
		for(int i =1;i <= n;i ++)
			printf("%d ",a[i]);
		printf("\n");
		//printf("%d\n",t);
	}
	return 0;
}
