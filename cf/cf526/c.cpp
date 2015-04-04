/************************************************************
 * Author : darkdream
 * Email : cijianzy@gmail.com 
 * Last modified : 2015-04-05 02:29
 * Filename : c.cpp
 * Description :
 * *********************************************************/
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
  ans = h1* v;
  ans += ((c-w1*v)/w2) * h2;
  return ans;
}
LL ans = 0 ; 
LL gcd(LL a, LL b)
{
	return b==0 ?a:gcd(b,a%b);
}

int main(){
	scanf("%lld %lld %lld %lld %lld",&c,&h1,&h2,&w1,&w2);
    double d1,d2;
	d1 = h1*1.0/w1;
	d2 = h2*1.0/w2;
	LL sum = 0 ;
	if(d1 < d2)
	{
		swap(h1,h2);
		swap(w1,w2);
	}
	LL lcm = w1*w2/gcd(w1,w2);
	ans = (c/lcm) * (lcm/w1)*h1;
	c = c %lcm;
	ans += max()
	printf("%lld\n",ans);
return 0;
}
