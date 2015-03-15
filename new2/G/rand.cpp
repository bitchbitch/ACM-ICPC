// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年11月27日 星期四 20时16分49秒

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
int hs[10004];
int R(int l ,int r)
{
   int k = (r-l+1);
   return rand()%k+l;
}
int main(){
    freopen("in","w",stdout);
	srand(time(NULL));
	int T = 100 ;
	while(T--)
	{
       int n = R(1,100);
	   printf("%d\n",n);
	   memset(hs,0,sizeof(hs));
	   for(int i = 1;i <= n;i++)
	   {
	       int len = R(1,15);
		   for(int j = 1;j <= len; j++)
			   printf("%c",R(0,25) + 'a');
		   int x; 
		   while(hs[x = R(1,10000)] == 1 )
		   { 
		   }
		   hs[x] = 1; 
		   printf(" %d\n",x);
	   }
	}
return 0;
}
