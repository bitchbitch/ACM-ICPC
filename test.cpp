// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月06日 星期一 20时13分24秒

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
int dp[2][1000005];
int n , m; 
void solve(int k ,int f)
{
   dp[f][0] = 1; 
   for(int i = 1; i <= k ;i ++)
   {
       dp[f][i] = (dp[!f][i] + dp[!f][i-1])%M;
   }
   if(k % 10000 == 0 )
     printf("%d\n",k);
}
int main(){
    freopen("output","w",stdout);
    dp[0][0] = 1; 
	scanf("%d %d",&n,&m);
    for(int i = 1; i <= n;i ++)
	{
      solve(i,i%2);	
	}
	printf("%d\n",dp[(n%2)][m]);
return 0;
}
