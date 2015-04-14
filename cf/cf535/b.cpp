// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年04月15日 星期三 00时46分48秒

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
char str[100];
int len ;
LL sum[15];
int main(){
	scanf("%s",str);
	int len = strlen(str) ; 
	LL ans=0 ;  
	LL tmp = 1; 
    for(int i = 1;i <= 9 ;i ++)
	{
		tmp *= 2; 
		sum[i] = sum[i-1] + tmp ; 
	}
	ans = sum[len-1];
	for(int i =0 ;i < len;i ++)
	{
      if(str[i]== '7')	
	  {
	     ans += 1 << (len-i-1);
	  }
	}
	printf("%lld\n",ans+1);
return 0;
}
