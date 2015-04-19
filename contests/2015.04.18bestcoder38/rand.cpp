// File Name: rand.cpp
// Author: darkdream
// Created Time: 2015年04月18日 星期六 22时04分56秒

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
int a[1000];
int main(){
	freopen("in","w",stdout);
	printf("10000\n");
	for(int i = 1;i <= 10000 ;i ++)
	{
		for(int j = 1;j <= 4; j ++){
		  a[j] = rand()% 20;
		}
		if(a[1] > a[2] || a[3] > a[4])
			i--;
		else printf("%d %d %d %d\n",a[1],a[2],a[3],a[4]);
	}
return 0;
}
