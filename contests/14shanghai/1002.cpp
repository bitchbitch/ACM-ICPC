// File Name: 1002.cpp
// Author: darkdream
// Created Time: 2014年09月27日 星期六 11时57分23秒

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
  int t; 
  scanf("%d",&t);
  LL sum = 0 ; 
  for(int ca  = 1;ca <= t ;ca ++)
  {
    sum = 0 ; 
	LL a, b ; 
	scanf("%I64d %I64d",&a,&b);
	for(LL i = a;i <= b;i ++)
	{
	  sum +=  1ll*i*i*i;
//	  printf("%I64d\n",sum);
	}
	printf("Case #%d: %I64d\n",ca,sum);
  }
return 0;
}
