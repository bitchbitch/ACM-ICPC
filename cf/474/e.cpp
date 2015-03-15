// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年10月07日 星期二 01时29分07秒

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
LL a[maxn];
LL b[maxn];
int la[maxn];
int dp[maxn];
map <LL,int> mp;
struct node{
   int l ,r; 
   int mx;
   int site;; 
}tree[maxn << 2];
int L(int x)
{
  return 2 * x;
}
int R(int x)
{
  return  2 * x + 1 ;
}
void build(int c, int l , int r)
{
    tree[c].l =  l ; 
	tree[c].r = r; 
	tree[c].mx = 0 ; 
	tree[c].site = 0 ; 
    if(l == r)
	{
	   return ; 
	}
	build(L(c),l,(l+r)/2);
	build(R(c),(l+r)/2+1,r);
}
void pushup(int c)
{
    if(tree[L(c)].mx > tree[R(c)].mx)
	{
        tree[c].mx = tree[L(c)].mx; 
		tree[c].site = tree[L(c)].site;
	}else {
        tree[c].mx = tree[R(c)].mx; 
		tree[c].site = tree[R(c)].site;
	}
}
void update(int c, int k,int st,int v )
{
    if(tree[c].l == tree[c].r  && tree[c].l == k )
	{
	    tree[c].mx = v ; 
		tree[c].site = st ; 
	    return ;
	}
	if(k <= (tree[c].l + tree[c].r)/2)
	{
	    update(L(c),k,st,v);
	}else {
	    update(R(c),k,st,v);
	}
	pushup(c);
}
int mx ;
int site; 
void query(int c, int l ,int r)
{
      if(tree[c].l>= l && tree[c].r <= r)
      {
	     if(tree[c].mx > mx )
		 {
		    mx = tree[c].mx;
			site = tree[c].site ; 
		 }
		 return;
	  }
	  int m = (tree[c].l + tree[c].r) /2;
	  if(l <= m)
	     query(L(c),l,r);
	  if(r > m)
		 query(R(c),l,r);
}
int n , d; 
int find(LL x)
{
    int l = 1; 
	int r = n; 
    while(l <= r )
	{
	   int m = (l + r)/2;
	   if(b[m] <= x)
	   {
	      l = m + 1; 
	   }else {
	      r = m - 1;
	   }
	}
	return l;
}
void solve(int k )
{
   if(k == 0 )
	   return;
   solve(la[k]);
   printf("%d ",k);
}
int main(){
	scanf("%d %d",&n,&d);
	for(int i =1 ;i <= n;i ++)
	{
	    scanf("%I64d",&a[i]);
	    b[i] = a[i];
	}
	sort(b+1,b+1+n);
	mp.clear();
	b[0] = 0 ; 
	int num = 0 ; ;
	for(int i = 1;i <= n;i ++)
	{
		if(b[i] != b[i-1])
		{
			num ++ ;
      	   mp[b[i]] = num;
		}
	}
	build(1,1,num);
	//printf("****%d\n",num);
    int p = 0 ;
	int pmx =0; 
	for(int i =1;i <= n;i ++)
	{
	   int t = mp[a[i]];
       int l = find(a[i] - d);
	   int r = find(a[i] + d - 1);
	   
	   mx = 0; 
	   site = 0 ;
	   if(l != 1)
	   {
		 //printf("mp[b[l-1]] = %d\n",mp[b[l-1]]);
         query(1,1,mp[b[l-1]]);
	   }
	   if(r != n + 1)
	   {
		  //printf("mp[b[r]] = %d %d\n",mp[b[r]],r);
	      query(1,mp[b[r]],num);
	   }
	   la[i] = site;
	   //if(mx != 0 || i == 1)
	      mx ++ ; 
	   
	   dp[i] = mx;
	   if(mx > pmx)
	   {
	     pmx = mx ; 
		 p = i ;    
	   }
	   //printf("%d %d %d\n",t,i,mx);
	   update(1,t,i,mx); 
	  // printf("%d %d %d %d\n",t,mx,site,tree[1].mx);
	}
    
	printf("%d\n",pmx);
	solve(p);
	/*printf("\n");
	for(int i = 1;i <= n;i ++)
		printf("%d ",la[i]);
	
		*/
	return 0;
}
