// File Name: 1009.cpp
// Author: darkdream
// Created Time: 2014年09月14日 星期日 12时44分40秒

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
#define M 10000007
using namespace std;
int n ,m ;
int a[6000000];
int temp ;
int hs[10000007];
int main(){
	a[1] = 2333;
    for(int i = 2;i <= 5000000;i ++)
	{
      a[i] = ((a[i-1] * 10) +3) % M ;
	}
	int i =0 ;
	memset(hs,0,sizeof(hs));
	while(1)
	{
	  i ++ ;
	  temp = (temp + a[i] )% M;
	  if(hs[temp])
	  {
		  printf("%d %d %d\n",temp,i,hs[temp]);
	  }
	  if(i > 400000)
		  break;
	  hs[temp] = i; 
	  
	}
return 0;
}
