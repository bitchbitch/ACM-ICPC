// File Name: 加油站.cpp
// Author: darkdream
// Created Time: 2013年11月26日 星期二 20时01分30秒

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

int c[200005],v[200005];
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
    int t; 
	scanf("%d",&t);
	while(t--)
	{
	   int n ; 
	   scanf("%d",&n);
	   int sumc = 0 ; 
	   int sumv = 0 ; 
	   for(int i = 1;i <= n;i ++)
	   {
	      scanf("%d %d",&v[i],&c[i]);
		  sumc += c[i];
		  sumv += v[i];
	   }
	   if(sumv < sumc)
	   {
		   printf("-1\n");
		   continue;
	   }
	   for(int i = 1;i <= n - 1;i ++)
	   {
		 v[i] = v[i] - c[i];  
	   }
	   for(int i =1 ;i<= n;i ++)
	   {
	     v[i+n] = v[i];
	   }
	   /*for(int i = 1;i <= n;i ++)
		   printf("%d ",v[i]);
	   printf("\n");*/
       int be = 1 ;
	   int sum = 0 ;
	   for(int i = 1;i <= 2*n ;i ++)
	   {
	       if(sum < 0 )
		   {
		     sum = 0 ; 
			 if(i - be >= n)
				 break;
			 be = i ;
		   }
		   sum += v[i];
	   }
	   printf("%d\n",(be-1) % n);

	}

return 0;
}
