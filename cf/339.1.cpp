// File Name: 339.1.cpp
// Author: darkdream
// Created Time: 2014年08月03日 星期日 17时13分53秒

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
int dp[1004][14][14];
int lb = 0 ;;
int b[100];
int m ;
void dfs(int i, int j ,int k )
{
    if(i == 0 )
		return; 
	dfs(i-1,k-j,dp[i][j][k]);
	printf("%d ",k);
}
int main(){
    char str[14];
	scanf("%s",str);
	scanf("%d",&m);
	int len = strlen(str);
	for(int i = 0 ;i < len;i++)
	{
	   if(str[i] == '1')
	   {
	      lb ++ ; 
		  b[lb] = i + 1; 
	   }
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0][0] = 0;
	for(int i =1;i<= m;i ++)
	{
	   for(int j = 0;j <= 10;j ++)
	     for(int k = 0 ;k <= 10 ;k ++)
		 {
		    if(dp[i-1][j][k] != -1 )
			{
			 //printf("%d %d %d\n",i,j,k);
			     for(int s = 1;s <= lb ;s ++ )
				 {
				   if(b[s] > j && b[s] != k)
				   {
					   dp[i][b[s]-j][b[s]] = k ;
			           //printf("***%d %d %d\n",i,b[s]-j,b[s]);
				   }
				 }
			}
		 }
	}
	for(int i = 1 ;i <= 10;i ++)
	{
		for(int j = 1;j <= 10;j ++)
		{
		   if(dp[m][i][j] != -1 )
		   {
		     printf("YES\n");
			 dfs(m,i,j);
			 return 0;
		   }
		}
	}
     printf("NO\n") ;
return 0;
}
