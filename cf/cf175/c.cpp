// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年11月01日 星期六 10时12分29秒

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
  LL  k ; 
  LL v;
}a[200];
bool cmp(node x, node y)
{
  return x.v < y.v;
}
LL b[100];
int main(){
   LL n ; 
   scanf("%lld",&n);
   for(int i = 1;i <= n;i ++)
   {
     scanf("%lld %lld",&a[i].k,&a[i].v);;
   }
   sort(a+1,a+1+n,cmp);
   LL t; 
   scanf("%lld",&t);
   for(int i = 1;i <= t;i ++)
   {
     scanf("%lld",&b[i]);
   }
   LL sum = 0 ;
   LL num = 0 ;
   LL k = 1; 
   for(int i = 1;i <= t;i ++)
   {
      while(num + a[k].k <= b[i])
	  {
	      num += a[k].k;
		  sum += a[k].k * i * a[k].v;
		  k ++ ; 
		  if(k > n)
			  break;
	  }
	  if(k > n )
		  break;
	  LL tt = b[i] - num;
	  num += tt;
	  sum += tt * i * a[k].v ; 
      a[k].k -= tt;
   }
   for(;k <= n;k ++)
   {
     sum += a[k].k * (t+1) * a[k].v;
   }
   printf("%lld\n",sum);
return 0;
}
