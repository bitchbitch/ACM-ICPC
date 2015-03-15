// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年05月07日 星期三 17时07分23秒

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
#define MAXN  200005

int a[MAXN];
int hs[MAXN];
struct node{
	int l, r , m ; 
	int sum ;
}tree[MAXN*4];

int L(int x)
{
	return x << 1; 
}
int R(int x)
{
	return x << 1|1;
}
void pushup(int c)
{
	tree[c].sum = tree[L(c)].sum + tree[R(c)].sum ; 
}
void build(int c, int l , int r)
{
	tree[c].l = l ; 
	tree[c].r = r ; 
	tree[c].m = (l+r)/2;
	if(l == r)
	{
		tree[c].sum  = 0;
		return ;
	}
	build(L(c),l,tree[c].m);
	build(R(c),tree[c].m+1,r);
	pushup(c);
}
int sum = 0 ; 
void getsum(int c, int l , int r )
{
	if(tree[c].l >= l && tree[c].r  <=  r)
	{
		sum += tree[c].sum;
		return;
	}
	if(r <= tree[c].m)
		getsum(L(c),l,r);
	else if(l > tree[c].m)
		getsum(R(c),l,r);
	else {
		getsum(L(c),l,tree[c].m);
		getsum(R(c),tree[c].m+1,r);
	}
}

void update(int c, int p)
{
	if(tree[c].l == tree[c].r && tree[c].l == p )
	{
	/*	if(tree[c].sum == 0 )
			tree[c].sum = 2;
		else*/ 
		   tree[c].sum += 1; 
		return;
	}
	if(p <= tree[c].m)
		update(L(c),p);
	else update(R(c),p);
	pushup(c);
}
struct lr{
	int l,r,num;
}q[MAXN];
int cmp(lr a, lr b)
{
	return a.l > b.l;
}
int ans[MAXN];
int isupdate[MAXN];
int main(){
	int n ,m ; 
	while(scanf("%d %d", &n,&m) != EOF)
	{
		if(n == 0 && m == 0 )
			break;
		build(1,1,n);
		for(int i = 1;i <= n;i ++)
			scanf("%d",&a[i]);
		memset(hs,0,sizeof(hs));
		for(int i = 1;i <= m;i ++)
		{
			scanf("%d %d",&q[i].l,&q[i].r);
			q[i].num = i; 
		}
		sort(q+1,q+m+1,cmp);
		int p = 1;
		memset(hs,0,sizeof(hs));
		for(int i = n;i >= 1 ;i--)
		{
			for(int j = 1; j <= sqrt(a[i]+1.0); j ++)
			{
				int min = MAXN;
				int tsum = 0 ; 
				if(a[i] % j == 0 )
				{
					if(hs[j] && j != 1 )
					{
						if(hs[j] < min)
							min = hs[j];
						update(1,hs[j]);
						tsum ++ ; 
					}
					hs[j] = i ; 
					int temp = a[i]/j ; 
					if(temp  != j&& hs[temp])
					{
						if(hs[temp] < min)
							min = hs[temp];
						update(1,hs[temp]);
						tsum ++ ;
					}
					hs[temp] = i ;
				}
				if(min != MAXN)  
				update(1,min);
			}
			while(q[p].l == i )
			{
				sum = 0 ;
				getsum(1,q[p].l,q[p].r);
				ans[q[p].num] = (q[p].r - q[p].l +1) - sum;
				p++;
			}
		}
		for(int i = 1;i <= m;i ++)
			printf("%d\n",ans[i]);

	}
	return 0;
}
