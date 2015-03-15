/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-11-01 18:55
 * Filename : rand.cpp
 * Description :
 * *********************************************************/
// File Name: rand.cpp
// Author: darkdream
// Created Time: 2014年10月05日 星期日 17时29分38秒

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
#define INF 1000000000
using namespace std;

int main(){
   freopen("out","w",stdout);
   srand(time(NULL));
   printf("100\n");
  for(int i = 1;i <=100 ;i ++)
  {
      int n = rand()%(16) + 2;
	  int m = rand()%(16);
	  printf("%d\n",n);
	/*  for(int i = 1;i <= n ;i ++)
        printf("%d ",rand()%1001);
	  printf("\n");*/
     for(int i = 1;i <= n-1;i ++)
     {
        printf("%d %d %d\n",rand()%i+1,i+1,rand()%10000+1);
     }
     for(int i = 1;i <= m;i ++)
	 {
	   int t = rand()% 3;
	   if(t == 0)
		   printf("CHANGE %d %d\n",rand()%(n-1)+1,rand());
	   else if(t == 1) 
		   printf("QUERY %d %d\n",rand()%n+1,rand()%n + 1);
	   else printf("NEGATE %d %d\n",rand()%n + 1, rand()%n + 1);
	 }
	 printf("DONE\n");
  }
return 0;
}
