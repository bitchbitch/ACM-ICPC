// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年08月19日 星期二 15时20分58秒

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
   freopen("input.txt","w",stdout);
   for(int i = 1;i <= 10000;i ++)
   {
     int n = rand()%10000 + 1; 
	 printf("%d\n",n);
	 for(int i = 1;i <= n;i ++)
		 printf("%d ",rand()%100+1);
	 printf("\n");
   }
   printf("0\n");
return 0;
}
