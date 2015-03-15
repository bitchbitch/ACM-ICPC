// File Name: 279c.cpp
// Author: darkdream
// Created Time: 2015年03月09日 星期一 08时19分05秒

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
int n ,m ; 
int a[100005];
int dp[100005];
int fa[100005];
int tmp[100005];
int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i ++)
		scanf("%d",&tmp[i]);
	int ok = 0 ;
	int t = 1 ;
	a[1] = tmp[1];
	fa[1] = 1; 
	for(int i = 2;i <= n;i ++)
	{
        if(tmp[i] == a[t])
		{
		  fa[i] = t; 
		  continue;
		}else{
		  t ++ ;
		  fa[i] = t; 
		  a[t] = tmp[i];
		}
	}
	for(int i = 2;i < t;i ++)
	{
      	if(a[i] < a[i-1] && a[i] <a[i+1])
	    {
		   dp[i] = 1 ; 
		}
	}
	for(int i = 1;i <= t;i ++)
	{
	  dp[i] = dp[i-1] +dp[i];
	  //printf("%d ",dp[i]);
	}
	//printf("\n");
    int l, r; 
	for(int i = 1;i <= m;i ++)
	{
	  scanf("%d %d",&l,&r);
	  if(dp[fa[r]-1] - dp[fa[l]] > 0 )
		  printf("No\n");
	  else printf("Yes\n");
	}
return 0;
}
