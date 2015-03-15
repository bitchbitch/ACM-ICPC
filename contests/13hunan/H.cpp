// File Name: H.cpp
// Author: darkdream
// Created Time: 2014年10月03日 星期五 09时41分27秒

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
int n , m , k ; 
int a[100005];
struct node{
	int l,r;
	int col;
}tree[maxn<<2];
int L(int x)
{
	return 2 * x ;
}
int R(int x)
{
	return 2*x + 1;
}
void pushdown(int c)
{
	tree[L(c)].col += tree[c].col;
	tree[R(c)].col += tree[c].col;
	tree[c].col = 0 ; 
}
void build(int c, int l , int r)
{
	tree[c].l = l ; 
	tree[c].r = r;
	tree[c].col = 0 ; 
	if(l == r)
	{
		return ;
	}
	build(L(c),l,(l+r)/2);
	build(R(c),(l+r)/2+1,r);
}
void update(int c, int l , int r)
{
	if(r < l)
		return ; 
	//printf("%d %d %d\n",c,l,r);
	if(tree[c].l >= l && tree[c].r <=  r)
	{
		tree[c].col ++ ; 
		return ; 
	}
	pushdown(c);
	int m = (tree[c].l + tree[c].r)/2;
	if(l <= m)
	{
		update(L(c),l,r);
	}
	if(r > m) {
		update(R(c),l,r);
	}
}
int ans; 
void solve(int c)
{
	if(tree[c].l == tree[c].r)
	{
		if(tree[c].col >= k )
			ans ++ ; 
		return;
	}
	pushdown(c);
	solve(L(c));
	solve(R(c));
}
int find(int k)
{
	int l ,r ;
	l = 1; 
	r = n; 
	while(l <= r)
	{
		int m = (l + r )/2;
		if(a[m] > k)
		{
			r = m -1;
		}else {
			l = m + 1; 
		}
	}
	return r;
}
int main(){
	int ca = 0 ; 
	while(scanf("%d %d %d",&n,&m,&k) != EOF)
	{
		ca ++ ; 
		for(int i = 1;i<= n;i ++)
		{
			scanf("%d",&a[i]);
		}
		sort(a+1,a+1+n);
		build(1,1,n);
		int la = find(1);
		int x, y;
		for(int i = 1;i <= m;i++)
		{
			scanf("%d %d",&x,&y);
			x = find(x);
			y = find(y);
			update(1,la+1,x);
			la = y;
		}
		ans = 0 ; 
		solve(1);
		printf("Case %d: %d\n",ca,ans);
	}
	return 0;
}
