// File Name: d.cpp
// Author: cijianzy
// Created Time: 2015年05月23日 星期六 01时24分00秒

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
#define maxn 5000005
using namespace std;
LL dp[maxn];
LL num[maxn];
bool hs[maxn];
void sai(){
    int t = sqrt(maxn);
    for(int i = 2;i < t;i ++){
        if(hs[i] == 0 ){
            int k = i * i ;
            while(k < maxn ){
                hs[k] = 1; 
                dp[k] = k /i ;
                k += i ; 
            }
        }
    } 
    for(int i = 2; i < maxn;i ++)
    {
        num[i] ++;
        num[i] += num[dp[i]];
    }
    //for(int i = 1;i <= 20 ;i ++)
      //  printf("%I64d ",num[i]);
    for(int i = 1;i < maxn;i ++)
        num[i] += num[i-1];

}
int main(){
    int t; 
    sai();
    scanf("%d",&t);
    int a,b; 
    while(t--){ 
        scanf("%d %d",&a,&b);
        printf("%I64d\n",num[a]-num[b]);
    }
return 0;
}
