// File Name: c.cpp
// Author: darkdream
// Created Time: 2013年11月25日 星期一 00时43分22秒

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

int a[1000];
int b[1000];
int c[20000];
int d[20000];
int main(){
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
   memset(c,-1,sizeof(c));
   memset(b,-1,sizeof(b));
   memset(d,-1,sizeof(d));
   memset(a,-1,sizeof(a));
   int n , k ;
   scanf("%d %d",&n,&k);
   for(int i = 1;i <= n;i ++)
   {
      scanf("%d",&a[i]);
   }
   int ans =0 ;
   c[0] = 0 ;
   d[0] = 0 ;
   for(int i= 1;i <= n;i ++)
   {
     scanf("%d",&b[i]);
	 b[i]  = b[i] *k -a[i];
	 //printf("%d\n",b[i]);
	 if(b[i] < 0)
	 {
		b[i] = -b[i];
	    for(int j = 10000;j>= 0;j --) 
		{
		  if(c[j] != -1 && j+b[i] <= 10000)
		  {
			if(c[j] + a[i] > c[j+b[i]])
		     c[j+b[i]] = c[j] + a[i];
		  }
		}
	 }else if(b[i] > 0)
	 {
	    for(int j = 10000;j >= 0;j --) 
		{
		  if(d[j] != -1 && j+b[i] <= 10000)
		  {
			if(d[j] + a[i] > d[j+b[i]])
		     d[j+b[i]] = d[j] + a[i];
		  }
		}
	 }else  ans+= a[i];

   }
   //for(int i = 1;i <= 20 ;i ++)
	 //  printf("%d %d\n",c[i],d[i]);
   int max = 0 ;
   for(int i =1 ;i <= 10000 ;i ++)
   {
     if(c[i] != -1 && d[i] != -1)
	 {
	     if(c[i] +d[i] > max)
			 max = c[i] + d[i];
	 }
   }
   if(ans+max != 0)
   printf("%d\n",ans+max);
  else printf("-1\n");

return 0;
}
