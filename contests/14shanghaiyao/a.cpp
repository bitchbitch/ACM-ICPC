// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年11月15日 星期六 13时30分01秒

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
char str[100];
char str1[100];
int CM(int l ,int r)
{
    for(int i = l;i <= r;i ++)
	{
        if(str[i] >  str1[i])	
		{
		  return 1; 
		}else if(str[i] < str1[i]){
		  return -1;
		}
	}
	return 0; 
}
int main(){
   int n ;
   scanf("%d",&n);
   for(int ca = 1; ca <= n;ca ++)
   {
      scanf("%s %s",str,str1);
      int t = CM(0,0);
      printf("Case %d:",ca);
	  if(t == 0 )
		  printf(" =");
	  else if(t == 1)
		  printf(" >");
	  else printf(" <");
	  t = CM(1,5);
	  if(t == 0 )
		  printf(" =");
	  else if(t == 1)
		  printf(" >");
	  else printf(" <");
	  printf("\n") ;
   }
return 0;
}
