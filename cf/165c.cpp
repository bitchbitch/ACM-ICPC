// File Name: 165c.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 17时17分25秒

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

int hs[1000005];
char str[1000005];
int main(){
  int n ; 
  scanf("%d",&n);
  int temp ;
  int sum = 0 ; 
  scanf("%s",&str[1]);
  hs[0] = 0 ;
  LL  ans = 0 ;
  int len = strlen(&str[1]);
  for(int i= 1;i <= len;i ++)
  {
     scanf("%1d",temp);
	 if(temp)
	 {
	     sum ++ ;
	     hs[sum] = i ;
		 ans += (i-hs[sum-1])*(hs[sum-n]-hs[sum-n-1]);
	 }

  }
  ans += (len+1-hs[sum])*(hs[sum-n+1]-hs[sum-n]);
return 0;
}
