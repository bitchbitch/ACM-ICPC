// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年01月10日 星期六 17时55分37秒

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
int Ga,Gb,Gc;
int a[30],b[30],c[30];
bool solve(int k)
{
   int t= 0 ; 
   int ta,tb,tc;
   ta = tb = tc = 0 ; 
   while(k)
   {
      if(k % 2)
	  {
	    ta += a[t];
		tb += b[t];
		tc += c[t];
	  }
	  k /= 2;
	  t ++ ; 
   }
  //<F5> printf("%d %d %d\n",ta,tb,tc);
   if(ta == Ga && tb == Gb&& tc == Gc)
   {
       return  1;
   }
   return 0 ; 
}
int main(){
  int T;
  scanf("%d",&T);
  for(int ca = 1;ca <= T; ca ++)
  {
      scanf("%d %d %d",&Ga,&Gb,&Gc);
	  int n;
	  scanf("%d",&n);
	  for(int i= 0;i < n;i++)
	  {
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	  }
	  int total = (1 << n)-1;
	  int ok = 0 ; 
	  for(int i =0 ;i <= total;i ++)
	  {
	     if(solve(i))
		 {
		   ok = 1; 
		   break;
		 }
	  }
	  if(ok)
	    printf("Case #%d: yes\n",ca);
	  else printf("Case #%d: no\n",ca);
  }
return 0;
}
