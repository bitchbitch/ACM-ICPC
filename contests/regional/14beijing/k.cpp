// File Name: k.cpp
// Author: darkdream
// Created Time: 2014年11月29日 星期六 12时14分47秒

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
int a[3000005];
int main(){
   int t; 
   scanf("%d",&t);
   for(int ca = 1; ca <= t ;ca ++)
   {
      int n; 
	  scanf("%d",&n);
	  int t = 1e9 ; 
	  int sum = 0 ; 
	  for(int i = 1;i <= n;i ++)
	  {
	    scanf("%d",&a[i]);
	  }
	  t = a[n];
	  for(int i = n-1;i >= 1;i -- )
	  {
	      if(a[i] > t)
		  {
		     sum ++ ; 
		  }
		  if(a[i] < t)
			  t = a[i];
	  }
	  printf("Case #%d: %d\n",ca,sum);
   }
return 0;
}
