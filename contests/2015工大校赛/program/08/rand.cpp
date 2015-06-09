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
    printf("2000\n");
    int len ,k ; 
    for(int i = 1;i <= 500 ;i ++){
        len = randlr(1,100);
        k = randlr(0,len-1);
        for(int i = 1;i <= len; i ++){
            printf("%d",randlr(0,9));
        }
        printf(" %d\n",k);
    }
    for(int i = 1;i <= 1400;i ++){ 
        len = randlr(101,999);
        k = randlr(0,len-1);
        for(int i = 1;i <= len; i ++){
            printf("%d",randlr(0,9));
        }
        printf(" %d\n",k);
    }
    for(int i = 1;i <= 100;i ++){ 
        len = randlr(1000,1000);
        k = randlr(0,len-1);
        for(int i = 1;i <= len; i ++){
            printf("%d",randlr(0,9));
        }
        printf(" %d\n",k);
    }
return 0;
}
