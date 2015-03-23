// File Name: 487b.cpp
// Author: darkdream
// Created Time: 2015年03月23日 星期一 13时50分29秒

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
int a[maxn];
struct node{
   int l , r , m ,mi,mx ; 
}tree[maxn*4];
int L(int x)
{
  return 2 * x; 
}
int R(int x)
{
   return 2 * x + 1;
}
void push_up(int c)
{
   tree[c].v = max(tree[L(c)].v,tree[R(c)].v);
}
void build(int c,int l , int r)
{
      tree[c].l = l  ;
	  tree[c].r = r;
	  tree[c].m = (l + r)/2;
	  tree[c].mi = 1e9;
	  tree[c].mx = -1e9;
	  if(l ==  r)
	  {
	    return ; 
	  }
	  build(L(c),l,tree[c].m);
	  build(R(c),tree[c].m + 1,r);
}
int mx = -1e9;
int mi =  1e9;
void update(int c, int p, int v)
{
    if(tree[c].l == tree[c].r)
	{
	   tree[c].v = min(tree[c].v,v);
	   return;
	}
	if(p <= tree[c].m)
		update(L(c),p,v);
	else update(R(c),p,v);
    push_up(c);
}
void findmxi(int c, int l ,int r)
{
    if(l <= tree[c].l && r >= tree[c].r)
	{
	    mx = min(tree[c].v,mx);
	   return;
	}
	if(l <= tree[c].m)
		findmi(L(c),l,r);
	if(r > tree[c].m)
		findmi(R(c),l,r);
}
int n , s, l ; 
int findsite(int v)
{
    int l = 1; 
	int r = n;
	int m ; 
	while(l <= r )
	{
       m = (l + r) >>1;
	   if(a[m] < v)
		   l = m + 1;
	   else r = m -1; 
	}
	return l ; 
}
int main(){
    scanf("%d %d %d",&n,&s,&l);
	for(int i = 1;i <= n;i ++)
	{
	   scanf("%d",&a[i]);
	}
	printf("%d\n",mx);
return 0;
}
