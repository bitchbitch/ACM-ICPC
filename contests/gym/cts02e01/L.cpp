// File Name: L.cpp
// Author: darkdream
// Created Time: 2014年09月11日 星期四 20时45分36秒

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
struct node{
  LL x,  y ;
}a[50005];
bool cmp(node a, node b)
{
	return a.x + a.y < b.x + b.y;
}
int main(){
  LL n ;
  scanf("%lld",&n);
  for(int i = 1;i <= n;i ++)
  {
    scanf("%lld %lld",&a[i].x,&a[i].y);
  }
  sort(a+1,a+1+n,cmp);
  LL sum = 0 ;
  LL ans = -2*1e9 ;
  for(int i = 1;i <= n;i ++ )
  {
	  if(sum -a[i].y > ans)
	  {
	    ans = sum - a[i].y;
	  }
	  sum += a[i].x ; 
  }
  printf("%lld\n",ans);
return 0;
}
