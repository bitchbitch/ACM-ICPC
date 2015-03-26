// File Name: b.cpp
// Author: darkdream
// Created Time: 2015年03月27日 星期五 00时33分41秒

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
#define maxn 200005
using namespace std;
char str[maxn];
int a[maxn];
int cmp(int a, int b)
{
  return a > b; 
}
int n;
void change(int l , int r)
{
    for(int i = l ;i <= r ;i ++)
	{
	    swap(str[i],str[n-i+1]);
	}
}
int main(){
     scanf("%s",&str[1]);
	 int m ; 
	 n = strlen(&str[1]);
	 scanf("%d",&m);
	 for(int i = 1;i <= m; i ++)
		 scanf("%d",&a[i]);
	 sort(a+1,a+1+m,cmp);
	 int last = n/2; 
	 for(int i = 1; i <= m;i ++)
	 {
	      if((m - i) % 2 == 0) 
		  {
		    change(a[i],last);
		  }
		  last = a[i] - 1; 
	 }
	 puts(&str[1]);
return 0;
}
