// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月20日 星期三 23时26分20秒

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
   int n ,m ; 
   scanf("%d %d",&n,&m);
   int t = 1;
   n --;
   while(n)
   {
	 t ++;
     n --; 
     if(t % m == 0 )
		 n ++ ;
	// printf("%d %d\n",n,t);
   }
   printf("%d\n",t);
return 0;
}
