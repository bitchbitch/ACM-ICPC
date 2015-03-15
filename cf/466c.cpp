// File Name: 466c.cpp
// Author: darkdream
// Created Time: 2015年03月07日 星期六 10时09分39秒

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
int a[500005];
LL dp[500005];
map<LL,int> mp;
int main(){
  int n;  
  scanf("%d",&n);
  for(int i = 1;i <=  n;i ++)
  {
     scanf("%d",&a[i]);
     dp[i] = dp[i-1]+ a[i];
  }
  LL sum = 0 ; 
  for(int i = 1;i < n;i ++)
  {
     if(dp[i] == (dp[n] - dp[i])*2)
	 {
       sum += mp[dp[i]/2];
	 }
	 
	 mp[dp[i]] ++;
  }
  printf("%I64d\n",sum); 
return 0;
}
