// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年04月30日 星期四 09时50分38秒

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
//typedef double Money;
int n = 0x7FFFFFFF;
int main(){
	int t =0 ; 
	printf("%d\n",n);
	while(n){
		printf("%d",n%2);
		n/= 2; 
		t ++;
	}
	printf("\n%d\n",t);
	return 0 ; 
}


