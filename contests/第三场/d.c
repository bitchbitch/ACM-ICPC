// File Name: d.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 20时38分57秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   double n ;
   while(scanf("%lf",&n) != EOF)
   {
     if(n == 0.0)
		 break;
	 double r1 = sqrt(n*n/3.0);
	 double r2 = sqrt(r1*r1 + n*n/3.0);
	 printf("%.3lf %.3lf\n",r1,r2);
   }
return 0 ;
}
