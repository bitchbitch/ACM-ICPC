// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 23时31分20秒

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

int main(){
  int n , m ; 
  scanf("%d %d",&n,&m);
  n = min(n,m);
  if(n % 2 == 1)
	  printf("Akshat\n");
  else printf("Malvika\n");
return 0;
}
