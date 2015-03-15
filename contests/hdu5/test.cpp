// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年08月05日 星期二 14时29分42秒

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
	freopen("input.txt","w",stdout);
    srand(time(NULL));
	int p = 10000;
	while(p--)
	{
	int n = rand()%20 + 1;
	  for(int i =1 ;i <= n;i ++)
	  {
            int t = rand()%3;
			if(t == 0 )
				printf("(");
			else if(t == 1)
				printf(")");
			else printf("?");
	  }
	  printf("\n");
	}
return 0;
}
