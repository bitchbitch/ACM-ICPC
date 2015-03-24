// File Name: f.cpp
// Author: darkdream
// Created Time: 2015年03月15日 星期日 12时19分58秒

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
LL a, b ;
LL  p(int n)
{
  LL sum = 1; 
  for(int i=  1;i <= n;i ++)
	  sum *=2 ;
  return sum; 
}
int solve(LL t, LL now)
{
	//printf("%lld %lld\n",t,now);
    if(t == now)
		return 0; 
	return 1 + solve(t/2,abs(now-t/2));
}
int main(){
   int  t ;
   scanf("%d",&t);
   while(t--)
   {
	   int n ;
	   scanf("%d %I64d %I64d",&n,&a,&b);
	   printf("%d\n",solve(p(n),a)-1); 
   }
return 0;
}
