// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年04月05日 星期日 01时16分14秒

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
LL c,h1,h2,w1,w2;
LL count(LL v)
{
  LL ans = 0 ; 
  ans = h1*v;
  ans += (LL)((LL)(c-w1*v)/w2) * h2;
  return ans;
}
LL ans = 0 ; 
LL gcd(LL a, LL b)
{
	return b==0 ?a:gcd(b,a%b);
}
int main(){
	scanf("%I64d %I64d %I64d %I64d %I64d",&c,&h1,&h2,&w1,&w2);
	LL lcm = w1/gcd(w1,w2)*w2;
	LL tmp = (c/lcm) - 1; 
	if(tmp >= 1)
	{
     	ans = tmp  * max((lcm/w1)*h1,(lcm/w2)*h2) ;
	    c = c % lcm + lcm ;
	}
	if(w1 < w2)
	{
	   swap(h1,h2);
	   swap(w1,w2);
	}
	LL mx = 0 ;
	//printf("%I64d %I64d %I64d\n",ans,lcm,c);
    for(LL i = 0;i * w1 <= c ;i ++)
	{
        mx = max(mx,count(i)) ; 	
	}
	printf("%I64d\n",ans + mx);
return 0;
}
