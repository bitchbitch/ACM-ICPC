// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年09月12日 星期五 08时16分42秒

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
int a[50000][26];
int main(){
  memset(a,0,sizeof(a));
  int x, y ; 
  while(scanf("%d %d",&x,&y) != EOF)
  {
    printf("%d\n",x+y);
  }
return 0;
}
