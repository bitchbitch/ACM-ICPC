// File Name: 316b2.cpp
// Author: darkdream
// Created Time: 2015年03月22日 星期日 14时58分34秒

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
#define maxn 1005
using namespace std;
int fa[maxn];
int site ; 
int color;
int find(int x)
{
   fa[x] == x?x:fa[x] = find(fa[x]);
}
void dfs(int x ,int dis)
{
   if(fa[x] == x)
   {
       color = x; 
	   site = dis; 
       return;
   }
   dfs(fa[x],dis + 1);
}
int tt ;
int hs[10005];
int a[1005];
int dp[1050][1050];
int main(){
   int n , x;
   scanf("%d %d",&n,&x);
   for(int i = 1;i <= n;i ++)
   {
     scanf("%d",&fa[i]);
	 if(fa[i] == 0)
		 fa[i] = i; 
   }
   dfs(x,1);
   for(int i = 1 ;i <= n;i ++)
   {
        find(i); 
   }
   for(int i = 1;i <= n;i ++)
   { 
	 if(fa[i] != color)
      hs[fa[i]] ++;
   }
   tt = 0 ; 
   for(int i = 1;i <= n;i ++)
   {
      if(hs[i] != 0 )
	  {
	     tt ++ ; 
		 a[tt] = hs[i];
	  }
   }
   memset(dp,0,sizeof(dp));
   dp[0][0] = 1; 
   for(int i = 1;i <= tt;i ++)
   {
      for(int j =0 ;j <= n;j ++)
	  {
	     if(dp[i-1][j] == 1 )
		 {
		    dp[i][j] = 1; 
			dp[i][j+a[i]] = 1; 
		 }
	  }
   }
   for(int i = 0 ;i <= n;i ++)
   {
      if(dp[tt][i]  == 1)
		  printf("%d\n",i+site);
   }
   
return 0;
}
