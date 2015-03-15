// File Name: b.cpp
// Author: darkdream
// Created Time: 2014年07月24日 星期四 23时40分41秒

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
int a[100005];
int b[100005];
int main(){
  int n ;
  scanf("%d",&n);
  int ok = 0 ;
  for(int i = 1;i <= n;i ++)
  {
    scanf("%d",&a[i]);
	if(a[i] < a[i-1])
	{
		b[i] = b[i-1]+1;
		b[i-1] = 0;
	}
  }
  a[n+1] = 1e9+7;
  int sum = 0 ; 
  int site = 0 ;
  for(int i =1 ;i <= n;i ++)
  {
     if(b[i])
	 {
		 sum ++ ;
	     site = i; 
	 }
  }

  if(sum >= 2)
	 printf("no\n");   
  if(sum == 0 )
	  printf("yes\n1 1\n");
  if(sum == 1 )
  {
	  if(a[site] > a[site -b[site]-1] && a[site-b[site]] < a[site+1])
	    printf("yes\n%d %d\n",site-b[site],site);
	  else printf("no\n");
  }
return 0;
}
