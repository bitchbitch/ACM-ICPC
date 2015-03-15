// File Name: 148d.cpp
// Author: darkdream
// Created Time: 2015年03月11日 星期三 10时11分37秒

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
double dp[2005][1005];
int main(){
   int w, b; 
   scanf("%d %d",&w,&b);
   if(w == 0)
   {
      printf("%.9f",0.0);
	  return 0 ; 
   }
   dp[0][w] = 1;
   double sum = 0 ; 
   int n = w + b; 
   for(int i = 1;i <= n; i++)
   {
      for(int j = 0;j <= w;j ++)
	  {
        if(i % 3 == 1 ){
		   sum += dp[i-1][j+1]*(j+1)/(n-i+1);
		   dp[i][j] = dp[i-1][j] * (n-i+1-j)/(n-i+1);
		}
		else if(i% 3 == 2 ){
		   dp[i][j] = dp[i-1][j] * (n-i+1-j)/(n-i+1);
		}	
	    else{ 
		   dp[i][j] = dp[i-1][j] * (n-i+1-j)/(n-i+1);
	       dp[i][j] += dp[i-1][j+1]*(j+1)/(n-i+1);	
		}
	  }
   }
   printf("%.9f",sum);
return 0;
}
