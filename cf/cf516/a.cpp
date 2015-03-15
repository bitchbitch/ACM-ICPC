// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年02月18日 星期三 00时25分01秒

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
int a[20];
int b[10];
int k[10];
void solve(int x)
{
	if(x == 1 || x == 0  )
		return;
	if(x == 3 || x == 5 || x == 7)
	{
		k[x] ++ ;
	     return ; 
	}
	int tmp  = x ; 
    while(tmp % 2 == 0 || tmp % 3 == 0 )
	{
	   if(tmp %2 == 0 )
	   {
	      b[2] ++ ;
		  tmp = tmp /2;
	   }else{
	       b[3] ++ ;
		   tmp = tmp /3;
	   }
	}
	solve(x-1);
}
int main(){
  int n ; 
  scanf("%d",&n);
  for(int i = 1;i <= n;i ++)
  {
    scanf("%1d",&a[i]);
  }
  for(int i = 1;i <= n;i ++)
  {
    solve(a[i]); 
  }
  for(int i = 9 ;i >= 2;i --)
  {
    if(k[i])
	{
	  for(int j = 1;j <= k[i];j ++)
		  printf("%d",i);
	}
  }
  for(int i = 1;i <= b[3];i ++)
	  printf("3");
  for(int i = 1;i <= b[2]-b[3];i ++)
	  printf("2");
return 0;
}
