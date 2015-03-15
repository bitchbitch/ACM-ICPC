// File Name: e.cpp
// Author: darkdream
// Created Time: 2014年07月04日 星期五 19时44分49秒

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
#include<climits>
#include<queue>

using namespace std;
long long  a[10000];
int main(){
	a[1] = 1; 
	a[2] = 2; 
   for(int i = 3;i <= 100 ;i ++)
       a[i] = a[i-1] + a[i-2];
   for(int i =1 ;i <= 10 ;i ++)
	  printf("%10lld %10lld\n",a[i],a[a[i]]);
return 0;
}
