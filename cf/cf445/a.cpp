// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年07月06日 星期日 21时08分40秒

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
#include<queue>

using namespace std;

int a[200][200];
int visit[200][200];

int main(){
   int n ,m ; 
   scanf("%d %d",&n,&m);
   memset(visit,0,sizeof(visit));
   memset(a,0,sizeof(a));
   for(int i = 1;i<= n;i ++)
   {
      char str[390];
	  scanf("%s",&str[1]);
	  for(int j =1 ;j <= m ;j ++)
	     if(str[j] == '.')
			 visit[i][j] = 1; 
   }
   for(int i = 1;i <= n;i ++)
   {
	 if(i % 2 == 0 )
	  for(int j = 1;j <= m;j ++)
	  {
		if(visit[i][j])
		{
	       if(visit[i][j] && j % 2== 0 )
               a[i][j] = 1; 
		   else a[i][j] = 2; 
		}
	  } 
	 else 
	 for(int j = 1;j <= m;j ++)
	  {
		if(visit[i][j])
		{
	       if(visit[i][j] && j % 2== 0 )
               a[i][j] = 2; 
		   else a[i][j] = 1; 
		}
	  }
   
   }
   for(int i =1 ;i <= n;i ++)
   {
       for(int j =1 ;j <= m;j ++)
	   {
	      if(a[i][j] == 1 )
			  printf("B");
		  else if(a[i][j] == 2)
			  printf("W");
		  else printf("-");
	   }
	   printf("\n");
   }
return 0;
}
