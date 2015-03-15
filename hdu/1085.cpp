// File Name: 1085.cpp
// Author: darkdream
// Created Time: 2014年07月12日 星期六 18时00分23秒

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

int dp[4][15001000];
int main(){
    int a[4]; 
	while(scanf("%d %d %d",&a[1],&a[2],&a[3]) != EOF)
	{
	  memset(dp,0,sizeof(dp));
		if(!a[1] && !a[2] && !a[3])
		  break;
	  for(int i =1;i <= 3 ;i ++)
	  {
	    while(a[i] != 0 )
		{
		  for()
		}
	  }
	}
return 0;
}
