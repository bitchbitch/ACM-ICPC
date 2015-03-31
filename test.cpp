// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年03月31日 星期二 20时34分29秒

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
int main(){
	int n = 1000000;
	double ans = 0 ; 
	for(int i = 1;i <= n;i ++)
		ans += n*1.0/i ; 
	printf("%lf\n",ans);
		
   
return 0;
}
