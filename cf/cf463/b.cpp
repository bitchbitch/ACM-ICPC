// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年09月01日 星期一 21时01分57秒

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
int a[100005];
int main(){
   long long ans = 0 ;
   long long rans = 0 ;
   int n ;
   scanf("%d",&n);
   for(int i =1 ;i <=n ;i ++)
   {
     scanf("%d",&a[i]);
	 ans +=  a[i-1] - a[i];
	 if(ans < 0 )
	 {
		 rans += -ans;
		 ans = 0 ;
	 }
   }
   printf("%lld\n",rans);
return 0;
}
