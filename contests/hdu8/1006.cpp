// File Name: 1006.cpp
// Author: darkdream
// Created Time: 2014年08月14日 星期四 12时32分22秒

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
    LL h,a,b,k;
	int ca = 0 ; 
	while(scanf("%I64d %I64d %I64d %I64d",&h,&a,&b,&k) != EOF)
	{
	   ca ++ ; 
	   if(h == 0 && a == 0 && b == 0 && k == 0 )
		   break;
	   int ok = 1;
	   LL t = b - (a-b)*k;
	   if(t < 0 ||h - (a-b)*(k-1) - a <= 0  || h - a <= 0  )
		   printf("Case #%d: YES\n",ca);
	   else printf("Case #%d: NO\n",ca);
	}
return 0;
}
