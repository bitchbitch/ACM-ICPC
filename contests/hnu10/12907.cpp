// File Name: 12907.cpp
// Author: darkdream
// Created Time: 2014年08月17日 星期日 12时38分22秒

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
int a[10000];
int main(){
  a[1] = 1; 
   a[2] = 1; 
  for(int i = 3;i <= 14;i ++)
  {
	  a[i] = a[i-1] + a[i-2];
    printf("%d\n",a[i]);
  }
return 0;
}
