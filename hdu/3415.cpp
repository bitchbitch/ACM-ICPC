// File Name: 3415.cpp
// Author: darkdream
// Created Time: 2013年11月28日 星期四 20时44分21秒

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

int a[200005];
int main(){
   int n ,k; 
   int t; 
   scanf("%d",&t);
   while(t--)
   {
	 memset(a,0,sizeof(a));
     scanf("%d %d",&n,&k);
	 
	 for(int i = 1; i<= n;i ++)
	 {
	     scanf("%d",&a[i]);
	 }
	 for(int i =1;i <= k; i++)
     {
	   a[i+n] = a[i];
	 }
	 int max = 0;
	 int sum = 0 ;
	 int be = 1 ; 
	 int ta, tb ;
	 for(int i = 1;i <= i + k ;i ++)
	 {
	    sum += a[i];
		if(sum < 0 )
		{
		  be = i; 
		  sum = 0 ;
		}
		if(sum > max )
		{
		  max = sum; 
		  ta = be; 
		  tb = i;
		}
		if(i - be == k )
		{
		
		}
	 }
   }
return 0;
}
