// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年11月02日 星期日 21时33分19秒

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
	FILE *p = fopen("ans","r");
	FILE *p1 = fopen("ans1","r");
	char str[1000];
	char str1[1000];
	int t = 0 ; 
	while(fgets(str,1000,p))
	{
		t++;
		fgets(str1,1000,p1);
		if(strcmp(str,str1) != 0 )
		{
			puts(str);
			puts(str1);
			printf("***%d\n",t);
		}
	}
	return 0;
}
