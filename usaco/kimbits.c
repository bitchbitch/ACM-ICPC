// File Name: kimbits.c
// Author: darkdream
// Created Time: 2014年02月28日 星期五 19时02分25秒
/*
ID: dream.y1
PROG: kimbits
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int hs[40];
int map[33][33];
void init()
{
	memset(map,0,sizeof(map));
	map[0][0] =1 ; 
    for(int i = 1;i <= 31 ;i ++)
	{
	  map[i][0] = 1; 
	  map[i][i] = 1; 
	}
	for(int i = 2;i <= 31;i ++)
		for(int j = 1;j < i ;j ++)
		{
		  map[i][j] = map[i-1][j] + map[i-1][j-1];
		}
}
void solve(long long n , long long m , long long k )
{
	long long sum[40];
	memset(sum,0,sizeof(sum));
    for(int i = 0;i <= n;i ++)
	{
	   sum[i] = 0; 
	   for(int  j = 0;j <= m;j ++)
	   {
         sum[i] += map[i][j];
	   }
	   if(sum[i] >= k )
	   {

	       hs[i] = 1;
		   if(i == 1)
			   return ;
		   solve(i-1,m-1,k-sum[i-1]);
		   break;
	   }
	}
}
int main(){
   freopen("kimbits.in","r",stdin);
   freopen("kimbits.out","w",stdout);
	long long n , m , k ; 
   scanf("%lld %lld %lld",&n ,&m,&k);
   init();
   solve(n,m,k);
   for(int i = n ;i >= 1;i --)
	   if(hs[i])
		   printf("1");
	   else printf("0");
   printf("\n");
   return 0 ;
}
