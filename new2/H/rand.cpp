// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年11月27日 星期四 21时00分05秒

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
int R(int l ,int r)
{
   int k = (r-l+1);
   return rand()%k + l;
}
int main(){
   freopen("in","w",stdout);
   srand(time(NULL));
   printf("1000\n");
   int T = 1000;
   while(T--)
   {
     int n = R(1,50);
     for(int i = 1;i <= n;i++)
	 {
	    
		int len = R(1,10);
		for(int j = 1;j <= len;j++)
		{
		   int t= R(1,7);
		   if(t == 1)
		   {
			   printf("WLA");
			   j += 2;
		   }
		   else printf("%c",R(0,25)+'A');
		}
	    if(i != n)
			printf(" ");
	 }
	 printf("\n");
   
   }
return 0;
}
