// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年03月18日 星期三 01时04分52秒

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
#define maxn 200005
using namespace std;
int w, h , n;
char str[10];
int v; 
struct node{
  int l , r , m ,v,lazy;
};
map<int ,int> wmp;
map<int ,int> hmp;
class sg{
	public:
    struct node tree[maxn*4];
	int L(int x)
	{
	   return 2 * x; 
	}
	int R(int x)
	{
	   return 2* x + 1; 
	}
	void build(int c, int l , int r ,int v)
	{
	      tree[c].l = l ; 
		  tree[c].r = r; 
		  tree[c].m = (l + r)/2;
		  tree[c].lazy = 0 ; 
		  if(l == r)
		  {
			  tree[c].v = v; 
			  return;
		  }
		  build(L(c),l,tree[c].m,v);
		  build(R(c),tree[c].m+1,tree[c].r,v);
		  push_up(c);
	}
	void push_up(int c)
	{
	     tree[c].v = max(tree[L(c)].v,tree[R(c)].v);
	}
	void push_down(int c)
	{
		 if(tree[c].lazy != 0 )
		 {
	      tree[L(c)].v = tree[c].lazy; 
		  tree[R(c)].v = tree[c].lazy;
		  tree[L(c)].lazy = tree[c].lazy;
		  tree[R(c)].lazy = tree[c].lazy;
		  tree[c].lazy = 0 ;
		 }
	}
	void update(int c, int l , int r,int v)
	{
	  if(l <= tree[c].l && r >= tree[c].r)
	  {
		   //printf("%d**%d\n",tree[c].v,v);
		   tree[c].lazy = v;
		   tree[c].v = v; 
		   return; 
	  }
	  push_down(c);
	  if(l <= tree[c].m )
		  update(L(c),l,r,v);
	  if(r > tree[c].m)
		  update(R(c),l,r,v);
	  push_up(c);
	}

}t1,t2; 
int main(){
    scanf("%d %d %d",&w,&h,&n);
	  t1.build(1,1,w,w);
	  t1.tree[1].lazy = w; 
	  t2.build(1,1,h,h); 
	  t2.tree[1].lazy = h;
	  wmp[0] = 1; 
	  wmp[w] = 1; 
	  hmp[0] = 1; 
	  hmp[h] = 1;
	  map<int ,int >::iterator l,m,r;
	  int tmpv;  
	for(int i = 1;i <= n;i ++)
	{
	  scanf("%s %d",str,&tmpv);
	  if(str[0] == 'H')
	  {
		  if(hmp.find(tmpv) == hmp.end())
		  {
			  hmp[tmpv] = 1;
			  l = hmp.find(tmpv);
			  l --;
			  m = hmp.find(tmpv);
			  r = hmp.find(tmpv);
			  r ++ ; 
			  t2.update(1,l->first,m->first,m->first- l->first);
			  t2.update(1,m->first+1,r->first,r->first - m->first);
		//	  printf("%d %d\n",m->first - l->first+1,r->first - m->first);
		  }
	  }else{
		  if(wmp.find(tmpv)== wmp.end() )
		  {
			  wmp[tmpv] = 1;
			  l = wmp.find(tmpv);
			  l --;
			  m = wmp.find(tmpv);
			  r = wmp.find(tmpv);
			  r ++ ;
		//	  printf("%d %d\n",m->first ,l->first);
			  //if(l->first == 1 )
	          t1.update(1,l->first,m->first,m->first- l->first );
			  t1.update(1,m->first+1,r->first,r->first - m->first);
		//	  printf("%d %d %d\n",t1.tree[1].v,m->first - l->first+1,r->first - m->first);
		  }
	  }
	  //printf("%d %d\n",t1.tree[1].v,t2.tree[1].v);
	  printf("%I64d\n",1ll*t1.tree[1].v*t2.tree[1].v);
	}
return 0;
}
