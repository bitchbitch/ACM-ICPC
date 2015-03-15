// File Name: a.cpp
// Author: darkdream
// Created Time: 2013年11月24日 星期日 23时23分15秒

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

int min(int a, int b)
{
  if(a > b)
	  return b ; 
  else return a; 
}
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
  int n  ; 
  scanf("%d",&n);
  int a, b,  c, d; 
  int minum = 1000000000;
  int mina, minb;
  int num = 0;
  for(int i =1 ;i<= 4;i ++)
  {
	scanf("%d %d %d %d",&a,&b,&c,&d);
    int k =  min(a,b) + min(c,d);
	if(k <  minum && k <= n)
	{
	   minum = k ;
	   mina = min(a,b); 
	   minb = min(c,d);
	   num = i ;
	   break;
	}
  }
  if(num)
	  printf("%d %d %d\n",num,mina,n-mina);
  else
	  printf("-1\n");

return 0;
}
