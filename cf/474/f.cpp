// File Name: f.cpp
// Author: darkdream
// Created Time: 2014年10月07日 星期二 21时25分35秒

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
struct node{
   int l , r ; 
   int gcd;
}tree[maxn << 2];
int a[maxn];
struct node1{
    int v,p; 
}b[maxn];
int gcd(int x, int y )
{
   return y == 0 ? x:gcd(y,x%y);
}
int L(int x)
{
   return 2 * x ; 
}
int R(int x)
{
   return 2 * x + 1 ; 
}
void pushup(int c)
{
   tree[c].gcd = gcd(tree[L(c)].gcd,tree[R(c)].gcd);
}
void build(int c, int l , int r)
{
   tree[c].l = l ;
   tree[c].r = r;
   //printf("%d %d %d\n",c,l,r);
   if(l == r)
   {
      tree[c].gcd = a[l];
	  return ;
   }
   int m = (l + r)/2;
   build(L(c),l,m);
   build(R(c),m+1,r);
   pushup(c);
}
int cmp(node1 a, node1 b)
{
  if(a.v == b.v)
  {
    return a.p < b.p ;
  }
  return a.v < b.v ; 
}
int ans = 0 ;

void query(int c, int l, int r)
{
	//printf("%d %d %d %d %d \n",c,l,r,tree[c].l ,tree[c].r);
    if(tree[c].l >= l && tree[c].r <= r)
	{
	     ans = gcd(ans,tree[c].gcd);
		 return ;
	}
	int m = (tree[c].l + tree[c].r)/2;
    if(l <= m)
	     query(L(c),l,r);
	if(r > m )
		 query(R(c),l,r);
}
int n ;
int  find(int x)
{
    int l = 1; 
	int r = n ; 
	while(l <= r)
	{
	  int m = (l +r )/2;
	  if(b[m].v <= x)
	  {
	     l = m + 1;  ; 
	  }else {
	     r = m - 1; 
	  }
	}
	return l ; 
}
int ll, rr ;
int find1(int x)
{
	int l = ll ;
	int r = rr ; 
	while(l <= r)
	{
	  int m = (l +r )/2;
	  if(b[m].p <= x)
	  {
	     l = m + 1;  ; 
	  }else {
	     r = m - 1; 
	  }
 	}
   return l ;
}
int main(){
   scanf("%d",&n);
   for(int i =1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
	  b[i].v = a[i];
	  b[i].p = i;
   }
   build(1,1,n);
   sort(b+1,b+n+1,cmp);
   //for(int i =1 ;i <= n;i ++)
	 //  printf("%d %d\n",b[i].v,b[i].p);
   int m ; 
   scanf("%d",&m);
   for(int i = 1;i <= m;i ++)
   {
     int l , r ; 
	 scanf("%d %d",&l,&r);
	 ans = a[l];
	 query(1,l,r);
	 //printf("%d\n",ans);
	 ll = find(ans-1);
	 if(b[ll].v != ans)
	 {
	     printf("%d\n",r-l+1);
		 continue;
	 }else{
	     rr = find(ans);
		 rr --;
		 int x, y ; 
		 x = find1(l-1);
		 if(b[x].p > r)
		 {
	        printf("%d\n",r-l+1);
			continue;
		 }else{
		    y = find1(r);
		    y -- ;
            printf("%d\n",r-l+1 - (y-x+1));
		 } 
	 }

   }
return 0;
}
