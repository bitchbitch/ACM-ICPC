// File Name: memcpy.1.cpp
// Author: cijianzy
// Created Time: 2015年05月03日 星期日 20时54分10秒

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
#include<assert.h>
#define LL long long

using namespace std;

void *Memcpy(void *dst,const void *src,size_t size){
        //assert(dst != NULL);
        //assert(src != NULL);
        char * psrc;
        char * pdst;
        if(src < dst && (char *)src + size > (char *)dst){
            psrc = (char *)src + size -1;
            pdst = (char *)dst + size -1;
            while(size --){
                *pdst = *psrc;
                pdst -- ;
                psrc -- ; 
            }
        }else{
            psrc = (char *)src;
            pdst = (char *)dst;
            while(size -- ){
                *pdst = *psrc;
                pdst ++ ; 
                psrc ++ ;
            }
        }
        return dst;
}
int a[100];
int b[100];
int main(){

    for(int i = 0 ;i < 99 ;i ++)
        b[i] = i ; 
    Memcpy((char *)a,(char *)b,sizeof(b));
    for(int i = 0 ;i < 99 ;i ++)
        printf("%d ",a[i]);


return 0;
}
