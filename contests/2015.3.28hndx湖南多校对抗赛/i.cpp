// File Name: i.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 12时56分11秒

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
#define maxn 10005
using namespace std;
int a[maxn];
struct node{
  int l ,r , m , v; 
}tree[maxn*4];
int ans[maxn];
int L(int x)
{
 return 2 * x; 
}
int R(int x)
{
 return 2 *x + 1; 
}
void push_up(int c)
{
    tree[c].v = tree[L(c)].v + tree[R(c)].v; 
}
void build(int c ,int l , int r)
{
    tree[c].l = l; 
	tree[c].r = r ; 
	tree[c].m = (l + r)/2;
    if(tree[c].l ==tree[c].r)
	{
	    tree[c].v = 1; 
		return;
	}
	build(L(c),l,tree[c].m);
	build(R(c),tree[c].m+1,r);
	push_up(c);
}
int tt ;
void find(int c, int v)
{
   if(tree[c].l == tree[c].r)
   {
	  tt = tree[c].l ;
      tree[c].v = 0 ; 
      return ; 
   }
   if(tree[L(c)].v >= v)
   {
      find(L(c),v);
   }else{
      find(R(c),v-tree[L(c)].v);
   }
   push_up(c);
}
int ta;
int main(){
  int n ;
  while(scanf("%d",&n) != EOF)
  {
	build(1,1,n);
    memset(ans,0,sizeof(ans));
	int ok = 0 ;
	for(int i = 1;i <= n; i ++)
	{
      scanf("%d",&ta);
	  if(tree[1].v < ta+1)
	  {
		  ok = 1; 
		  continue;;
	  }
	  if(ok == 0 )
	  {
	    find(1,ta+1);
	    ans[tt] = i ; 
	  }
	}
	if(ok == 1)
		printf("No solution\n");
	else {
	  for(int i = 1;i <= n;i ++)
		  printf(i == 1?"%d":" %d",ans[i]);
	  printf("\n");
	}
  }
return 0;
}
