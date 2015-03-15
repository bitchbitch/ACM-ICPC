// File Name: duipai.cpp
// Author: darkdream
// Created Time: 2014年11月28日 星期五 15时06分06秒

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
	FILE *p = fopen("darkdreamout","r");
	FILE *p1 = fopen("darkdremout1","r");
	char str[1000];
	char str1[1000];
	while(fgets(str,1000,p))
	{
	//	puts(str);
		fgets(str1,1000,p1);
	//	puts(str1);
	    if(strcmp(str,str1) != 0 )
		{
			printf("***\n");
		}
	}
	return 0;
}
