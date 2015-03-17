// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年03月18日 星期三 00时41分16秒

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
LL solve(LL a, LL b)
{
	
   if(b > a )
	   swap(a,b);
   if(b == 0 )
	   return 0; 
   return a/b + solve(b,a%b);
}
int main(){
  LL n , m; 
  scanf("%lld %lld",&n,&m);
  printf("%lld\n",solve(n,m)); 
return 0;
}
