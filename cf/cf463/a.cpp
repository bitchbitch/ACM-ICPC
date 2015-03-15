// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月01日 星期一 20时34分45秒

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
  int n ,s;
  scanf("%d %d",&n,&s);
  int mx = -1 ; 
  s = s * 100 ;
  for(int i = 1;i <= n;i ++)
  {
    int a, b;
    scanf("%d %d",&a,&b);
	a = a*100 + b ; 
	if(s >= a )
	  {
	    mx = max(mx,(s-a)%100);
	  }
  }
  printf("%d\n",mx);
return 0;
}
