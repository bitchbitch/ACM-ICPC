// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年09月07日 星期日 23时39分39秒

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
int a[1004];
int main(){
  int n;
  scanf("%d",&n);
  scanf("%d",&a[1]);
  int sum = 0 ; 
  if(a[1] == 1 )
	  sum = 1; 
  for(int i =2 ;i <= n;i++)
  {
	scanf("%d",&a[i]);
    if(a[i] == 0 && a[i-1] == 1)
	{
      sum ++;	
	}
	if(a[i] == 1)
	{
	   sum ++ ;
	}
  }
  if(a[n] == 0 )
  {
    sum = max(sum-1,0) ; 
  }
  printf("%d\n",sum);
return 0;
}
