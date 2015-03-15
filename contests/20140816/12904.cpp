// File Name: 12904.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 13时34分26秒

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

int main(){
  LL a, b ; 
  while(scanf("%lld %lld",&a,&b) != EOF)
  {
      printf("%lld\n",(a-b)*(a-b-1)/2);
  }
return 0;
}
