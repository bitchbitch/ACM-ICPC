// File Name: 340d.cpp
// Author: darkdream
// Created Time: 2014年08月03日 星期日 12时31分24秒

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
#define maxn 100005
using namespace std;
int st[100005];
int num = 0 ; 
int a[100005];
int n ;
void solve(int x)
{
   int l =1 ,r = num;
   while(l <= r)
   {
      int m = (l + r)/2;
      if(st[m] <= x)
	  {
	    l = m +1; 
	  }else {
	    r = m - 1;
	  }
   }
   if(l == num + 1)
   {
     num ++ ;
	 st[num] = x; 
   }else{
     st[l] = x; 
   }
}
int main(){
   scanf("%d",&n);
   for(int i = 1;i <= n;i ++)
   {	
	  scanf("%d",&a[i]);
      solve(a[i])  ; 
   }
   printf("%d\n",num);
   return 0;
}
