// File Name: a.c
// Author: darkdream
// Created Time: 2013年02月28日 星期四 23时14分05秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  //   freopen("input.txt","r",stdin);
  //   freopen("output.txt","w",stdout); 
   int a[200];
   int n ;
   scanf("%d",&n);
   for(int i  = 1; i<= n; i++)
   {
     scanf("%d",&a[i]);
   }
	int s, t ,tsum = 0 , sum =0;
	scanf("%d %d",&s,&t);
	if( s >t )
	{
	  int temp = s;
	  s = t;
	  t = temp;
	}
	for(int k = s; k <t ;  k++)
		sum += a[k];
	for(int k = t; k != s  ; k++)
	{
	   tsum += a[k];
	   if(k == n)
		   k = 0;
	}
	if(tsum  <sum)
		sum = tsum;
	printf("%d",sum);
 return 0 ;
}
