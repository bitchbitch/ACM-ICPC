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
#define maxn 200000
using namespace std;
struct node{
   int l , r,m, v, lazy,mx,mi ; 
}tree[maxn*4];
int map<int,int>mp;
int mpt;
int mpa[maxn];
int n,m,q;
struct q; 
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
  tree[c].lazy = tree[c].mi = tree[c].mx = 0 ; 
  if(l == r)
  {
    return; 
  }
}
int main(){
  scanf("%d %d %d",&n,&m,&q);
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
	 }else if(str[1] == 'c')
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
	 sort(mpa +1 ,mpa + mpt + 1);
	 for(int i = 1;i <= mpt ;i ++)
	 {
	     mp[mpa[i]]  = i ; 
	 }
	 build(1,1,mpt);
	 for(int i = 1;i <= n;i ++)
	 {
       
	 }
  }
	
  return 0;
}
