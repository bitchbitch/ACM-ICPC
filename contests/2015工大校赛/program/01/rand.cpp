// File Name: rand.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 15时47分23秒

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
int randlr(int l , int r){
    if(r <=  l )
        swap(l,r);
    if(r == l)
        return l; 
    return rand()%(r-l+1) + l ;  
}
int main(){
    srand(time(NULL));
    freopen("01.in","w",stdout);
    printf("100\n");

    int a, b; 
    printf("1 100000\n");
    for(int i = 1;i <= 98 ;i ++){
       a = randlr(1,100000);
       b = randlr(a,100000);
       printf("%d %d\n",a,b);
    }
    printf("11 11\n");
return 0;
}
