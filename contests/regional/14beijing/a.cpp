// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年11月29日 星期六 12时08分28秒

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
  int t , s;
}a[10005];
int cmp(node a ,node b)
{
  return a.t < b.t;
}
double Fabs(double t)
{
   if(t < 0)
	   return -t;
   return t;
}
int main(){
  int t ; 
  scanf("%d",&t);
  for(int ca = 1; ca <= t ; ca ++)
  {
       int n; 
	   scanf("%d",&n);
	   for(int i = 1;i <= n;i ++)
	   {
	     scanf("%d %d",&a[i].t ,&a[i].s);
	   }
	   double mx = 0 ; 
       sort(a+1,a+1+n,cmp);
	   for(int i = 2;i <= n;i ++)
	   {
	       mx = max(mx,Fabs(1.0*(a[i].s - a[i-1].s)/(a[i].t-a[i-1].t)));
	   }
     printf("Case #%d: %.2f\n",ca,mx);
  }
return 0;
}
