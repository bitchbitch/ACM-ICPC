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
    freopen("in.txt","w",stdout);
    printf("10000\n");

    int a, b; 
    for(int i = 1;i <= 10000;i ++){
        printf("%d\n",randlr(1,1000000000));
    }
return 0;
}
