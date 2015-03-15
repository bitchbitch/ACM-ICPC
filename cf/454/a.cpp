// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年08月01日 星期五 23时27分55秒

#include<vector>
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
int a[104][104];
int main(){
  int n;
  memset(a,0,sizeof(a));
  scanf("%d",&n);
  int t = n/2+1;
  int be = t;
  for(int i = 1;i <= n;i ++)
  {
      if(i <= t)
	  {
	     for(int j = be ;j <= be + i*2-2 ;j ++)
			 a[i][j] = 1;
		 be --;
	  }else{
		 if(i == t + 1)
			 be = 2;
		 else 
		     be ++ ; 
	     for(int j = be;j <= be +(n-i+1)*2-2;j ++)
			 a[i][j] = 1;
	  }
  }
   for(int i =1 ;i <= n;i ++)
   {
	for(int j = 1;j <= n;j++)
	{
     if(a[i][j])
		 printf("D");
	 else printf("*");
	}
	printf("\n");
   }
return 0;
}
