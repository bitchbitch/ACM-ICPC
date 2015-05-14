// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 00时38分58秒

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
LL n , m ; 
LL a[200005];
int main(){
     scanf("%lld %lld",&n,&m);
	 LL sum = 0 ; 
	 for(int i = 1;i <= n;i ++)
	 {
		 scanf("%lld",&a[i]);
		 sum += a[i];
	 }
	 for(int i = 1;i <= n;i ++)
	 {
		  LL tsum = sum - a[i];
			  LL mx = min(a[i],m-(n-1));  
			  LL mi = (m-tsum);
			  if(mi <= 0)
				  mi = 1; 
			  printf("%lld ",a[i]-(mx-mi+1));
	 }
return 0;
}
