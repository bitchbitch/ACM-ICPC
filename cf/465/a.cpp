// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月07日 星期日 23时27分31秒

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
int a[200];
int main(){
  int n , m ;
  scanf("%d",&n);
  for(int i =1;i <= n;i ++)
  {
     scanf("%1d",&a[i]);
  }
  int ans = 0; 
  int temp = 1; 
  for( int i = 1;i <= n;i ++)
  {
     temp = (a[i] + temp)/2;
	 if(temp == 0 || a[i] == 0)
		{
		  ans = i ; 
		  break;
		}
  }
  if(ans == 0 )
	  ans = n ;
  printf("%d\n",ans);
return 0;
}
