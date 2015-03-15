// File Name: 11.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 12时07分20秒

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
struct node{
   int a, b ; 
}l[100005];
#define LL long long 
int cmp(node a , node b)
{
   return  a.b*1.0/a.a > b.b*1.0/b.a; 
}
int main(){
  int  n ; 
  while(scanf("%d",&n) != EOF)
  {
    for(int i =1 ;i <= n;i ++)
	{
	   scanf("%d",&l[i].a);
	}
    for(int i =1 ;i <= n;i ++)
	{
	   scanf("%d",&l[i].b);
	}
	sort(l+1,l+1+n,cmp);
	LL sum = 0 ;
	LL ans = 0 ;
	for(int i = 1;i <= n;i ++)
	{
	  sum += l[i].a ; 
	  ans += sum * l[i].b;
	}
	printf("%I64d\n",ans);
  }
  return 0;
}
