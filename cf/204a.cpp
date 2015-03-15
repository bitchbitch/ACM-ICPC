// File Name: 204a.cpp
// Author: darkdream
// Created Time: 2014年07月25日 星期五 09时16分57秒

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
LL sum[20];
LL temp[20];
LL count(LL n)
{
   int len = 0;
   LL k = n;
   while(k)
   {
       len ++ ; 
	   k/= 10 ; 
   }
 //  printf("%d\n",len);
   if(len == 1)
	   return n+1;
   LL ans = sum[len-1];
   int t = len ; 
   int a[20];
   while(n)
   {
      a[t] = n %10 ; 
      n = n/10 ;
	  t--;
   }
   for(int i =1 ;i <= len-1;i ++)
   {
        int be; 
		be = i == 1?1:0;
		for(;be < a[i];be++)
		{
		  ans += temp[len-i-1]; 
		}
   }
   if(a[len] >= a[1])
	   ans ++ ; 
   return ans; 
}
int main(){
   LL n ,m;
   temp[0] =1 ;
   temp[1] = 10 ; 
   for(int i =1 ;i <= 17 ;i ++)
	   temp[i] = temp[i-1]*10;
   sum[0] = 1; 
   sum[1] = 10; 
   for(int i = 2 ;i <= 19 ;i ++)
   {
	   sum[i] = sum[i-1];
       for(int j = 1;j <= 9 ;j ++)
		      sum[i] += temp[i-2]; 
   }
  // printf("%I64d\n",count(1));
   scanf("%I64d %I64d",&n,&m);
   printf("%I64d",count(m)-count(n-1)); 
return 0;
}
