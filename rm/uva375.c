// File Name: uva375.c
// Author: darkdream
// Created Time: 2013年03月04日 星期一 08时10分35秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define pi  acos(-1.0)

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
    int n ;
     scanf("%d",&n);
	 while(n--)
	 {
	    double b,h ,co ,si,hy ,ta , r , sum = 0 , k;
		scanf("%lf %lf",&b,&h);
		hy = hypot(b/2,h);
	    co = b/2/hy;
		si = h/hy;
        ta = si/(1+co);
        r = b/2*ta;
		k = (h-2*r)/h;

	    while(r >= 0.000001)
		{
		   sum += 2*r*pi;
		   b = b * k;
		   h = h * k;
		   r = b / 2*ta;
		}
		
	  printf("%13.6lf\n",sum);
	  if(n!=0)
		  printf("\n");

	 }
	return 0 ;
}
