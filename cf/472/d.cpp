// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年09月29日 星期一 00时45分45秒

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
#define maxn 2010
using namespace std;
int n ; 
int mi[maxn];
vector <int> mp[2010];
int nmp[maxn][maxn];
int pre[maxn];
bool vis[maxn];

long long  dep[maxn];
void dfs(int la,int zla,int dis)
{
   dep[la] = dis;   
   int len = mp[la].size();
   for(int i = 0 ;i < len ;i ++)
   {
	   int ne = mp[la][i];
       if(ne != zla)
	   {
		  dfs(ne,la,dis + nmp[la][ne]);
	   }
   }
}
void prime()
{
    for(int i = 1;i <= n;i ++){
       dep[i] = 2e9;
	   vis[i] = 0 ; 
	}		
	dep[1] = 0 ; 
	while(1)
	{
	   int v = -1;
	   for(int i = 1;i <= n;i ++)
	   {
	      if(!vis[i] && (v == -1 || dep[i] < dep[v]))
			  v = i ;  
	   }
	   if(v == -1)
		   break;
	   vis[v] = 1;
	   for(int i = 1;i <= n;i ++)
	   {
	       if(!vis[i] && nmp[v][i] < dep[i]) 
		   {
		      dep[i] = nmp[pre[i] = v][i];
		   }
	   }
	}
}
int main(){
	 scanf("%d",&n);
	 int sum = 0 ; 
	 int ok  = 0 ;
	 for(int i = 1;i <= n;i ++)
	 { 
		for(int j = 1;j <= n;j ++)
	    {
	        scanf("%d",&nmp[i][j]);
		}
	 }
	 for(int i = 1;i <= n;i ++)
	 {
	    for(int j = 1;j <= n;j ++)
		{
		   if(i!= j && nmp[i][j] == 0 )
			   ok = 1;
		   if(nmp[i][j] != nmp[j][i])
			   ok = 1;
		}
	 }
	 if(ok)
	 {
	   puts("NO");
	   return 0 ; 
	 }
	 prime();
	 for(int i = 2;i <= n;i ++)
	 {
	   mp[i].push_back(pre[i]);
	   mp[pre[i]].push_back(i);
	   //printf("%d %d\n",i,pre[i]);
	 }
	 for(int i = 1;i <= n;i ++)
	 {
	    dfs(i,0,0);
	/*	for(int j = 1;j <= n;j ++)
			printf("%lld ",dep[j]);
		printf("\n");*/
	    for(int j = 1; j <= n;j ++)
		{
		   if(dep[j] != nmp[i][j])
		   {
			  
		      puts("NO");
			  return 0;
		   }
		}
	 }
	 puts("YES");
return 0;
}
