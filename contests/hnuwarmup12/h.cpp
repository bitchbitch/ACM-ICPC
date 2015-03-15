// File Name: h.cpp
// Author: darkdream
// Created Time: 2015年03月14日 星期六 12时28分16秒

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
int a[300][3];
int dp[300][300][3];
void update(int i , int j , int k ,int val,int plus)
{
   if(val == -1)
	   return;
   if(dp[i][j][k] == -1)
	   dp[i][j][k] = val+plus ; 
   else dp[i][j][k] = min(dp[i][j][k],val+ plus); 
}
int main(){
   int n , m ; 
   while(scanf("%d %d",&n,&m) != EOF)
   {
	   if(n == 0 && m == 0 )
		   break;
	   int sum = 0;
       for(int i = 1;i <= n;i ++)
	   {
	     scanf("%d %d",&a[i][0],&a[i][1]);
	     sum  += a[i][0]+a[i][1];
	   }
	   int ans = 1e9;
	   if(m == 0 )
	   {
	     printf("%d\n",sum);
		 continue;
	   }
	   memset(dp,-1,sizeof(dp));
	   dp[0][0][0] = 0 ;
	   dp[0][0][1] = 0 ; 
	   for(int i= 1;i <= n;i ++)
	   {
	      for(int j = 1;j <= m;j++)
		  {
		      update(i,j,0,dp[i-1][j-1][0],a[i][0]);
              update(i,j,1,dp[i-1][j-1][1],a[i][1]);
			  
			  for(int s = 0 ;s < i-1 ;s ++ )
			  {
		        update(i,j,0,dp[s][j-1][0],a[i][0]);
		        update(i,j,0,dp[s][j-1][1],a[i][0]);
		        update(i,j,1,dp[s][j-1][0],a[i][1]);
		        update(i,j,1,dp[s][j-1][1],a[i][1]);
			  }
		  }
		  /*for(int j = 0 ;j <= m;j ++)
		  {
		     printf("%d %d\n",dp[i][j][0],dp[i][j][1]);
		  }
		  printf("***\n");*/
		  if(dp[i][m][0] != -1)
			  ans = min(ans,dp[i][m][0]);
		  if(dp[i][m][1] != -1)
			  ans = min(ans,dp[i][m][1]);
	   }
	   printf("%d\n",sum-ans);
   }
return 0;
}
