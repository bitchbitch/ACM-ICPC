// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月12日 星期五 09时05分08秒

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
  int n ;
  while(scanf("%d",&n) != EOF,n)
  {
      int t = 0 ; 
	  while(n != 1)
	  {
	    if(n% 2 ==0 )
			n /= 2 ; 
		else n = n * 3 + 1;
	   t++;
	  }
	  printf("%d\n",t+1);
  }
return 0;
}
