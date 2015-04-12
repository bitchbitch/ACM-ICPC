// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月12日 星期日 13时35分02秒

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
int tmp ; 
int a[105];
int main(){
   int t; 
   scanf("%d",&t);
   while(t--)
   {
	 int n; 
     scanf("%d",&n);
	 for(int i = 1;i  <= n; i ++)
	 {
	  scanf("%d",&a[i]);
	 }
	 sort(a+1,a+1+n);
	 if(a[n] != a[n-1])
		 printf("%d\n",a[n]);
	 else printf("%d\n",a[1]);
   }
return 0;
}
