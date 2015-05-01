// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年05月01日 星期五 11时03分28秒

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

unsigned int BKDRHash(char *str)
 {
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
 }

unsigned int BKDRHash1(char *str)
 {
    unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
    return hash;
 }
char str[1000];
int main(){
  while(scanf("%s",str) != EOF){
	printf("%d\n",BKDRHash(str));
	printf("%d\n",BKDRHash1(str));
  } 
return 0;
}
