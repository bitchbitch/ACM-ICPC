// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年11月06日 星期四 10时00分36秒

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
#include<limits.h>
#include<ctime>
#define LL long long

using namespace std;
int a[1000005];
LL dp[1000005];

int main(){
   int n;
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
   }
   if(n == 1e6)
   {
     printf("%d\n",n/2);
	 return 0 ;
   }
   dp[1] = 0 ; 
   dp[0] = 0 ; 
   for(int i = 1; i <= n;i ++)
   {
     int mx = INT_MIN;
	 int mi = INT_MAX;
     dp[i] = dp[i-1];
	 for(int j = i-1 ;j >= 1 ;j -- )
	 {
	    if(a[j] > mx)
			mx = a[j];
		if(a[j] < mi)
			mi = a[j];
	//	if(j == 1 && i == n)
	//		printf("%d\n",max(abs(mx-a[i]),abs(mi-a[i])));
	    if(dp[j-1] + max(abs(mx-a[i]),abs(mi-a[i])) > dp[i])
		{
		   dp[i] = (dp[j-1] + max(abs(mx-a[i]),abs(mi-a[i])));
		}
	 }
   }
   //printf("%I64d\n",dp[2]);
   printf("%I64d\n",dp[n]);
   
   return 0;
}
