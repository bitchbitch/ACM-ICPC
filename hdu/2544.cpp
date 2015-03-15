// File Name: 2544.cpp
// Author: darkdream
// Created Time: 2014年04月03日 星期四 22时43分06秒

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
#include<climits>


using namespace std;
/*
int dis[105][105];
int main(){
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n, m ; 
   while(scanf("%d %d",&n,&m) != EOF)
   {
      if(n == 0 && m == 0 )
		  break;
	  for(int i = 1;i <= n;i ++)
		  for(int j = 1;j <= n ;j ++)
		  {
		    if(i == j )
				dis[i][j] = 0 ; 
			else dis[i][j] = 10000000;
		  }
      while(m -- )
	  {
        int a, b, c ;
	    scanf("%d %d %d",&a,&b,&c);
		dis[a][b] = c; 
	    dis[b][a] = c; 
	  }


	  int ans[200] = {0};
	  int visit[200] = {0} ; 
	  ans[1] = 0 ; 
	  int minnum = 1; 
	  for(int i=  2;i <= n;i ++)
		  ans[i] = 10000000;
	  int p = n ;
	  while(p --)
	  {
		  int min = INT_MAX;
	      for(int i = 1;i <= n;i ++)
			  if(!visit[i] && ans[i] < min )
			  {
			     minnum = i ; 
				 min = ans[i];
			  }
		  visit[minnum] = 1; 
		  for(int i = 1;i <= n;i ++)
		  {
		     if(ans[i] > ans[minnum] + dis[minnum][i])
				 ans[i] = ans[minnum] + dis[minnum][i];
		  }
	  }
	  printf("%d\n",ans[n]);
	  
   }
return 0;
}*/
