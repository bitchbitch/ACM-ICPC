// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年12月14日 星期日 21时59分26秒

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
  freopen("in.txt","w",stdout);
  int T = 100 ;
  srand(time(NULL));
  while(T--)
  {
    int n , m; 
	n = rand()% 100 + 1 ;
	m = rand()%100 + 1;
	printf("%d %d\n",n,m);
	for(int i = 1;i <= n;i ++)
	{
	  for(int i = 1;i<= m ;i ++)
		{
		    if(rand()%4 < 1)
				printf("*");
			else printf(".");
		}
	  printf("\n");
	}
	
  }
return 0;
}
