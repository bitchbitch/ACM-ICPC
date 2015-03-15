/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-08-02 14:28
 * Filename : 431c.cpp
 * Description :
 * *********************************************************/
// File Name: 431c.cpp
// Author: darkdream
// Created Time: 2014年08月01日 星期五 20时22分33秒

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
LL dp[104][104]; 
LL dpa[104][104];
#define md 1000000007
int main(){
    int n , k , d; 
	scanf("%d %d %d",&n,&k,&d);
	memset(dp,0,sizeof(dp));
	memset(dpa,0,sizeof(dpa));
	dp[0][0] = 1; 
	LL ans = 0 ;
	for(int i = 1;i <= n;i ++)
	{
	    for(int j = i-1;j <= n;j ++)
		{
	       if(dp[i-1][j]) 
		   {
              for(int s = 1;s <= k ; s ++)
			  {
				 if(j + s > n)
					 break;
			     if(s <  d )
					 dp[i][j+s] = (dp[i][j+s] + dp[i-1][j]) % md;
				 else 
					 dpa[i][j+s] = (dpa[i][j+s] + dp[i-1][j]) % md;
			  }
		   }
		   if(dpa[i-1][j])
		   {
		      for(int s = 1; s <= k; s++)
			  {
			     if(j + s > n)
					 break;
				 dpa[i][j+s] = (dpa[i-1][j]+ dpa[i][j+s]) %md;
			  }
		   }
		}
	}
	for(int i = 1;i <= n;i ++)
		ans =( dpa[i][n]+ ans)%md;
	printf("%I64d\n",ans%md);
return 0;
}
