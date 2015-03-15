// File Name: 1032.cpp
// Author: darkdream
// Created Time: 2014年08月11日 星期一 23时07分28秒

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
  LL x, y; 
}a[100005];
bool cmp(node c, node b )
{
   if(c.x == b.x)
    return c.y < b.y;
  return c.x < b.x;
}
int main(){
    int n ; 
	scanf("%d",&n);
   for(int i =1 ;i <= n;i ++)
   {
     scanf("%lld %lld",&a[i].x,&a[i].y);
     a[i].y = a[i].x + a[i].y -1; 
   }
   sort(a,a+n,cmp);
   LL temp = -1;
   int sum =0 ; 
   for(int i =1 ;i <= n;i ++)
   {
      if(temp < a[i].y)
	  {
		 //printf("%lld %lld\n",temp,a[i].y);
	     if(temp < a[i].x)
			 temp = a[i].x ;
		 else temp = temp + 1;
		 sum ++ ; 
	  }
   }
   printf("%d\n",sum);
return 0;
}
