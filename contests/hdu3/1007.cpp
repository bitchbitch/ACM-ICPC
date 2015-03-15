// File Name: 1007.cpp
// Author: darkdream
// Created Time: 2014年07月29日 星期二 12时49分33秒

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
#define maxn 100005
struct node{
  int is3 ; 
  int m , r , l ;  
  LL sum ,fsum ; 
}tree[maxn << 2];
LL f[100];
int L(int x)
{
   return 2* x;
}
int R(int x)
{
   return 2*x + 1; 
}
void pushup(int c)
{
   tree[c].sum = tree[L(c)].sum + tree[R(c)].sum ; 
   tree[c].fsum = tree[L(c)].fsum + tree[R(c)].fsum ;
}
void  build(int c, int l , int r )
{ 
     tree[c].l = l ; 
	 tree[c].r = r; 
	 tree[c].m = (l+r)/2;
	 tree[c].is3 = 0 ; 
	 if(l ==  r)
	 {
	    tree[c].sum = 0 ; 
		tree[c].fsum = 1 ; 
		return ; 
	 }
	 build(L(c),l,tree[c].m);
	 build(R(c),tree[c].m+1,r);
	 pushup(c);
}
LL ABS(LL x)
{
   if(x <= 0 )
    return -x; 
   else return x; 
}
LL find( LL x )
{
    int l = 1 , r = 85 ;
	while(l <= r )
	{
	   int m = (l + r)/2; 
       if(f[m] > x)
	   {
	       r = m - 1; 	
	   }else {
	       l = m + 1; 
	   }
	}
//	printf("%I64d %I64d\n",f[l],f[r]);
    if(ABS(f[l]-x) < ABS(f[r]-x))
	{
	   return f[l];
	}else return f[r];
}
void pushdown(int c)
{
    if(tree[c].is3)
	{
	   tree[L(c)].is3 = 1; 
	   tree[R(c)].is3 = 1;
	   tree[L(c)].sum = tree[L(c)].fsum;
	   tree[R(c)].sum = tree[R(c)].fsum;
	   tree[c].is3 = 0 ; 
	}
}
void update(int c, int k , int d)
{
     if(tree[c].l == tree[c].r&& tree[c].l == k )
	 {
		 tree[c].is3  = 0 ; 
		 tree[c].sum += d; 
		 tree[c].fsum = find(tree[c].sum);
         return ;            	 
	 }
     pushdown(c);
	 if(k <= tree[c].m) 
		 update(L(c),k,d);
	 else update(R(c),k,d);
	 pushup(c);
}
LL ans = 0 ; 
void get(int c , int l , int r)
{
       if(l <= tree[c].l && r >= tree[c].r )
	   {
		 ans += tree[c].sum ;
		 // printf("%I64d\n",ans);
	     return ;
	   }
	 pushdown(c);
	 if(l <= tree[c].m)
		 get(L(c),l,r);
	 if(r > tree[c].m)
		 get(R(c),l,r);
}
void change(int c, int l , int r)
{
	  if(tree[c].is3 == 1)
		  return ;
      if(l <= tree[c].l && r >= tree[c].r)
		{
	          tree[c].is3 = 1;
			  tree[c].sum = tree[c].fsum;
			  return ;
		}
	 if(l <= tree[c].m)
		 change(L(c),l,r);
	 if(r > tree[c].m)
		 change(R(c),l,r);
	 pushup(c);
}
int main(){
   int n , m; 
   f[0] = 1 ;
   f[1] = 1; 
   for(int i = 2;i <= 86;i ++)
	   f[i] = f[i-1] + f[i-2];
   while(scanf("%d %d",&n,&m) != EOF)
   {
	   build(1 ,1,n);
	   int a, b, c  ;
       for(int i = 1;i <= m;i ++)
	   {
	     int a, b, c  ;
		 scanf("%d %d %d",&a,&b,&c);
		 if(a == 1 )
		 {
		    update(1,b,c);
		 }else if(a == 2 ){
			ans = 0 ; 
		    get(1,b,c);
		    printf("%I64d\n",ans);	
		 }else{
		    change(1,b,c);
		 }
	   }
   }
return 0;
}
