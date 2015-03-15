// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年11月15日 星期六 16时10分11秒

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
#define maxn 41000
using namespace std;
struct p{
  int x,y ; 
}a[11000];
struct node{
  int l  ,r ; 
  int mx;
  int add; 
}tr[maxn << 2];
vector<int> mp[maxn];

int L(int x)
{
  return 2 * x; 
}
int R(int x )
{
   return 2 * x + 1; 
}
void push_up(int x)
{
   tr[x].mx = max(tr[L(x)].mx,tr[R(x)].mx);
}

void push_down(int x)
{
    if(tr[x].add != 0 )
	{
	    tr[L(x)].mx += tr[x].add;
		tr[R(x)].mx += tr[x].add;
		tr[L(x)].add += tr[x].add;
		tr[R(x)].add += tr[x].add;
	    tr[x].add = 0 ; 
	}
}
void build(int c ,int l , int r)
{
   tr[c].l = l ; 
   tr[c].r = r; 
   tr[c].mx = 0 ; 
   tr[c].add = 0 ; 
   if(l ==  r)
   {
     return;
   }
   int m = (l + r) >> 1; 
   build(L(c),l,m);
   build(R(c),m+1,r);
}
void update(int c, int l ,int r ,int v)
{
   if(tr[c].l >= l && tr[c].r <=  r)
   {
       tr[c].mx += v; 
	   tr[c].add +=v; 
       return;
   }
   push_down(c);
   int m = (tr[c].l + tr[c].r) >> 1; 
   if(l <= m)
	   update(L(c),l,r,v);
   if(r > m)
	   update(R(c),l,r,v);
   push_up(c);
}
int cmp(p a ,p b)
{
   if(a.x == b.x)
   {
      return a.y < b.y;
   }
   return a.x < b.x;
}
int n , w , h ;  
void solve(int x, int v)
{
   int k = mp[x].size();
   //printf("***\n");
   for(int i = 0 ;i < k ;i ++)
   {
	//printf("%d %d\n",x,mp[x][i]);
     int l = mp[x][i];
     int r = min(l+h,40005);
	 update(1,l,r,v);
	 //printf("%d %d\n",l,r);
   }
}
int main(){
	while(scanf("%d",&n) != EOF)
	{
	  if(n <  0 )
		  break;
	  scanf("%d %d",&w,&h);
      for(int i = 1;i <= n;i ++)
	  {
	      scanf("%d %d",&a[i].x,&a[i].y);
		  a[i].x += 20001;
          a[i].y += 20001;
	  }
	  build(1,1,40005);
	  sort(a+1,a+1+n,cmp);
	  //for(int i = 1;i <= n;i ++)
		//  printf("%d %d\n",a[i].x,a[i].y);
      for(int i = 1;i <= 40005; i ++)
		  mp[i].clear();
	  for(int i = 1;i <= n;i ++)
	  {
	    mp[a[i].x].push_back(a[i].y);
	  }
	  int ans = 0 ; 
	  for(int i = 1;i <= 40005;i ++)
	  {
	      int t = i - w - 1; 
		  if(t  > 0 )
		  {
		    solve(t,-1);
		  }
		  solve(i,1);
		  ans = max(tr[1].mx,ans);
	  }
	  printf("%d\n",ans);
	}
	return 0;
}
