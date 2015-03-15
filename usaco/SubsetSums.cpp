// File Name: SubsetSums.cpp
// Author: darkdream
// Created Time: 2013年11月26日 星期二 10时35分56秒
/*
ID: dream.y1
PROG: subset
LANG: C++
*/
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

int sum[1000];
long long dp[1000];
int mx(int a, int b)
{
  if(a > b)
	  return a ; 
  else return b; 
}
int main(){
freopen("subset.in","r",stdin);
freopen("subset.out","w",stdout);
    sum[1] = 1 ; 
   for(int i= 2;i <= 40;i ++)
	   sum[i] += sum[i-1] + i ;
   memset(dp,0,sizeof(dp));
   int n ; 
   scanf("%d",&n);
   dp[0] = 1;
   for(int i = 1;i <= n;i ++)
   {
     for(int j = 500;j >= 0 ;j --)
	 {
         if(dp[j])
		  dp[j+i] += dp[j];
	 }
   }
   if(sum[n] % 2 == 0)
   printf("%lld\n",dp[sum[n]/2]/2);
   else printf("0\n");
   
   
   

return 0;
}
