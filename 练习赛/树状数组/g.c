// File Name: g.c
// Author: darkdream
// Created Time: 2013年03月23日 星期六 09时15分32秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int N[1005],M[1005] , n , m ;
int lowbit(int x)
{
 return x&(-x);
}
void updaten(int x);
{
   while(x <= n )
   {
      N[x]++;
	  x = x+ lowbit(x);
   }
}
void updatem(int x);
{
   while(x <= n )
   {
      M[x]++;
	  x = x+ lowbit(x);
   }
}
int sumn(int x)
{
   int res = 0;
   while(x >= 1)
	{
	  res += N[x];
	  x -= lowbit(x);
	}
   return res;
}
int summ(int x)
{
   int res = 0;
   while(x >= 1)
	{
	  res += M[x];
	  x -= lowbit(x);
	}
   return res;
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int t;
	scanf("%d",&t);
	while(t--)
	{
	  int n , m , k ;
	  scanf("%d %d %d",&n,&m,&k);
	  while(k--)
	  {
	    int a, b;
		scanf("%d",&a)
	  }
	}
return 0 ;
}
