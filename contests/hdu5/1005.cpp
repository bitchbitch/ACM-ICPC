// File Name: 1005.cpp
// Author: darkdream
// Created Time: 2014年08月05日 星期二 12时44分19秒

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
char str[1000006];
/*struct node{
  int num ;
  int is = 0
  }dp[1000006];*/
int dp[1005][1004];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%s",&str[1]) != EOF)
	{
		int len = strlen(&str[1]);
        memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i = 1 ;i <= len;i ++)
		{
			for(int j = 0;j <= len ;j ++)
			{
				if(dp[i-1][j]){
					if(str[i] == '?')
					{
						if(j != 0 )
							dp[i][j-1] += dp[i-1][j];
						dp[i][j+1] += dp[i-1][j];
					}else if(str[i] == '('){
						dp[i][j+1] += dp[i-1][j];
					}else{
						if(j != 0)
							dp[i][j-1] += dp[i-1][j];
					}
				}
			}
		}

	/*	for(int i =0;i <= len ;i ++)
		{
			for(int j = 0 ;j <= len ;j ++)
				printf("%d ",dp[i][j]);
			printf("\n");
		}*/
		if(dp[len][0] == 0 )
			printf("None\n");
		else if(dp[len][0] == 1)printf("Unique\n");
		else printf("Many\n");
	}
	return 0;
}
