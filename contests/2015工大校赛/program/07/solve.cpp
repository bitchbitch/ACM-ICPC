// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 22时27分26秒

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
int hs[20];
int sum[20];
int num[20];
int n;
int solve(){
   LL k = 0 ; 
   for(int i = 1;i <= n;i ++)
       k = k * 10 + num[i] ;
   LL t= sqrt(k);
   if(t * t == k )
       return 1; 
   return 0 ; 
}
int main(){
    freopen("out.txt","w",stdout);
    int k = (1 << 9)-1;
    int s,t;
    for(int i =1;i <= k;i ++){
        t = 0 ; 
        s = i ; 
        n = 0 ;
        while(s){
            t ++ ;
            if(s % 2){
              n ++ ;   
              num[n] = t; 
            }
            s = s/2; 
        }
        do{
            sum[n] += solve();
        }while(next_permutation(num+1,num+1+n));
    }
    for(int i = 1;i <= 9;i ++)
        printf("%d\n",sum[i]);
return 0;
}
