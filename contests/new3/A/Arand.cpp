// File Name: Arand.cpp
// Author: darkdream
// Created Time: 2014年12月08日 星期一 18时40分17秒

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
int R(int l , int r)
{
   int t  = rand()%(r-l +1);
   return t + l;
}
int main(){
  srand(time(NULL));
  freopen("A.in","w",stdout);
  printf("100000\n");
  for(int i = 1;i<= 100000;i ++)
  {
	 if(R(0,1))
	 {
		 for(int j = 1;j <= 4 ;j ++)
		 {
			 printf("%d %d\n",R(-20,20),R(-20,20));
		 }
	 }else{
	    int x = R(-10,10);
		int y = R(-10,10);
		int r = R(0,10);
		printf("%d %d\n",x,y);
		for(int i = 1;i <= 3;i ++)
		{
		  printf("%d %d",x + R(-1,1)*r,y + R(-1,1) * r);
		}
	 }
  }
  return 0;
}
