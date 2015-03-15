// File Name: 1010.cpp
// Author: darkdream
// Created Time: 2014年07月29日 星期二 12时03分51秒

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
int n , seed;
int main(){
	while(scanf("%d %d",&n,&seed) != EOF)
	{
	  int x = seed;   
	  for (int i = 2; i <= n;i ++)
	  {
	     x= x * 907 % 2333333;
		 int t = x; 
		 for(int j = max(1,i-5);j <= i -1 ;j ++)
		 {
		      
		 }
	  }
	}
return 0;
}
