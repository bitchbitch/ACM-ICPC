// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年10月18日 星期六 09时26分57秒

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
int n ; 
int mp[104][104];
int xadd[] ={0,0,1,-1};
int yadd[] ={-1,1,0,0};
int ok(int x, int y)
{
   if( x <= n && y >= 1 && x >= 1 && y <= n)
	   return 1;
   return 0 ;
}
void dfs(int x, int y,int od,int st)
{
	mp[x][y] = st;
	int isok = 0 ; 
    for(int i = 0 ;i <= 3;i ++)
	{
         int tx = x + xadd[i];
		 int ty = y + yadd[i];
		 if(ok(tx,ty)&& !mp[tx][ty] && i != od)
		 {
			isok = 1; 
	        dfs(tx,ty,i,st+1);
			continue;
		 }
	}
	if(isok == 0 )
	{
         int tx = x + xadd[od];
		 int ty = y + yadd[od];
		 if(ok(tx,ty)&& !mp[tx][ty])
		 {
			isok = 1; 
	        dfs(tx,ty,od,st+1);
		 }
	}
}
void solve()
{
   memset(mp,0,sizeof(mp));
   if(n% 2 == 0 )
   {
       dfs(1,2,3,1); 
   }else 
   {
       dfs(1,1,3,1); 
   }
}
int main(){
   int t; 
   scanf("%d",&t);
   while(t--)
   {
    scanf("%d",&n);
	solve();
	for(int i =1 ;i <= n;i ++)
	{
	   for(int j = 1;j <= n;j ++)
	   {
	        printf(j == 1?"%d":" %d",mp[i][j]);
	   }
	   printf("\n");
	}
   }
return 0;
}
