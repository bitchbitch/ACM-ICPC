// File Name: 165c.1.cpp
// Author: darkdream
// Created Time: 2014年07月30日 星期三 10时36分03秒

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
#define LL long long 
int dp[1000004];
char str[1000005];
int main(){ 
	 int n ; 
	 scanf("%d",&n);
	 scanf("%s",str);
	 int len = strlen(str);
	 int sum = 0 ;
	 memset(dp,0,sizeof(dp));
	 dp[0]++;
	 LL ans = 0 ; 
	 for(int i = 0 ;i < len ;i ++)
	 {
	      if(str[i] == '1') 
		  {
		    sum ++ ; 
		  }
		  int nsum = sum - n ;
		  if(nsum >= 0)
			  ans += dp[nsum];
		  dp[sum]++; 
	 }

	 printf("%lld\n",ans);
return 0;
}
