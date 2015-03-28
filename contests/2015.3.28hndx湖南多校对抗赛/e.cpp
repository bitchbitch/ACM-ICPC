// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年03月28日 星期六 14时37分24秒

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
int n ;
int dp[maxn][2];
int a[maxn];
struct node{
	int l ,r , m , v; 
}tree[maxn*4];
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
	tree[c].v = max(tree[L(c)].v,tree[R(c)].v); 
}
void build(int c ,int l , int r)
{
	tree[c].l = l; 
	tree[c].r = r ; 
	tree[c].m = (l + r)/2;
	tree[c].v = -1; 
	if(tree[c].l ==tree[c].r)
	{
		return;
	}
	build(L(c),l,tree[c].m);
	build(R(c),tree[c].m+1,r);
}
int mx = 0 ; 
void find(int c,int l , int r)
{
     if(tree[c].l >= l && r >= tree[c].r)
	 {
	      mx = max(tree[c].v,mx);
		  return;
	 }
	 if(l <= tree[c].m)
		 find(L(c),l,r);
	 if(r > tree[c].m)
		 find(R(c),l,r);
}
void update(int c, int p , int v)
{
    if(tree[c].l == tree[c].r)
	{
	   tree[c].v = max(tree[c].v,v);
	   return;
	}
	if(p <= tree[c].m)
		update(L(c),p,v);
	else update(R(c),p,v);
	push_up(c);
}
int main(){
	while(scanf("%d",&n) != EOF)
	{
		 build(1,1,10000);
		 a[0] = 0 ;
		 memset(dp,0,sizeof(dp));
		 int ans = 0; 
         for(int i = 1;i <= n;i ++)
         {
			  scanf("%d",&a[i]);
		      if(a[i] > a[i-1] && i!= 1) 
			  {
			     dp[i][0] = dp[i-1][0] + 1;  
				 ans = max(dp[i][0],ans);
			     dp[i][1] = dp[i-1][1] + 1;  
			  }
			     update(1,a[i],dp[i][0]);
				 mx = -1;
				 if(a[i] != 1)
					 find(1,1,a[i]-1);
				 dp[i][1] = max(dp[i][1] ,mx + 1);
				 ans = max(dp[i][1],ans);
				 //printf("%d %d %d\n",dp[i][0],dp[i][1],mx);
		 } 
		 printf("%d\n",ans+1);
	}
return 0;
}
