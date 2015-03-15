// File Name: uva10014.c
// Author: darkdream
// Created Time: 2013年02月19日 星期二 23时19分17秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double c[4000];
int main(){
	int n , p ;
	scanf("%d",&n);
	for (p =1; p <= n; p++)
	{
	 int  t ,i ; 
	 double a0 ,ak ,sum = 0 ,temp;
	 scanf("%d",&t);
	 scanf("%lf %lf",&a0,&ak);
	 sum  =  t*a0 + ak ;
     double sum1 = 0 ;
	 for (i = 1 ; i <= t ; i++)
	 {	 scanf("%lf",&temp);
         sum1 += temp;
		 sum -= 2*sum1;
	 }
     if(p != 1 )
		 printf("\n");	 
	 printf("%.2lf\n",sum /(t+1));
	}
return 0 ;
}
