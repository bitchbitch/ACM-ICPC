/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-08-01 23:54
 * Filename : b.cpp
 * Description :
 * *********************************************************/
// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年08月01日 星期五 23时41分55秒

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
int a[200005];
int main(){
  int n ;
  scanf("%d",&n);
  int ok = 0 ;
  a[0] = 0 ;
  int be = 0 ; 
  for(int i =1 ;i <= n;i ++)
  {
     scanf("%d",&a[i]);
	 if(a[i] < a[i-1] && !ok)
	 {
	   ok = 1;
	   be = i ; 
	 }
  }
  if(ok == 0 )
  {
     printf("0\n");
	 return 0;
  }
  for(int i = 1 ;i <= n;i ++)
	  a[i+n] = a[i];
  ok =0 ;
  for(int i = be +1;i<= be +n -1;i ++)
  {
    if(a[i] < a[i-1])
	{
	    ok = 1 ;
		break;
	}
  }
  if(ok  == 0 )
	  printf("%d\n",n-be + 1);
  else printf("-1\n");
  return 0;
}
