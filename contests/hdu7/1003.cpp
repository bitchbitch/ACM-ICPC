// File Name: 1003.cpp
// Author: darkdream
// Created Time: 2014年08月12日 星期二 12时01分53秒

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
LL hs[100];
map<long long ,int> a;
LL sum ; 
LL solve(LL n )
{
	LL k = min(n,10000*1ll);
	for(LL i = 4;i <= 7000;i ++)
    {
		if(a.find(i) != a.end())
			continue;
	    LL t = n ;
		LL ok = 1; 
		while(t)
		{
	       if(t % i > 6 || !hs[t%i])
		   {   
			   ok = 0 ; 
		       break;
		   }
		   t = t / i ; 
		}
		if(ok)
	    {
			sum ++ ;
		}
	}
	return sum ; 
}
LL n ; 
LL solve3(LL i , LL j , LL k )
{
    double temp = (-j + sqrt(j*j - 4*i*k) )/(2*i);
	LL tt = (temp+0.5);
	if(fabs(temp - tt) < 1e-10 && tt > i && tt > j && tt > k+n)
	{
	   ///printf("%I64d %I64d %I64d %I64d\n",i,j,k+n,tt);
	   return tt;
	}
	return 0 ; 
}
int main(){
   LL t ;
   //freopen("intput","r",stdin);
   //freopen("output1","w",stdout);
   
   scanf("%I64d",&t);
   memset(hs,0,sizeof(hs));
   for(LL i = 3;i <= 6;i ++)
	   hs[i] = 1; 
   for(LL ca =1 ;ca <= t;ca ++)
   {
	    a.clear();
		scanf("%I64d",&n);
		if(n <= 6)
		{
		   if(hs[n])
		   printf("Case #%I64d: -1\n",ca);
		   else 
		   printf("Case #%I64d: 0\n",ca);
	       continue;;
		}
		sum = 0 ;
		for(LL i = 3;i <= 6;i ++)
		  for(LL j = 3;j <= 6;j ++)
		  {
			  LL t= (n-j)/i;
		      if((n-j) % i == 0 && i < t && j < t &&a.find(t) == a.end())
			  {
			    a[t] = 1; 
				sum ++ ;
			  }
			  for(LL s = 3 ;s <= 6; s ++)
			  {
				 t= solve3(i,j,s-n);
				 if(t && a.find(t) == a.end())
				 {
				   a[t] = 1; 
				   sum ++ ; 
				 }
			  }
		  }
		//printf("%I64d\n",sum);
		printf("Case #%I64d: %I64d\n",ca,solve(n));
   }
return 0;
}
