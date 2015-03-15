// File Name: 522d.cpp
// Author: darkdream
// Created Time: 2015年03月12日 星期四 14时09分15秒

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
#define maxn 500005
using namespace std;
struct que{
  int l , r,si; 
}qu[maxn];
struct node{
  int l , r  ,m ; 
  int v; 
}tree[maxn*4];
int ans[maxn];
int L(int x)
{
   return 2 * x; 
}
int R(int x )
{
   return 2 * x+ 1; 
}
void build(int c, int l, int r)
{
    tree[c].l = l ; 
	tree[c].r = r; 
	tree[c].m = (l + r) >>1;
    tree[c].v = maxn +1000 ;
	if(tree[c].l == tree[c].r)
	{
	   return ;
	}
	build(L(c),tree[c].l ,tree[c].m);
	build(R(c),tree[c].m+1,tree[c].r);
}
void push_up(int c)
{
     tree[c].v = min(tree[L(c)].v,tree[R(c)].v);
}
void update(int c, int p,int v)
{
     if(tree[c].l == tree[c].r && tree[c].l == p)
	 {
	   tree[c].v = v;
	   return ;
	 }
	 if(p <= tree[c].m)
		 update(L(c),p,v);
	 else update(R(c),p,v);
	 push_up(c);
}
int mi;
void findans(int c, int l ,int r )
{
    if(l <= tree[c].r && r >= tree[c].r)
	{
        mi = min(mi,tree[c].v);
		return;
	}
	if(l <= tree[c].m)
        findans(L(c),l,r);
	if(r > tree[c].m)
		findans(R(c),l,r);
}
map<int ,int>mp;
int a[maxn];
int cmp(que a, que b)
{
   return a.l > b.l;
}
int main(){
   int n , m ; 
   scanf("%d %d",&n,&m);
   build(1,1,n);
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
   }
   for(int i = 1;i <= m;i ++)
   {
      scanf("%d %d",&qu[i].l,&qu[i].r);
      qu[i].si = i ;
   }
   sort(qu+1,qu+1+m,cmp);
   int t = 1; 
   for(int i = n;i >= 1;i --)
   {
       if(mp[a[i]])
	   {
		  //printf("%d %d\n",mp[a[i]],mp[a[i]]-i);
	      update(1,mp[a[i]],mp[a[i]]-i);
	   }
		mp[a[i]] = i ;
	   while(qu[t].l == i)
	   {
	      mi = maxn + 1000;
		  findans(1,qu[t].l,qu[t].r);
		  if(mi == maxn + 1000 )
			  mi = -1;
		  ans[qu[t].si] = mi;
		  t ++; 
	   }
   }
   for(int i = 1;i <= m;i ++)
	   printf("%d\n",ans[i]);
return 0;
}
