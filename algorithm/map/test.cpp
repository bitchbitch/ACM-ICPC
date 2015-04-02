// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年11月09日 星期日 18时18分53秒

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
map<int,int>  hehe;
int main(){
   map<int,int>::iterator iter;
   for(int i = 1;i <= 1000000;i ++)
	  hehe[i] = 1; 
   int x;
   int be = clock();
   int t = 10 ; 
   while(t--)
   for(iter = hehe.begin(); iter != hehe.end(); iter ++)
   {
       x = iter->second; 
   }
   int en = clock();
   printf("%lf\n",(en - be)*1.0/CLOCKS_PER_SEC);
   t = 10 ; 
   while(t--)
   for(int i= 1; i != 1000001; i ++)
   {
       x = i; 
   }
   be = clock();
   printf("%lf\n",(be - en)*1.0/CLOCKS_PER_SEC);
return 0;
}
