// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年09月21日 星期日 13时49分03秒

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
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long
#define pi acos(-1.0)
using namespace std;
struct node{
  double x, h; 
}nd[100005];
struct node1{
  double v ; 
  int site;
}a[100005];

int cmp1(node x, node y)
{
   return x.h > y.h;
}
int cmp(node1 x, node1 y )
{
  return x.v < y.v ;
}

double lj[100005];
double rj[100005];
int n , m; 
int find(double x)
{
   int l = 0; 
   int r = m ; 
   while(l <= r)
   {
      int mid = (l + r) /2; 
	  if(a[mid].v > x )
	  {
	     r = mid - 1;
	  }else{
	     l = mid + 1;
	  }
   }
   return r;
}
double ans[100105];
int main(){
  int t ;
  scanf("%d",&t);
  for(int ca = 1;ca <= t; ca ++)
  {
	 scanf("%d",&n);
	 for(int i = 1;i <= n;i ++)
	 {
	   scanf("%lf %lf",&nd[i].x,&nd[i].h); 
	 }
	 sort(nd+1,nd+1+n,cmp1);
	 scanf("%d",&m);
	 for(int i = 1;i <= m;i ++)
	 {
	   scanf("%lf",&a[i].v);
	   a[i].site = i ; 
	 } 
	 sort(a+1,a+1+m,cmp);
	 a[0].v = 0 ; 
	 memset(lj,0,sizeof(lj));
	 memset(rj,0,sizeof(rj));
	 for(int i = 1;i <= n;i ++)
	 {
	    int k =find(nd[i].x);
		for(int j = k ;j >= 1 ;j --)
		{
		   if(nd[i].h/(nd[i].x- a[j].v) > lj[j])
		   {
		        lj[j] = nd[i].h/(nd[i].x - a[j].v);
		   }else{
		     break;
		   }
		}
		for(int j = k + 1 ;j <= m;j ++)
		{
		   if(nd[i].h/(a[j].v-nd[i].x) > rj[j])
		   {
		        rj[j] = nd[i].h/( a[j].v - nd[i].x) ;
		   }else{
		     break;
		   }
		}
	
	 }
	 printf("Case #%d:\n",ca);
	 for(int i = 1;i <= m;i ++)
	 {
	    ans[a[i].site] = (90.0-atan(lj[i])*180/pi) + (90.0-atan(rj[i])*180/pi);    
	 }
	 for(int i= 1;i <= m;i ++)
	 {
	    printf("%lf\n",ans[i]) ;
	 }
  }
return 0;
}
