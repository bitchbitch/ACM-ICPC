// File Name: c.cpp
// Author: cijianzy
// Created Time: 2015年05月23日 星期六 00时46分54秒

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
map<LL,int> mp; 
LL p[12];
int isok(int x, int y)
{
    if(x ==0 )
        return 1; 
    if(y == 0 )
        return 0;
    return x > y; 
}
int main(){
    int n; 
    int k1,k2; 
    p[0] = 1; 
    for(int i = 1;i <= 10 ;i ++)
        p[i] = p[i-1] * 10 ; 
    scanf("%d",&n); 
    scanf("%d",&k1);
    LL x = 0 ;
    LL y = 0 ;
    LL tmp ; 
    for(int i = 1;i <= k1;i ++){
        scanf("%I64d",&tmp);
        x = x * 10 + (tmp) % 10 ; 
    }
    scanf("%d",&k2);
    for(int i = 1;i <= k2;i ++){
        scanf("%I64d",&tmp);
        y = y * 10 + (tmp) % 10 ; 
    }
    int step = 0 ; 
    while(1){
        if(k1 == 0 ){
            printf("%d 2\n",step);
            return 0 ;
        }
        if(k2 == 0 ){
            printf("%d 1\n",step);
            return 0 ;
        }
        if(mp[x*p[k2]+y] != 1){
            mp[x*p[k2] + y] = 1; 
        }else{
            puts("-1");
            return 0 ; 
        }
        LL tmp1 = x /p[k1-1];
        x %= p[k1-1]; 
        LL tmp2 = y / p[k2-1];
        y %= p[k2-1]; 
        //printf("%I64d %I64d\n",tmp1,tmp2);
        
        if(isok(tmp1,tmp2)){
            x = x * 10 + tmp2; 
            x = x * 10 + tmp1;
            k1 ++ ; 
            k2 -- ; 
        }else{
            y = y * 10 + tmp1; 
            y = y * 10 + tmp2;
            k2 ++ ; 
            k1 -- ; 
        }
        //printf("%I64d:%d\n%I64d:%d\n",x,k1,y,k2);
        step ++ ; 
    }
return 0;
}
