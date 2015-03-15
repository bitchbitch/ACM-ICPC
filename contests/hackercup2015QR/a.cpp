// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年01月10日 星期六 17时16分44秒

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
LL a[20];
int T;
LL SP(LL i , LL j, LL tmp)
{
     int x =(tmp)/a[i] % 10 ; 
	 int y =(tmp)/a[j] % 10 ;
	 if(x == 0 && j == T)
		 return tmp;
	 return tmp - x * a[i] - y*a[j] + y *a[i] + x*a[j]; 
}
int count(LL tmp)
{
  int num = 0 ; 
   while(tmp)
   {
     num ++;
	 tmp/= 10;
   }
   return num ;
}
int main(){
   int t ;
   scanf("%d",&t);
   a[1] = 1; 
   for(int i = 2;i <= 13 ;i++)
   {
     a[i] = a[i-1]*10;
   }
   for(int ca = 1 ; ca <= t ;ca ++)
   {
      LL tmp;
	  scanf("%lld",&tmp);
	  LL mx = tmp;
	  LL mi = tmp;
	  T = count(tmp);
	  for(int i = 1;i <= T;i ++)
		  for(int j = i + 1;j <= T ;j ++)
		  {
		    LL now = SP(i,j,tmp);
			if(now > mx)
				mx = now;
			if(now < mi)
				mi = now;
		  }
	  printf("Case #%d: %lld %lld\n",ca,mi,mx);
   }

return 0;
}
