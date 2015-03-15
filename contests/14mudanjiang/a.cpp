// File Name: a.cpp
// Author: darkdream
// Created Time: 2014年09月07日 星期日 11时57分35秒

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

int main(){
    int t;
	scanf("%d",&t);
	while(t--)
	{
	  int n; 
	  scanf("%d",&n);
	  int a[100];
	  for(int i = 1;i <= n;i ++)
	  {
	    scanf("%d",&a[i]);
	  }
	  int sum = 0 ; 
	  for(int i = 2;i < n;i ++)
	  {
	    if(a[i] > a[i-1] && a[i] > a[i+1])
			sum ++ ; 
	  }
	  printf("%d\n",sum);
	}
	return 0;
}
