// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年09月07日 星期日 13时56分37秒

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
#define maxn 100005
using namespace std;

int n , m , kn ,ln; 
vector<int> mp[maxn];
int visit[maxn];
int k[maxn];
int l[maxn];
int hs[maxn];
int ok ;
int site;
int sum ;
void dfs(int s )
{
  int num = mp[s].size();
  for(int i = 0;i < num;i ++)
  {
     if(!visit[mp[s][i]]) 
	 {
	     if(!k[mp[s][i]]){
			visit[mp[s][i]] = 1; 
			sum ++ ;
		    dfs(mp[s][i]);
		 }
		 else{
		   if(l[mp[s][i]] == site + 1 )
		   {
		     visit[mp[s][i]] = 1; 
			 site ++ ;
			 sum ++ ;
			 dfs(mp[s][i]);
		   }else if(l[mp[s][i]]){
		     hs[l[mp[s][i]]] = mp[s][i];    
		 }
		 }
	 }
  }
  if(site == ln)
  {
     ok = 1;
	 return ;
  }else{
    if(hs[site + 1])
	{
	  visit[hs[site+1]] = 1;
	  site ++ ;
	  sum ++ ; 
	  dfs(hs[site]);
	}
  }
}
int main(){
    int t; 
	scanf("%d",&t);
	while(t--)
	{
       scanf("%d %d %d",&n,&m,&kn);
       int a, b ; 
	   for(int i = 1;i <= n;i ++)
		   mp[i].clear();
	   memset(hs,0,sizeof(hs));
	   memset(k,0,sizeof(k));
	   memset(l,0,sizeof(l));
	   memset(visit,0,sizeof(visit));
	   int temp ; 
	   for(int i = 1;i <= kn ;i ++ )
	   {
	       scanf("%d",&temp);
		   k[temp] = 1 ; 
	   }
	   for(int i =	1 ;i <= m;i ++)
	   {
           scanf("%d %d",&a,&b);
	       mp[a].push_back(b); 
	       mp[b].push_back(a);
	   }
	   int be;
	   scanf("%d",&ln);
	   for(int i = 1;i <= ln ;i ++)
	   {
	      scanf("%d",&temp);
		  if(i == 1 )
			  be = temp; 
		  l[temp] = i;
	   }
	   if(ln < kn)
	   {
	      printf("No\n");
		  continue;
	   }
	   ok  = 0 ; 
	   site = 1; 
	   sum =  1 ; 
	   visit[be] = 1;
	   dfs(be); 
	   
	   if(ok && sum == n)
		   printf("Yes\n");
	   else printf("No\n");
	}
return 0;
}
