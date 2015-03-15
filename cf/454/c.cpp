// File Name: c.cpp
// Author: darkdream
// Created Time: 2014年08月02日 星期六 00时14分13秒

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
double P(double  x,int  n)
{
  if(n == 1)
	  return x; 
  double t = P(x,n/2);
  if(n % 2 == 0)
  {
	  return t*t; 
  }else{
    return t*t*x;
  }
}
double a[100005];
int main(){
   int n , m; 
   scanf("%d %d",&m,&n);
   double ans ;
   a[1] = ans = P(1.0/m,n);
   for(int i = 2;i <= m;i ++)
   {
       a[i] = P(i*1.0/m,n);
	   ans += i *(a[i] - a[i-1]);
   }
   printf("%lf\n",ans);
return 0;
}
