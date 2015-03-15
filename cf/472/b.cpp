// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年09月28日 星期日 23时39分54秒

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
int a[3000];
int cmp(int a, int b)
{
   return a > b ; 
}
int main(){
   int n , k ; 
   scanf("%d %d",&n,&k);
   for(int i = 1;i <= n;i ++)
   {
       scanf("%d",&a[i]);
   }
   sort(a+1,a+1+n,cmp);
   int p = 0 ; 
   LL ans = 0 ;
   while(p < n)
   {
      ans +=(a[p+1]-1)*2;
	  p += k ; 
   }
   printf("%I64d\n",ans);
return 0;
}
