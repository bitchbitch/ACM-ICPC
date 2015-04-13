// File Name: rand.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 15时13分53秒

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
int a[10005];
int main(){
	  freopen("in","w",stdout);
      printf("%d\n",10000);
	  for(int ca = 1;ca <= 10000;ca ++)
	  {
	    int n = rand() % 5+ 1; 
		for (int i= 1;i <= n;i ++)
		{
		  a[i] = rand() % 10+ 1; 
		}
		sort(a+1,a+1+n);
		int ok = 1; 
		for(int i = 2;i <= n;i ++)
			if(a[i] == a[i-1])
			{
			  ok = 0 ; 
			  break;
			}
		if(ok)
		{
		  printf("%d\n",n);
		  for(int i = 1;i <= n;i ++)
			  printf("%d ",a[i]);
		  printf("\n");
		}else ca -- ; ; 
	  }

return 0;
}
