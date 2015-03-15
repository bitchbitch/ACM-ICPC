// File Name: 163div2.a.cpp
// Author: darkdream
// Created Time: 2013年01月22日 星期二 23时26分28秒

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

using namespace std;

int main(){
    char  a[100];
	int n ;
	scanf("%d",&n);
	getchar();
	gets(a);
	int i ,sum = 0,t;

    for (i = 1; i < n; i++)
	{
		if ( a[i] == a[i-1])
			sum ++;

	}
 printf("%d",sum);
return 0;
}
