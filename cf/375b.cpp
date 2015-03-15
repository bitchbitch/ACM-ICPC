// File Name: 375b.cpp
// Author: darkdream
// Created Time: 2015年03月09日 星期一 21时05分00秒

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
#define maxn 5005
using namespace std;
int dp[maxn][maxn];
int hs[maxn];
int main(){   
	int n , m; 
	scanf("%d %d",&n,&m);
	getchar();
	for(int i = 1;i <= n;i ++)
	{
	   int sum = 0 ;
	   char tmp ; 
	   for(int j = 1;j <= m ;j++  )
	   {
           tmp = getchar();
           if(tmp == '1' )
			   sum ++ ; 
		   else sum = 0; 
		   dp[i][j] = sum ;
	   }
	   getchar();
	}
	int mx = 0 ; 
	for(int i = 1;i <= m;i ++)
	{
	  memset(hs,0,sizeof(hs));
	  for(int j= 1;j <= n;j ++)
	  {
	    hs[dp[j][i]] ++;
	  }
	  int tsum = 0 ; 
	  for(int j = 0;j<= m;j ++)
	  {
	     if(hs[j])
		 {
           mx = max((n - tsum ) * j ,mx);
		   tsum += hs[j];
		 }
	  }
	}
	printf("%d\n",mx);
    	
return 0;
}
