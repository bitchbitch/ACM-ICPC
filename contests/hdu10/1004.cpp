// File Name: 1004.cpp
// Author: darkdream
// Created Time: 2014年08月21日 星期四 12时08分12秒

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
int a[100005];
LL sum[100005];
int main(){
   int t; 
   scanf("%d",&t);
   for(int ca = 1;ca <= t ; ca ++ )
   {
     int n ; 
	 scanf("%d",&n);
	 memset(sum,0,sizeof(sum));
	 for(int i =1 ;i <= n;i ++)
	 {
	    scanf("%d",&a[i]);
	 }
	 printf("Case #%d: %lld\n",ca,sum[i]);
   }
return 0;
}
