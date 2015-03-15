// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年11月11日 星期二 13时03分38秒

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
#define maxn 100004
using namespace std;
struct node{
  LL a,  b;
}num[maxn];
LL Mi[maxn];
LL n , m;
LL fen(LL x )
{
  LL l = 1, r = n;
  while(l <= r )
  {
    LL m = (l + r) >>1 ;
	if(num[m].a >  x)
	{
	   r = m- 1; 
	}else {
	   l = m + 1; 
	}
  }
  return r; 
}
LL M(LL a, LL b)
{
   if(a > b)
	   return b ; 
   else return a; 
}
int main(){
   LL t; 
   scanf("%I64d",&t);
   while(t--)
   {
	   scanf("%I64d %I64d",&n,&m);
      for(LL i = 1;i <= n;i ++)
	  {
	     scanf("%I64d %I64d",&num[i].a ,&num[i].b);
	  }
	  Mi[n] = num[n].a * num[n].b; 
	  for(LL i = n-1;i >= 1; i -- )
	  {
	     Mi[i] = M(num[i].a * num[i].b,Mi[i+1]);
	  }
      for(LL i = 1;i <= m;i ++)
	  {
	      LL q; 
		  scanf("%I64d",&q);
		  LL t = fen(q);
		  //printf("%I64d\n",t);
		  if(t == n)
			  printf("%I64d\n",1ll * num[t].b * q);
		  else 
		      printf("%I64d\n",M(1ll*num[t].b * q , Mi[t+1]));
	  }
   }
return 0;
}
