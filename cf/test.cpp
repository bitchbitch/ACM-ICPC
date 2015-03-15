// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年03月13日 星期五 08时53分57秒

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
    for(int i = 1;i <= 10000 ;i ++)
	{
		 if(i*(1+i)/2  >= 400000)
		 {
			 printf("%d\n",i);
		     break;
		 }
	}
return 0;
}
