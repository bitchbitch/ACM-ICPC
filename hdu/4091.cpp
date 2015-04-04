// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年03月15日 星期日 16时59分22秒

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
const int INF = 5000;
LL V, Ha, Hb, Wa, Wb;
inline LL gcd (LL a, LL b) {
	return b == 0LL ? a : gcd (b, a % b);
}
int t; 
int main() {
	scanf("%d",&t);
	for(int CA = 1;CA <= t;CA++)
	{
		cin >> V >> Wa >> Ha >> Wb >> Hb;
		if (Ha * Wb < Wa * Hb) {
			swap (Ha, Hb);
			swap (Wa, Wb);
		}
		LL g = gcd (Wa, Wb), k = Wa / g * Wb;
		LL p = (V / k) - 1,ans=0;
		if(p>0) ans = p * (k / Wa) * Ha,	V -= k * p;

		LL t = 0;
		if(Wa<Wb){
			swap (Ha, Hb);
			swap (Wa, Wb);
		}
		for (LL i = 0; i * Wa <= V; i++) {
			LL j = (V - (i * Wa) ) / Wb;
			LL tem = i * Ha + j * Hb;
			t = max (tem, t);
		}
		cout <<"Case #"<< CA<<": "<<ans + t << endl;
	}
}
