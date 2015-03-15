// File Name: d.cpp
// Author: darkdream
// Created Time: 2013年05月20日 星期一 21时56分38秒

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

int a[100004]; 
int main(){
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n;
   long long sum = 0;
   while(scanf("%d",&n) != EOF)
   {
	   sum = 0 ;
       for(int i = 1; i<= n;i ++)
	   { 
		   scanf("%d",&a[i]);
	       sum+= a[i];
	   }
	   int ok = 0 ,sumtemp = 0 ;;
	   for(int i = 1;i <= n;i ++)
	   {
	     if(abs(a[i]) <= sum)
		 { ok = 1;
		  sumtemp++;
		 }
	   }
	   if(ok == 0)
		   printf("Endless\n");
	   else
		   printf("%d\n",1+(n)*(n+1)/2);
   }
return 0;
}
