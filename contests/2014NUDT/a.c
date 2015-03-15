// File Name: a.c
// Author: darkdream
// Created Time: 2014年04月27日 星期日 12时33分41秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   double a,b,c,d;
   while(scanf("%lf %lf %lf %lf",&a,&b,&c,&d) != EOF)
   {
        a = 3*a ;
		b = 2*b ;
	    if(b*b - 4*a *c  + 1e-8 < 0 ||  fabs(b*b-4*a*c)  < 1e-8 )
		{
		  printf("(-inf, +inf)+\n");
		}else {
		  double x1,x2;
		  x1 = (-b - sqrt(b*b - 4*a*c))/(2*a);
		  x2 = (-b + sqrt(b*b - 4*a*c))/(2*a);
		  printf("(-inf, %.4lf)+ (%.4lf, %.4lf)- (%.4lf, +inf)+\n",x1,x1,x2,x2);
		}
   }
return 0 ;
}
