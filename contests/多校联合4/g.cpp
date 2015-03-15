// File Name: g.cpp
// Author: darkdream
// Created Time: 2013年04月27日 星期六 19时53分59秒

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
#include<limits.h>

using namespace std;
int n, m , MAX = 0;

int a[10000][202];
int b[10000][202];
int visit[10001];
void dfs(int x,int k)
{
    if(x == m)
	{
	   if(k > MAX)
		   MAX = k;
	   return ;
	}
	for(int j = 1  ;j <= a[x][201]; j++)
	{
	   if(!visit[a[x][j]])
	   {
		  visit[a[x][j]] = 1;
		  if(b[x][j] < k)
		    dfs(a[x][j],b[x][j]); 
		  else
			dfs(a[x][j],k);
	     visit[a[x][j]] = 0;    
	   }
	}
	return;

}
int main(){
	while(scanf("%d %d",&n,&m) != EOF)
	{
	  int t;
	  MAX = 0;
	  memset(visit,0,sizeof(visit));
       memset(a,0,sizeof(a));
	  scanf("%d",&t);
	  int x, y , dis;
	  while(t--)
	  {
		scanf("%d %d %d",&x,&y,&dis);
		a[x][++a[x][201]] = y;
		b[x][a[x][201]] = dis;
      }
	  visit[n] = 1;
	  dfs(n,INT_MAX);
     printf("%d\n",MAX);
	}

return 0;
}
