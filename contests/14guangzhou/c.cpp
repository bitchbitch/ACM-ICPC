// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年09月20日 星期六 16时31分55秒

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
int str[110][110];
int ans = 0 ;
int xadd[] = {0,-1,1,0,0,-1,1,1,-1};
int yadd[] = {0,0,0,-1,1,-1,1,-1,1};
void dfs(int x, int y , int from ,int flag,int sum)
{
	 int tx, ty ;
	 tx = x + xadd[from];
	 ty = y + yadd[from];
	 if(str[tx][ty] = '.')
	   dfs(x,y,from,flag);
     if(flag == 0 )
	 for(int i = 1 ;i <= 7 ;i ++ )
	 {
	    if()
	 }
}
int main(){
    while(scanf("%d",&n) != EOF)
	{
	  if(n == 0 )
		  break;
	   ans = 0 ;
	  for(int i =  1;i <= n;i ++)
	  {
	    scanf("%s",&str[i][1]);
	  }
	  for(int i =1 ;i <= n;i ++)
	  {
	    for(int j = 1;j<= n;j ++)
		{
		 if(str[i][j] == '.')
		    dfs(i,j,0);
		}
	  }
	  printf("%d\n",ans);
	}
return 0;
}
