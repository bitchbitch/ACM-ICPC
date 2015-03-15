// File Name: 332b.cpp
// Author: darkdream
// Created Time: 2014年07月30日 星期三 08时10分45秒

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
using namespace std;
#define M 200004
struct node{
  int l , r ,m; 
  LL maxn,s; 
}tree[M <<2];
LL a[200004];
LL sum[200004];
int L(int x)
{
  return 2 * x; 
}
int R(int x)
{
   return 2 * x + 1; 
}
void  pushup(int c)
{
   if(tree[L(c)].maxn >=tree[R(c)].maxn)
   {
      tree[c].maxn = tree[L(c)].maxn;
	  tree[c].s = tree[L(c)].s;
   }else{
      tree[c].maxn = tree[R(c)].maxn;
	  tree[c].s = tree[R(c)].s;
   }
}
void build(int c ,int l, int r)
{
      tree[c].l = l ;
	  tree[c].r = r ;
	  tree[c].m = (l+r)/2;
	  if(l == r)
	  {
	    tree[c].maxn = sum[l]; 
		tree[c].s = l ; 
		return ; 
	  }
	  build(L(c),l,tree[c].m);
	  build(R(c),tree[c].m+1,r);
	  pushup(c);
}
LL maxa; 
int site;
void find(int c, int l , int r)
{
	//printf("%d %d %d %d %d\n",c,tree[c].l,tree[c].r,l,r);
	 if(r <  l )
		 return ; 
     if(l <= tree[c].l && r >= tree[c].r)
	 {
	     if(tree[c].maxn > maxa)
		 {
		   maxa = tree[c].maxn;
		   site = tree[c].s; 
		 }
		 return ;
	 }
	 if(l <= tree[c].m)
		 find(L(c),l,r);
	 if(r > tree[c].m)
		 find(R(c),l,r);
}
int main(){
   int n , k;
   scanf("%d %d",&n,&k);
   int temp ;
   a[0] = 0 ; 
   for(int i = 1; i <= n;i ++)
   {
       scanf("%d",&temp);
       a[i] = a[i-1] + temp;
   }
   for(int i = 1 ;i <= n-k+1; i ++)
   {
      sum[i] = a[i+k-1] - a[i-1];
   }
   build(1,1,n-k+1);
   LL  ans = -1e9;
   int a, b ; 
   for(int i =1 ;i <= n-k+1;i ++)
   {
      maxa = -1e9 ;
	  site = 0 ; 
	  find(1,i+k,n-k+1);
	  if(sum[i] + maxa > ans)
	  {
	      ans  = sum[i] + maxa;
		  a= i ; 
		  b = site;
	  }
   }
   printf("%d %d\n",a,b);
return 0;
}
