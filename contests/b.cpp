// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年11月06日 星期四 08时41分33秒

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
int a[200005];
int p[2000006];
int n;
int main(){
    scanf("%d",&n);	
    for(int i = 1;i <= n;i ++)
	{
	   scanf("%d",&a[i]);
	   p[a[i]+1] = a[i];
	}
	sort(a+1,a+1+n);
	int tt= 0 ; 
	for(int i = 1;i <= a[n]*2 ;i ++)
	{
	   if(p[i])
	   {
	     tt= p[i];
	   }else{
	    p[i] = tt; 
	   }
	}
	int mx = 0 ; 
	a[0] = 0;
	for(int i = 1;i<= n;i ++)
	{
	   if(a[i] != a[i-1])
	   {
		   int tmp = a[i] ;
		   
		   while(tmp <= a[n])
		   {
			  tmp +=a[i];
		      int t = p[tmp];
			  if(t % a[i] > mx)
				  mx = t % a[i];
		   }
	   }
	}
	printf("%d\n",mx);
return 0;
}
