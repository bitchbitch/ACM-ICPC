// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 15时47分47秒

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
int a, b; 
int prime[100005];
void sai(){
    for(int i = 2;i <= sqrt(100000) ;i ++ ){
        if(prime[i] == 0){
            int k = i * i ; 
            while(k <= 100000){
                prime[k] = 1 ; 
                k += i ; 
            }
        }
    }
}
int ar,al;
void solve(int l ,int r ){
    int tl = 0 ; 
    int mx = 0 ; 
    ar = 0 ; 
    al = 0 ; 
    for(int i = l ;i <= r; i ++){
        if(i == l || (prime[i-1] == 0 && prime[i] == 1) ){
            tl = i ; 
        }
        if(prime[i] == 1 && i - tl + 1 > mx){
            mx = i-tl + 1; 
            al = tl;
            ar = i ; 
        }
    }
}
int main(){
    time_t be,en;
    freopen("01.in","r",stdin);
    freopen("01.out","w",stdout);
    be = clock();
    int T;
    
    sai();
    scanf("%d",&T);
    for(int i = 1; i <= T;i ++){
        scanf("%d %d",&a,&b);
        solve(a,b);
        printf("[%d,%d]\n",al,ar);
    }
    en = clock();
    //printf("%lf",(en-be)*1.0/CLOCKS_PER_SEC);
return 0;
}
