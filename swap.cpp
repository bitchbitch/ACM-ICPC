// File Name: swap.cpp
// Author: darkdream
// Created Time: 2015年05月02日 星期六 19时16分11秒

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

void Swap(int *p ,int *q){
	int tmp = *p ;
	*p = *q;
	*q = tmp ;
}
int main(){
	int a ,b; 
	a = 1; 
	b = 2 ;
	Swap(&a,&b);
	printf("%d %d\n",a,b);

return 0;
}
