// File Name: test.cpp
// Author: darkdream
// Created Time: 2014年08月01日 星期五 10时47分22秒

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

int main(){
	freopen("input.txt","w",stdout);
    printf("100\n");
	srand(time(NULL));
	for(int i = 1;i <= 100;i ++)
	{
        int n  = rand()%9+1;
		printf("%d\n",n);
		for(int i =1;i <= n ;i ++)
		{
		   printf("%d ",rand()%101);
		}
		printf("\n");
		int m = rand()%20+1;
		printf("%d\n",m);
		for(int i =1;i <= m ;i ++)
		{
		   int l ,r; 
		   l = rand()%n+ 1;
		   r = rand()%n+1;
		   if(l > r )
		   {
		     int t = r ; 
			 r = l ; 
			 l  = t;
		   }
		   printf("%d %d %d %d\n",rand()%2+1,l,r,rand()%101);
		}

	}
return 0;
}
