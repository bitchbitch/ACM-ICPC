// File Name: i.cpp
// Author: darkdream
// Created Time: 2014年10月22日 星期三 11时58分28秒

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
double dis(double x, double y , double x1,double y1)
{
   return sqrt((x-x1)*(x-x1) + (y - y1) * (y - y1));
}
struct node{
  int t,x,y;
}a[1004];
int main(){
  int t; 
  scanf("%d",&t);
  while(t--)
  {
     int n; 
	 scanf("%d",&n);
	 scanf("%d %d %d",&a[1].t,&a[1].x,&a[1].y);
	 double ans = 0 ; 
	 for(int i = 2;i <= n;i ++)
	 {
	     scanf("%d %d %d",&a[i].t,&a[i].x,&a[i].y);
	     ans  = max(ans,dis(a[i].x,a[i].y,a[i-1].x,a[i-1].y)/(a[i].t -a[i-1].t));
	 }
	 printf("%.10lf\n",ans);
  }
return 0;
}
