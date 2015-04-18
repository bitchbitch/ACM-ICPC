// File Name: c.cpp
// Author: darkdream
// Created Time: 2015年04月18日 星期六 10时34分50秒

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
int T;
struct node{
	double  x, y ; 
}a[20];
int n; 
int main(){
	scanf("%d",&T);
    
	for(int ca = 1;ca <= T; ca ++){
		scanf("%d",&n);
		for(int i= 0;i < n; i ++)
			scanf("%lf %lf",&a[i].x,&a[i].y);
		int num = (1 << n) -1;
	}
return 0;
}
