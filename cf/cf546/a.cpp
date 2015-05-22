// File Name: a.cpp
// Author: cijianzy
// Created Time: 2015年05月23日 星期六 00时29分48秒

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
    LL n ,k,w; 
    scanf("%I64d %I64d %I64d",&k,&n,&w);
    LL sum = 0 ;
    sum = k *(1 + w)*w/2;
    if(sum  > n) 
        printf("%I64d\n",sum - n);
    else puts("0");
    return 0;
}
