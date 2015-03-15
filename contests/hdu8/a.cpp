// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月14日 星期四 11时59分18秒

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
int n; 
const int maxn = 100005;
int hs[3000];
int dp[]
void init()
{
  memset(hs,0,sizeof(hs));
  int t = 1;
  hs[t] = 1; 
  for(int i = 1;i <= 11;i ++)
  {
      t  =t * 2; 
	  hs[t] = i ;
  }
}
int main(){
	init();
	int ca = 0 ;
    while(scanf("%d",&n) != EOF,n)
	{
	  ca ++ ; 
	  LL sum = 0 ;
	  for(int i = 1;i <= n;i ++)
	  {
	     int t ; 
		 scanf("%d",&t);
		 if(hs[t])
		 {
		    
		 }else{
		   
		 }
		 sum += dp[i][11];
	  }
	}
return 0;
}
