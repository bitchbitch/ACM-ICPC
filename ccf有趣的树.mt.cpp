// File Name: ccf有趣的树.mt.cpp
// Author: darkdream
// Created Time: 2015年03月30日 星期一 19时45分11秒

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
#define M  1000000007
using namespace std;
int c[1005][1005];
int n ; 
int main(){ 
   for(int i = 0;i <= 1000;i ++)
	   c[i][0] = 1; 
   for(int i = 1;i <= 1000 ;i ++)
	   for(int j = 1 ;j <= 1000 ;j ++)
	   {
	      c[i][j] = (c[i-1][j] + c[i-1][j-1])%M;
	   }
   printf("%d\n",c[1000][500]);
return 0;
}
