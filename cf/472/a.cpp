// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月28日 星期日 23时27分03秒

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
int isok(int n )
{
  for(int i = 2;i <= sqrt(n) ;i ++)
  {
     if(n % i == 0)
		 return 1;
  }
  return 0 ; 
}
int main(){
		int n ; 
		scanf("%d",&n);
		for(int i = 4;i <= n/2;i ++ )
		{
		  if(isok(i) && isok(n-i))
		  {
			  printf("%d %d\n",i,n-i);
		     return 0 ;
		  }
		}
	       
return 0;
}
