// File Name: 269b.cpp
// Author: darkdream
// Created Time: 2015年03月09日 星期一 18时44分02秒

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
int a[10000];
int ans[10000];
int n , m; 
int Find(int l , int r,  int x )
{
    while(l <= r )
	{
	  int m = (l + r)/2;
	  if(ans[m] <= x )
	  {
	     l = m + 1;  
	  }else {
	     r = m - 1; 
	  }
	}
    return l; 
}
int solve()
{
	int t = 1; 
	ans[1] = a[1];
   for(int i = 2;i <= n;i ++)
   {
       if(a[i] >= ans[t])
	   {
	      t ++ ; 
		  ans[t] = a[i];
	   }else{
		  //printf("%d %d\n",i,Find(1,t,a[i]));
	      ans[Find(1,t,a[i])] = a[i];
	   }
	   /*for(int i = 1;i <= t;i ++)
		   printf("%d ",ans[i]);
	   printf("\n");*/
   }
   return n - t; 
}
int main(){
  scanf("%d %d",&n,&m);
  double tmp ; 
  for(int i = 1;i <= n;i ++)
  {
    scanf("%d %lf",&a[i],&tmp);
  }
  printf("%d\n",solve());
return 0;
}
