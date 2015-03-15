// File Name: 349b.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 21时40分13秒

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

using namespace std;

int a[10];
int main(){
   int n;
   scanf("%d",&n);
   for(int i = 1;i <= 9 ;i ++)
	    scanf("%d",&a[i]);
   int maxn = -1; 
   int num; 
   for(int i =9; i >= 1 ;i--)
       {
	      int t = n/a[i];
		  if(t > maxn ||(t == maxn && a[i] < a[num]))
		  {
		     maxn = t; 
			 num = i ; 
		  }
	   }
   if(maxn == 0 )
   {
      printf("-1\n");
	  return 0 ;
   }
   int k = 0 ;
   n = n % a[num];
   while(n)
   {
     int ok = 0 ; 
	 for(int i = 9;i >= num+1;i --)
	 {
	    if(a[i] - a[num] <= n )
		{
		   n -= (a[i]-a[num]);
		   printf("%d",i);
		   ok = 1; 
		   k ++ ;
		   break;
		}
	 }
	 if(ok == 0 )
		 break;
   }
   for(int i = 1;i <= maxn - k;i ++)
	   printf("%d",num);
   printf("\n");
return 0;
}
