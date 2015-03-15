// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年11月11日 星期二 22时43分28秒

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
   LL n ;
   scanf("%lld",&n);
   if(n % 2 == 0 )
	   printf("%d\n",n/2);
   else printf("%d\n",n/2 -n);
return 0;
}
