// File Name: test.cpp
// Author: darkdream
// Created Time: 2015年03月26日 星期四 22时37分15秒

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
#define maxn 105
using namespace std;
int mp[maxn][maxn];
void floyd()
{
	  for(int i=  1;i <= 100 ;i ++)
		  for(int j= 1;j <= 100 ;j ++)
  for(int k = 1;k <= 100 ;k ++ )
		  {
		    mp[i][j] = mp[i][k] +mp[k][j];
		  }
}
int main(){
	 clock_t be,en;
	 be = clock();
     floyd();
	 en = clock();
	 printf("%ld",en - be);
return 0;
}
