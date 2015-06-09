// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 16时38分39秒

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
int n;
int gcd(int a, int b){
    return b ==0 ?a:gcd(b,a%b);
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--){ 
        scanf("%d",&n);
        for(int i = n/2;i >= 1 ;i --){
            if(gcd(i,n) == 1){
                printf("%d\n",i);
                break;
            }
        }
    }
return 0;
}
