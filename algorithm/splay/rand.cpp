// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年11月07日 星期五 19时01分47秒

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
int vis[100004];
void dfs(int k )
{
  if(k == n)
	  return;
  int m = rand()%(n-k)  + 1; 
 // printf("%d*",m);
  int t = 0 ; 
  for(int i = 1;i <= n; i ++)
  {
    if(!vis[i])
	{
	   t ++ ; 
	   if(t == m)
	   {
	     printf("%d ",i);
		 vis[i] = 1;  
		 dfs(k+1);
	   break;
	   }
	}
  }
}
int main(){
    srand(time(NULL));
    freopen("in","w",stdout);	
   // for(int i = 1;i <= 10000;i ++)
    for(int i = 1;i<= 200;i ++)
	{
	   n = rand() % 100000 + 1; 
	   printf("%d\n",n);
	   memset(vis,0,sizeof(vis));
	   dfs(0);
	   printf("\n");
	}
	printf("0\n");
	return 0;
}
