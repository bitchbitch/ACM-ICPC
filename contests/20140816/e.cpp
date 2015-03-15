// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年08月16日 星期六 12时56分58秒

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
#define maxn 1000
int main(){   
	LL sum = 0 ;:q

	for(int i=1 ;i <= maxn ;i ++)
		for(int j = i+1;j <= maxn;j ++)
			for(int s = j+1; s <= maxn; s++)
				sum ++ ; 
	printf("%lld\n",sum);
return 0;
}
