// File Name: b.c
// Author: darkdream
// Created Time: 2014年04月12日 星期六 22时20分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
long double a[1000005];
long double temp[1000005];
int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("output2.txt","w",stdout);
   int t; 
   scanf("%d",&t);
   for(int Case = 1; Case <=t ; Case ++)
   {
      long double c ,f , x; 
	  scanf("%Lf %Lf %Lf",&c,&f,&x);
	  a[1] = c/2.0;
	  temp[1] = x/2.0;
	  int ans = 0 ; 
	  printf("Case #%d: ",Case);
	  for(int i = 2;i <= 1000000;i ++)
	  {
	       a[i] = a[i-1] + c/(2 + (i-1) *f);
		   temp[i] = a[i] + x/(2 + i*f);
		   if(fabs(temp[i]-temp[i-1]) < 1e-8 || temp[i]> temp[i-1])
		   {
		     ans = i -1 ;
			 break;
		   }
	  }
	  printf("%.7Lf\n",temp[ans]);
   }
   return 0 ;
}
