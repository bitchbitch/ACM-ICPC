// File Name: test1003.cpp
// Author: darkdream
// Created Time: 2014年08月13日 星期三 19时52分27秒

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
    freopen("intput","w",stdout);
	int n = 300000;
    printf("%d\n",n);
	srand(time(NULL));
	for(int i =1 ;i <= n;i ++)
    {
		LL t = 1ll*(rand()%1000000+1)*(rand()%1000000+1);
        if(t == 0 )
		{
		   i -- ;
		   continue;
		}
		printf("%lld\n",t);
	}		
return 0;
}
