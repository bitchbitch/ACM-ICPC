// File Name: test.2.cpp
// Author: darkdream
// Created Time: 2015年04月15日 星期三 21时35分52秒

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
struct s{
	int i ; 
	int *p ;
};
int main(){
	s a; 
	int *p = &a.i;
	p[0] = 4; 
	p[1] = 3;
	a.p = p ; 
	a.p[1] = 1; 
	a.p[0] = 2 ; 
return 0;
}
