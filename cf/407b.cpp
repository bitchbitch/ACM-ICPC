// File Name: 407b.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 11时36分30秒

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
#define M 1000000007
using namespace std;
LL dp[1005];
int main(){
    int n; 
    scanf("%d",&n);
	int tmp;
	dp[1] = 2;
	scanf("%d",&tmp);
	LL sum = 1; 
	for(int i = 2;i <= n;i ++)
	{
      scanf("%d",&tmp);
	  dp[i] = 2; 
      for(int j = tmp ;j < i ;j ++)
	  {
	     dp[i] = (dp[i] +dp[j])%M;
	  }
      sum = (sum +dp[i])%M; 
	}
	printf("%I64d\n",(sum+1)%M);
return 0;
}
