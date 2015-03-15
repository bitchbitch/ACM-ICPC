// File Name: 191a.cpp
// Author: darkdream
// Created Time: 2015年03月10日 星期二 18时44分56秒

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
#define maxn 500005
using namespace std;
char str[20];
char str1[20];
int dp[30][30];
int main(){
    int n; 
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i++)
	{
	  scanf("%s",str1);
	  int be = str1[0] - 'a';
	  int en = str1[strlen(str1)-1] - 'a' ;
	  //printf("%d\n",strlen(str1));
	  for(int i = 0 ;i < 26 ;i ++)
		if(dp[i][be] != 0 )
		  dp[i][en] = max(dp[i][be]+ int(strlen(str1)),dp[i][en]);
	  dp[be][en] = max(dp[be][en],int(strlen(str1)));
	}
	int mx = 0 ; 
	for(int i = 0;i < 26;i ++)
		mx = max(dp[i][i],mx);
	printf("%d\n",mx);
return 0;
}
