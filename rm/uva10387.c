// File Name: uva10387.c
// Author: darkdream
// Created Time: 2013年03月03日 星期日 22时01分23秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define pi 3.141592657
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   double  a, b, s, m, n;
   while(scanf("%lf %lf %lf %lf %lf",&a,&b,&s,&m,&n) != EOF)
   {
     if(a == 0)
		 break;

	 printf("%.2lf %.2lf\n",atan(b*n/m/a)*180/pi,hypot(b*n/m,a)*m/s);
   }

return 0 ;
}
