// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月18日 星期四 23时29分43秒

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
#define MAX 100005
int a[MAX];
int ans = 0 ;
int L(int  c)
{
  return  c << 1;
}
int R(int c)
{
   return (c <<1) | 1;
}
struct node
{
   int left , right ,mid;
   double mx;
   int mxsite;
}tree[MAX * 4];
struct node1{
  double x,y;
}nd[100005];
double  tt ;  
void up(int c)
{
   if(tree[L(c)].mx > tree[R(c)].mx)
   {
       tree[c].mx = tree[L(c)].mx;
	   tree[c].mxsite = tree[L(c)].mxsite;
   }else{
       tree[c].mx = tree[R(c)].mx;
	   tree[c].mxsite = tree[R(c)].mxsite;
   }
}
void build(int c, int p , int v )
{
    tree[c].left = p ;
    tree[c].right = v;
    tree[c].mid = (p + v ) >> 1;
    if(p == v )
    {
        tree[c].mx = nd[p].y;
        tree[c].mxsite = p ; 
		return ;
    }
    build(L(c),p,tree[c].mid);
    build(R(c),tree[c].mid+1,v);
    up(c);
}
int findleft(int c, int l , int r)
{
 
}
int findright(int c, int l ,int r)
{

}
bool cmp(node1 x , node1 y)
{
     return x.x < y.x;
}
int n;
int f(double x)
{
    int l = 1;
	int r = n; 
	
	while(l <= r )
	{
	  int m = (l + r)/2; 
	  //printf("%d %lf\n",m,nd[m].x);
	  if(nd[m].x > x)
	  {
	    r = m-1;        
	  }else{
	    l = m+1; 
	  }
	}
	return r;
}
int main()
{
    int t ;
    scanf("%d",&t);
    for(int CASE = 1; CASE <= t ;  CASE ++)
    {
       scanf("%d",&n);
       for(int i = 1;i <= n;i ++)
	   {
	      scanf("%lf %lf",&nd[i].x,&nd[i].y);  
	   }
	   sort(nd+1,nd+1+n,cmp);
	   build(1,1,n); 
	   for(int i = 1;i <= n;i ++)
		   printf("%lf %lf\n",nd[i].x,nd[i].y);
       int m ; 
	   scanf("%d",&m);
	   double temp ; 
	   while(m --)
	   {
		   scanf("%lf",&temp);
		   int k = f(temp);
	       //printf("%d\n",k);
		   
	   }
    
	}
    return 0 ;
}
