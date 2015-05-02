// File Name: memcpy.cpp
// Author: darkdream
// Created Time: 2015年05月02日 星期六 20时31分37秒

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
int a[100];
int b[100];
void *Memcpy(void *dst,const void *src,size_t size){
	char *psrc;
	char *pdst;
	if(NULL == dst || NULL == src){
		return NULL;
	}
	if((src < dst) && (char *)src + size > (char*)dst ){
		psrc = (char *)src + size -1 ; 
		pdst = (char *)dst + size -1; 
		while(size --){
			*pdst -- = *psrc --;
		}
	}else{
		psrc = (char *) src; 
		pdst = (char *) dst;
		while(size --){
			*pdst ++ = *psrc ++ ; 
		}
	}
	return dst; 	
}
int main(){
	
return 0;
}
