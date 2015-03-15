// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月18日 星期四 23时29分43秒

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

int main(){
   int n ; 
   scanf("%d",&n);
   int sum = 0 ;
   int ans = 0 ; 
   for(int i= 1;i <= n;i ++)
   {
	   int a, b;
	   scanf("%d %d",&a,&b);
	   if(a <= b -2 )
	   {
	     ans ++; 
	   }
   }
   printf("%d\n",ans);
return 0;
}
