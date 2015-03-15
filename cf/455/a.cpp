// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月08日 星期五 23时25分48秒

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
int a[110005];
int hs[100004];
LL sum[100004];
int main(){
   //freopen("input","r",stdin);
   int n ;
   scanf("%d",&n);
   memset(hs,0,sizeof(hs));
   memset(sum,0,sizeof(sum));
   for(int i =1 ;i<= n;i ++)
   {
       scanf("%d",&a[i]);
	   hs[a[i]] ++; 
   }
   int t = 0 ;
   LL ans = 0 ; 
   sum[0] = 0 ;
   sum[1] = hs[1]*1;
   sum[2] = hs[2]*2; 
   for(int i = 3 ;i <= 100004;i  ++)
   {
      sum[i] = 1ll*hs[i]*i + max(sum[i-2],sum[i-3]);
	  ans = max(sum[i],ans);
   }
   printf("%I64d",ans);
return 0;
} 
