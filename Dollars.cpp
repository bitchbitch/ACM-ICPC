// File Name: Dollars.cpp
// Author: darkdream
// Created Time: 2013年11月29日 星期五 21时01分38秒

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
int a[14] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
int dp[200000];
int main(){
	int ta,tb;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d.%d",&ta,&tb) != EOF)
	{
		int m = ta*100 + tb;
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i= 0 ; i <= 10;i ++)
		{
			for(int j = 0;j <= m;j ++)
				if(dp[j] && j + a[i] <= m)
					dp[j+a[i]] += dp[j];
                               
		}
		//for(int i =0 ;i<= m;i ++)
		//	printf("%d ",dp[i]);
		printf("%2d.%02d%12d\n",ta,tb,dp[m]);
	}
	return 0;
}
