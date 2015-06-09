// File Name: solve.cpp
// Author: cijianzy
// Created Time: 2015年06月06日 星期六 22时52分15秒

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
int T; 
char str[1005];
int k ; 
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    time_t be,en; 
    be = clock();
    scanf("%d",&T);
    int len  =0 ; 
    while(T--){
        scanf("%s %d",str,&k);
        len = strlen(str);
        int t = 0;
        int tmp = 0 ; 
        for(int i = 1 ;i < len; i ++){
            while(t != -1 && str[i] < str[t]){
                if(tmp == k )
                    break;
                t -- ;
                tmp ++ ; 
            }
            t ++ ; 
            str[t] = str[i];
        }
        for(int i = 0 ;i < len - k; i ++)
            printf("%c",str[i]);
        printf("\n");
    }
    en = clock();
    //printf("%lf\n",(en-be)*1.0/CLOCKS_PER_SEC);
return 0;
}
