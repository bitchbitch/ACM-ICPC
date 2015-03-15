// File Name: 4d.cpp
// Author: darkdream
// Created Time: 2014年08月04日 星期一 19时24分49秒

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

struct node{
  int from;
  int len;
}dp[5000];
struct node1{
  int w, h,s; 
}a[5005];
int ok[10000];
int cmp(node1 a,node1 b)
{
   if(a.w == b.w) 
	   return a.h < b.h;
   return a.w < b.w;
}
void dfs(int k)
{
  if(k == -1)
	  return; 
   dfs(dp[k].from);
   if(a[k].s)
   printf("%d ",a[k].s);

}
int main(){
   int n ;
   scanf("%d %d %d",&n,&a[0].w,&a[0].h);
   memset(ok,0,sizeof(ok));
   for(int i =1 ;i <= n;i ++)
   {
       scanf("%d %d",&a[i].w,&a[i].h);
	   a[i].s = i; 
   }
   sort(a+1,a+1+n,cmp);
 /*  for(int i = 1;i <= n;i ++)
   {
       printf("%d %d\n",a[i].w,a[i].h);
   }*/
   for(int i = 0 ;i <= n;i ++)
   {
      dp[i].from = i ; 
	  dp[i].len = 1; 
   }
   dp[0].from = -1;
   ok[0] = 1; 
   int asite = 0;
   int amx = 1; 
   for(int i = 1;i <= n;i ++)
   {
	  int mx = 0;
	  int site = -1 ; 
      for(int j = 0;j < i;j ++)
	  {
	    if(a[i].w > a[j].w && a[i].h > a[j].h && ok[j])
		{
		    ok[i] = 1; 
		    if(dp[j].len > mx)
			{
			   mx = dp[j].len;
			   site = j;
			}
		}
	  }
	  dp[i].len = mx +1; 
	  dp[i].from = site;    
	  if(dp[i].len > amx)
	  {
	    amx = dp[i].len ; 
		asite = i; 
	  }
	  //printf("%d\n",dp[i].len);
   }
   printf("%d\n",amx-1);
   dfs(asite);
return 0;
}
