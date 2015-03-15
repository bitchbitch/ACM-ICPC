// File Name: littlekenbg.cpp
// Author: darkdream
// Created Time: 2013年11月29日 星期五 19时40分07秒

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

using namespace std;

int dp[10000];
int main(){
  int m,n;
  
  while(scanf("%d %d",&m,&n) != EOF)
  {
	memset(dp,0,sizeof(dp));
	dp[0] = 1;

    for(int i = 1; i <= n;i ++)
	{
	  int temp ;
	  scanf("%d",&temp);
	  for(int j = m;j >= 0;j --)
	  {
	    if(dp[j] != 0 && j + temp <= m)
		{
		   dp[j+temp] = 1;
		}
	  }
	}
	for(int i = m ;i >= 0;i --)
	{
	  if(dp[i] != 0)
	  {	 
		  printf("%d\n",i);
		  break;
	  }
	}
  }
return 0;
}
