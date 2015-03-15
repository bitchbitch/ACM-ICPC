// File Name: 166e.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 10时12分28秒

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
int a[10000002][4];
#define M 1000000007
int main(){
  int n; 
  scanf("%d",&n);
  a[0][3] = 1;
  LL t = 1;
  for(int i =1;i <= n;i ++)
  {
     LL k = 0 ;
     for(int j = 0 ;j <= 3;j ++ )
	 {
	    a[i][j] = (t-a[i-1][j]) %  M;
		k += a[i][j];
	 }
	 t = k ; 
  }
  printf("%d\n",a[n][3]);
return 0;
}
