// File Name: 1007.cpp
// Author: darkdream
// Created Time: 2014年08月07日 星期四 11时59分52秒

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
LL a[4000];
int main(){
  int t;
  scanf("%d",&t);
  while(t--)
  {
    int n ;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	   scanf("%lld",&a[i]);
	while(--n)
	{
	    for(int i = 1;i <= n;i ++)
			a[i] = a[i+1] - a[i];
	}
	printf("%lld\n",a[1]);
  }
return 0;
}
