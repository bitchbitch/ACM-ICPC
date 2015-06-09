// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 16时54分04秒

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
int d, n;
int k ; 
int carry;
int p[4] ={1,10,100,1000};
int ans[10005];
void solve(int x,int y ,int z){
    carry = 0 ;  
    for(int i = 1;i <= y;i ++){
        carry += i * x;  
        ans[i] = carry % p[z];
        carry = carry /p[z];
    }
}
int x[50];
void print(int k ){
    printf("%d.",carry);
    memset(x,0,sizeof(x));
    int t = 0 ;
    if(k == 2 ){
        for(int i = n; i >= 1; i--){
            if(ans[i] < 10){
                t ++ ;
                x[t] = 0 ; 
                t ++ ; 
                x[t] = ans[i]; 
            }else{
                t ++ ; 
                x[t] = ans[i]/10;
                t ++ ;
                x[t] = ans[i] %10 ; 
            }
            if(t >= 20)
                break;
        } 
    }else if(k == 3 ){
        for(int i = n; i >= 1; i--){
            if(ans[i] < 10){
                t ++ ;
                x[t] = 0 ; 
                t ++ ;
                x[t] = 0 ; 
                t ++ ; 
                x[t] = ans[i]; 
            }else if(ans[i] < 100){
                t++;
                x[t] = 0 ; 
                t ++ ; 
                x[t] = ans[i]/10;
                t ++ ;
                x[t] = ans[i] %10 ; 
            }else{
                t ++ ;
                x[t] = ans[i]/100;
                t ++ ;
                x[t] = (ans[i]%100)/10;
                t++;
                x[t] = ans[i] % 10;
            }
            if(t >= 20)
                break;
        } 
        
    }else{
        for(int i = n;i >= 1;i --)
        {
            t ++ ;
            x[t] = ans[i];
            if(t >= 20)
                break;
         }
    }
    for(int i = 1;i <= 20 ;i ++)
        printf("%d",x[i]);
    printf("\n");
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    time_t be,en;
    be = clock();
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&d,&n); 
        for(int i = 1;i <= 3;i ++){
            if(p[i] > d){
                solve(d,n,i); 
                print(i);
                break;
            }
        }
    }
    en = clock();
    printf("%lf\n",(en-be)*1.0/CLOCKS_PER_SEC);
return 0;
}
