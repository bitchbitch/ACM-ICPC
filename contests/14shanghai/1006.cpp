// File Name: 1006.cpp
// Author: darkdream
// Created Time: 2014年09月27日 星期六 13时43分37秒

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
#define M 1000000000
using namespace std;

struct big
{
  LL a[7];
  void clear()
  {
     memset(a,0,sizeof(a));
  }
  void amu(const LL &b)
  {
      LL zs,last;
	  last = 0; 
	  for(int i = 0;i < 6; i ++)
	  {
	    zs = (a[i]*b + last);
		last = zs/M;
		zs = zs % M;
		a[i] = zs;
	  }
   }
  void add()
  {
	LL last = 1 ; 
    for(int i = 0 ;i < 6;i ++)
	{
       last = (a[i]+last);
	   a[i] = last % M; 
	   last =  last /M;
	}
  }
  void change(LL b)
  {
	int k = -1;
	while(b)
	{
	   k ++ ; 
	   a[k] = b % M;
	   b = b/M;
	}
  }
  void sub(const big &b)
  {
      LL zs,last;
	  last = 0; 
	  for(int i = 0;i < 6; i ++)
	  {
	    last = a[i] - b.a[i] - last;
		if(last < 0)
		{
		   a[i] = last + M ;
		   last = -1;
		}else{
		   a[i] = last;
		   last = 0 ; 
		}
	  }
   }
  void print()
  {
	 int i; 
     for( i = 6;i >= 0 ;i ++)
	 {
	     if(a[i] != 0 )
			 break;
	 }
	 for(int j = i ;j >= 0; j ++)
	 {
	      printf(j != i?"%d":"%06d",a[i])' 
	 }
	 printf()
  }
};
int main(){
   int t ;
   scanf("%d",&t);
   ll n ; 
   for(int ca = 1; ca <= t;ca ++)
   {
      scanf("%lld",&n);
	  big x,y;
	  x.change(n);
	  y.change(n);
	  x.amu(n);
	  x.amu
   }
return 0;
}
