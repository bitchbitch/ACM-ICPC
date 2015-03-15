// File Name: 118d.cpp
// Author: darkdream
// Created Time: 2014年07月25日 星期五 15时35分03秒

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
const int  M = 100000000;
using namespace std;
int dp[204][200][3][20];
int main(){
    int n1,n2,k1,k2;
    scanf("%d %d %d %d",&n1,&n2,&k1,&k2);
	memset(dp,0,sizeof(dp));
	dp[1][1][0][1] = 1;
	dp[1][0][1][1] = 1;
	
	for(int i = 2;i <= n1+n2;i ++){
	    for(int j = 0 ;j <= n1;j ++){
		   for (int s = 0;s <= 1; s ++){
			     if((s && j == n1+1) ||(!s && i-j == n2+1))
					 continue;
			     for(int k = 1;k <= (s?k2:k1);k ++){
                       if(k == 1){
					     for(int t = 1;t <= 10 ; t++)
						 {
						    dp[i][j][s][1] = (dp[i][j][s][1] + dp[i-1][(s?j:j-1)][!s][t] )%M;
						 }
					   }else{
					        dp[i][j][s][k] = dp[i-1][(s?j:j-1)][s][k-1];
					   }
			//		   printf("%d %d %d %d %d\n",i,j,s,k,dp[i][j][s][k]);
				  }
		   }
		}
	}
	LL sum = 0 ;
	
	for(int s = 0;s <= 1;s ++)
	{
	    for(int i = 1;i <= 10 ;i ++)
		{
	      sum = (sum +dp[n1+n2][n1][s][i])%M; 	
		}
	}
	printf("%I64d\n",sum);
return 0;
}
