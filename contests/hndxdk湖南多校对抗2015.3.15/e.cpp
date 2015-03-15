// File Name: e.cpp
// Author: darkdream
// Created Time: 2015年03月15日 星期日 14时02分10秒

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
int a[1000005];
int dp[1000005];
int main(){
   int t ; 
   scanf("%d",&t);
   while(t--)
   {
      int n ;
	  scanf("%d",&n);
	  int tmp ;
	  int mi = 0 ; 
	  int sum = 0 ;
	  for(int i = 1;i <=n;i ++)
	  {
	     scanf("%d",&a[i]);
		 sum += a[i];
		 dp[i] = max(dp[i-1],sum);
	  }
	  sum =  0 ; 
	  for(int i = 1;i <=n;i ++)
	  {
	       if(sum <= 0 )
			   sum = 0 ; 
		   sum += a[i];
		   mi = max(mi,sum);
	  }
	  sum = 0 ;
	  for(int i = n;i >= 1;i --)
	  {
		  sum += a[i];
	      mi = max(sum + dp[i-1],mi) ; 	  
	  }
	  printf("%d\n",mi);
   }
   return 0;
}
