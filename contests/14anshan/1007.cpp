// File Name: 1007.cpp
// Author: darkdream
// Created Time: 2014年09月13日 星期六 12时01分10秒

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
int cmp(int a, int b)
{
  return a > b ; 
}
int a[1000];
int main(){
  int t ;
  scanf("%d",&t);
  while(t--)
  {
    int n;
	scanf("%d",&n);
    double  temp  = 1 ; 
	double ans = 0 ; 
	int k ;
	for(int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n,cmp);
	for(int i =1 ;i <= n;i ++)
	{
	  ans +=  temp *a[i];
	  temp *= 0.95;
	}
	printf("%lf\n",ans);
  }
return 0;
}
