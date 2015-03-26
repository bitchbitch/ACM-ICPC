// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年03月27日 星期五 00时49分40秒

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
int n ;
int a[100005];
int hs[1000005];
int ths[1000005];
int main(){
	int n ; 
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
	   scanf("%d",&a[i]);
	   hs[a[i]] ++ ; 
	}
	LL sum = 0 ; 
	int tmp = 0 ; 
    for(int i = 1000000 ;i >= 0 ;i --)
	{
	   ths[i] = hs[i+1] + hs[i] ;
       if(ths[i] >=  2)	
	   {
	     if(tmp == 0 )
		 {
			 tmp = i; 
			 if(hs[i+1] == 1)
			 {
				 hs[i+1] -= 1;
				 hs[i] -=1;
			 }else{
			     hs[i] -= 2; 
			 }
			 i++;
		 }
		 else {
		    sum += 1ll*tmp * i ;
		//	printf("%d %d\n",tmp,i);
			if(hs[i+1] == 1)
			 {
				 hs[i+1] -= 1;
				 hs[i] -=1;
			 }else{
			     hs[i] -= 2; 
			 }
			 i++;
			 tmp = 0 ; 
		 }
		 //printf("%lld\n",sum);
	   }
	}
	printf("%lld\n",sum);
return 0;
}
