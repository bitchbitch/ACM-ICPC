// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年08月12日 星期二 15时03分22秒

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

int main(){
   srand(time(NULL));
   freopen("input","w",stdout);
   printf("10000\n");
   for(int i =1 ;i <= 10000 ;i ++)
   {
        printf("%d %d %d %d %d\n",rand()%10 + 1, rand()%6000,rand()%6000,rand()%6000,rand()%3+1);
   }
return 0;
}
