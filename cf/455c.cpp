// File Name: 455c.cpp
// Author: darkdream
// Created Time: 2015年03月13日 星期五 15时56分13秒

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
#define maxn 310005
using namespace std;
int n , m,q;
int fa[maxn];
vector<int> mp[maxn];
int mi[maxn];
int find(int x)
{
   return fa[x] == x?x:fa[x] = find(fa[x]);
}
int tmp ; 
int dfs(int k , int la)
{
  int mx = 0 ; 
  int tt = 0 ; 
  for(int i = 0 ;i < mp[k].size() ;i ++)
  {
     if(mp[k][i] == la)
		 continue;
	 tt = dfs(mp[k][i],k);
     tmp = max(tmp,tt + mx);
	 mx = max(tt,mx);
  }
  return mx + 1; 
}
int main(){
	scanf("%d %d %d",&n,&m,&q);
	int ta , tb;
	for(int i= 1;i <= n;i ++)
	{
	   fa[i] = i ; 
	}
	int tmpa, tmpb; 
	for(int i = 1;i <= m; i ++)
	{
	    scanf("%d %d",&ta,&tb);
	    mp[ta].push_back(tb);
		mp[tb].push_back(ta);
        tmpa = find(ta);
		tmpb = find(tb);
		if(tmpa != tmpb)
		{
		   fa[tmpa] = fa[tmpb];
		}
	}
	for(int i = 1;i <= n;i ++)
	{
       if(fa[i] == i)
	   {
           tmp = 0 ; 
		   dfs(i,0);
		   mi[i] = tmp ; 
	   }
	}
	int status,l,r;
    for(int i = 1;i <= q;i ++)
	{
	      scanf("%d",&status);
		  if(status == 1)
		  {
		     scanf("%d",&l);
			 printf("%d\n",mi[find(l)]);
		  }else{
		     scanf("%d %d",&l,&r);
			 int tmpa = find(l);
			 int tmpb = find(r);
			 if(tmpa != tmpb)
			 {
			    fa[tmpa] = fa[tmpb];
			    int tta = mi[tmpa]%2 == 1?mi[tmpa]/2+1:mi[tmpa]/2;
			    int ttb = mi[tmpb]%2 == 1?mi[tmpb]/2+1:mi[tmpb]/2;
				mi[tmpb] = max(tta + ttb + 1,mi[tmpb]);
				mi[tmpb] = max(mi[tmpb],mi[tmpa]);
			 }
		  }
		  /*printf("\n");
		  for(int i = 1;i <= n;i ++)
			  printf("%d ",mi[i]);
		  printf("\n");
          */
	}
return 0;
}
