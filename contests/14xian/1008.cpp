// File Name: 1008.cpp
// Author: darkdream
// Created Time: 2014年09月14日 星期日 13时48分08秒

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
int a[100005];
int hs[100005];
int solve(int x)
{
	int t = 1 ;
	int k = 0 ; 
    while(x >= t)
	{
	  k ++ ; 
	  t = t * 2;
	}
	//printf("%d %d\n",k,(1<<k)-1);
    return x ^((1 << k) - 1);
}
int main(){
    int n; 
    while(scanf("%d",&n) != EOF)
	{
	  memset(hs,-1,sizeof(hs));
	  for(int i = 1;i <= n+1;i ++)
		  scanf("%d",&a[i]);
	  LL ans = 0 ;
	  for(int i = n ;i >= 0;i --)
	  {
	      if(hs[i] != -1)
			  continue;
		  int temp  = solve(i);
		        hs[temp] = i; 
		  hs[i] = temp ; 
		  ans += (temp^i)*2;
	  }
	  printf("%I64d\n",ans);
	  for(int i = 1;i <= n+1;i ++)
		  printf(i == 1?"%d":" %d",hs[a[i]] );
	  printf("\n");
	}
	return 0;
}
