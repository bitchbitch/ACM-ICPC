// File Name: sizeof.cpp
// Author: darkdream
// Created Time: 2015年05月02日 星期六 19时02分36秒

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

struct node{
	short a1;
	short a2;
	short a3; 
}tmp;
int a[100];
char val[10];
void test(char val[]){
	cout << sizeof(val) << endl;
}
int main(){
	test(val);

	printf("%d\n",sizeof(tmp));
	printf("%d\n",sizeof(&a));
return 0;
}
