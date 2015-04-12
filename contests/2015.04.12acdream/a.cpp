// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月12日 星期日 19时30分44秒

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
int a[4];
int gcd(int a, int b)
{
  return b == 0 ?a:gcd(b,a%b);
}
int main(){
  int t; 
  scanf("%d",&t);
  while(t--)
  {
	  for(int i = 1;i <= 3; i ++)
		  scanf("%d",&a[i]);
	  sort(a+1,a+1+3);
	  int x , y ; 
	  x = gcd(a[1],a[2]);
	  y = gcd(a[2],a[3]);
	  if(a[1]/x == 4 && a[2]/x == 5)
	  {
	      if(a[2]/y == 5 && a[3]/y == 6)
		  {
		      printf("major\n");
			  continue;
		  }else{
		      printf("noise\n");
		  }
		  continue;
	  }else if(a[1]/x == 5 && a[2]/x == 6){
	     if(a[2]/y == 4 && a[3]/y == 5)
		 {
		      printf("minor\n");
		 }else
		      printf("noise\n");
		 continue;
	  }else{
		      printf("noise\n");
			  continue;
	      
	  }
  }
return 0;
}
