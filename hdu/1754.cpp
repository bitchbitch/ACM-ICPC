// File Name: 1754.cpp
// Author: darkdream
// Created Time: 2014年07月09日 星期三 21时09分33秒

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
#include<climits>
#include<queue>

using namespace std;

#define maxn 200004
int L(int x)
{
   return x<<1; 
}
int R(int x)
{
   return x<<1|1;
}
struct node{
   int M;
   int l,r,m;
}tree[maxn*4];

int a[maxn];
void pushup(int c)
{
  tree[c].M = max(tree[L(c)].M,tree[R(c)].M);
}
void maketree(int c,int l ,int r)
{
    tree[c].l = l; 
	tree[c].r = r ; 
	tree[c].m = (l+r)/2;
	if(l == r )
	{
	   tree[c].M = a[l];
	   return ; 
	}
	maketree(L(c),l,tree[c].m);
	maketree(R(c),tree[c].m+1,r);
	pushup(c);
}

void update(int c, int p ,int x)
{
    if(tree[c].l == tree[c].r && tree[c].l == p )
	{
	    tree[c].M = x; 
		return ; 
	}
	if(p <= tree[c].m)
		update(L(c),p,x);
	else update(R(c),p,x);
	pushup(c);
}
int ans = -1;
void find(int c, int l,int r)
{
   if(tree[c].l >= l && tree[c].r <= r)
   {
      ans = max(ans,tree[c].M);
	  return ;
   }
   if(r <= tree[c].m)
	   find(L(c),l,r);
   else if(l > tree[c].m)
	   find(R(c),l,r);
   else {
       find(L(c),l,tree[c].m);
	   find(R(c),tree[c].m+1,r);
   }
}
int main(){
   int n , m ;
   while(scanf("%d %d",&n,&m) != EOF)
   {
	  memset(tree,0,sizeof(tree));
      for(int i = 1;i <= n; i ++)
		  scanf("%d",&a[i]);
	  maketree(1,1,n);
	  char str[10];
	  int a,b;
	  for(int i = 1;i <= m;i ++ )
	  {
		  ans = 0 ; 
	      scanf("%s %d %d",str,&a,&b);
		  if(str[0] == 'Q'){
			  find(1,a,b);
			  printf("%d\n",ans);
		  }else{
		     update(1,a,b);
		  }
	  }
   }
return 0;
}
