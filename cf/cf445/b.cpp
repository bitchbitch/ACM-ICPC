/************************************************************
 * Author        : darkdream
 * Email         : darkdream1994@gmail.com 
 * Last modified : 2014-07-06 22:54
 * Filename      : b.cpp
 * Description   :
 * *********************************************************/
// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年07月06日 星期日 21时24分56秒

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
#include<climits>
#include<queue>

using namespace std;
int f[100];
int hs[100];
int find(int x)
{
  return x==f[x]?x:find(f[x]);
}
int main()
{
   memset(hs,0,sizeof(hs));
   for(int i = 1;i <= 100 ;i ++)
	   f[i] = i ;
   int n , m ; 
   scanf("%d %d",&n,&m);
   for(int i = 1;i <= m;i ++)
   {
     int a, b;
	 scanf("%d %d",&a,&b);
	 int ta = find(a);
	 int tb = find(b);
     if(ta != tb)
	 {
	     f[tb] = ta;
	 }
   }
   for(int i = 1;i <= n;i ++)
   {
      hs[find(i)] ++ ; 
   }
   int sum  = 0 ;
   for(int i = 1;i <= n;i ++)
	   if(hs[i] >= 2)
		   sum += hs[i] -1;
   long long  ans = 1; 
   for(int i =1 ;i <= sum;i ++)
   {
      ans *=2 ;
   }
   printf("%lld\n",ans);
   return 0 ; 
}
