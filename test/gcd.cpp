// File Name: gcd.cpp
// Author: darkdream
// Created Time: 2014年07月31日 星期四 14时27分33秒

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

using namespace std;
int gcd(int a, int b)
{
  return b == 0 ?a:gcd(b,a%b);
}
int main(){
   int n , m; 
   scanf("%d %d",&n,&m);
   printf("%d\n",gcd(n,m));
return 0;
}
