// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年07月29日 星期二 12时52分06秒

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
LL f[100];
int main(){
  f[0] = 1 ; 
  f[1] = 1; 
  for(int i =2 ;i <= 100 ;i ++)
  {
     f[i] = f[i-1]  + f[i-2];
	 if(f[i] >= 1e18)
		 break;
	 printf("%d %lld\n",i,f[i]);
  }
return 0;
}
