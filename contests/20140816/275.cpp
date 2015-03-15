// File Name: 275.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 13时13分55秒

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

  LL n , m , k ; 
int ok = 0 ; 
void dfs(LL n , LL m )
{
	if(n == k || m == k  )
	{
	  ok = 1; 
	  return ;
	}
	if(ok)
		return ;
    if(n > k || m > k )
		return ;
    dfs(n+m,m);
	dfs(n,m+n);
}
int main(){
  while(scanf("%lld %lld %lld",&n,&m,&k)!= EOF)
  {
     ok = 0 ; 
	 if(n == 0 || m == 0 )
	 {
	     if(n == k || m == k)
		    printf("YES\n");
         else printf("NO\n");
		 break;
	 }
	 dfs(n,m);
	 if(ok)
		 printf("YES\n");
	 else printf("NO\n");
  }
     
return 0;
}
