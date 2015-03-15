// File Name: 331c1.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 22时32分18秒

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

int main(){
    int n; 
	scanf("%d",&n);
	int ans = 0 ; 
	while(n)
	{
       int t = n;  
	   int maxn = 0 ; 
	   while(t)
	   {
	       maxn = max(maxn,t%10);
		   t = t /10 ;
	   }
	   n -= maxn;
	   ans ++; 
	}
	printf("%d\n",ans);
return 0;
}
