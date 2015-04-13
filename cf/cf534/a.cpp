// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月13日 星期一 00时00分57秒

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
int n ;
int main(){
	scanf("%d",&n);
	if(n == 1 || n== 2)
	{
		printf("1\n1\n");
		return 0 ; 
	}
	if(n == 3 )
	{
	 printf("2\n1 3\n");
	 return 0 ; 
	}
	if(n== 4)
	{
		printf("4\n3 1 4 2\n");
		return 0 ; 
	}
	if(n% 2== 0)
	{
	  printf("%d\n",n);
      for(int i = 1;i <= n/2 ;i ++)
		  printf("%d %d ",i,i+n/2);
	}else{
	  printf("%d\n",n);
      for(int i = 1;i <= n/2 ;i ++)
		  printf("%d %d ",i,i+n/2+1);
	  printf("%d\n",n/2+1);
	}
return 0;
}
