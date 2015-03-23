// File Name: 132c.cpp
// Author: darkdream
// Created Time: 2015年03月22日 星期日 19时43分45秒

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
char str[1000];
int k;
int dp[105][105][2][2];
void update(int &x ,int v,int status)
{
	if(status == 1)
	{
      x = max(x,v);	
	  return; 
	}
	x = min(x,v);
}
int main()
{
    scanf("%s",&str[1]);
    scanf("%d",&k);
    int len = strlen(&str[1]);
    for(int i = 0 ;i <= len; i ++)
        for(int j = 0 ;j <= k ;j ++)
		{ dp[i][j][1][0] = 1e9;
		  dp[i][j][1][1] = -1e9;
		  dp[i][j][0][0] = 1e9;
		  dp[i][j][0][1] = -1e9;
		}
    dp[0][0][1][0] = 0 ;
	dp[0][0][1][1] = 0 ;  
    for(int i = 1 ; i <= len ; i ++)
    {
	    int st = 0;
		if(str[i] == 'F')
		{
		    for(int j =0 ;j <= k;j ++)
			{
			    update(dp[i][j][1][0],dp[i-1][j][1][0] +1,0) ;
			    update(dp[i][j][1][1],dp[i-1][j][1][1] +1,1) ;
			    update(dp[i][j][0][0],dp[i-1][j][0][0] -1,0) ;
			    update(dp[i][j][0][1],dp[i-1][j][0][1] -1,1) ;
				update(dp[i][j+1][1][0],dp[i-1][j][0][0],0);
				update(dp[i][j+1][1][1],dp[i-1][j][0][1],1);
				update(dp[i][j+1][0][0],dp[i-1][j][1][0],0);
				update(dp[i][j+1][0][1],dp[i-1][j][1][1],1);
			}
		}else{
		    for(int j =0 ;j <= k;j ++)
			{
			    update(dp[i][j+1][1][0],dp[i-1][j][1][0] +1,0) ;
			    update(dp[i][j+1][1][1],dp[i-1][j][1][1] +1,1) ;
			    update(dp[i][j+1][0][0],dp[i-1][j][0][0] -1,0) ;
			    update(dp[i][j+1][0][1],dp[i-1][j][0][1] -1,1) ;
				update(dp[i][j][1][0],dp[i-1][j][0][0],0);
				update(dp[i][j][1][1],dp[i-1][j][0][1],1);
				update(dp[i][j][0][0],dp[i-1][j][1][0],0);
				update(dp[i][j][0][1],dp[i-1][j][1][1],1);
			}
		}
		for(int j = 2;j <= k;j ++)
		{
				update(dp[i][j][1][0],dp[i][j-2][1][0],0);
				update(dp[i][j][1][1],dp[i][j-2][1][1],1);
				update(dp[i][j][0][0],dp[i][j-2][0][0],0);
				update(dp[i][j][0][1],dp[i][j-2][0][1],1);
		}
        /*for(int j = 0 ;j <= k;j ++)
            printf("%d ",dp[i][j][0]);
        printf("\n");
        for(int j = 0 ;j <= k;j ++)
            printf("%d ",dp[i][j][1]);
        printf("\n");
        printf("************\n");*/
    }
    int ans = 0;
	if(abs(dp[len][k][1][0]) <= 100 && abs(dp[len][k][1][0]) > ans)
	{
	   ans = abs(dp[len][k][1][0]);
	}
	if(abs(dp[len][k][1][1]) <= 100 && abs(dp[len][k][1][1]) > ans)
	{
	   ans = abs(dp[len][k][1][1]);
	}
	if(abs(dp[len][k][0][0]) <= 100 && abs(dp[len][k][0][0]) > ans)
	{
	   ans = abs(dp[len][k][0][0]);
	}
	if(abs(dp[len][k][0][1]) <= 100 && abs(dp[len][k][0][1]) > ans)
	{
	   ans = abs(dp[len][k][0][1]);
	}
	printf("%d\n",ans);
	//printf("%d %d %d %d\n",dp[len][k][1][0],dp[len][k][1][1],dp[len][k][0][0],dp[len][k][0][1]);

return 0;
}
