// File Name: uva113.c
// Author: darkdream
// Created Time: 2013年01月30日 星期三 08时41分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
     int n ;
	 double p ;
      while(scanf("%d %lf",&n, &p) != EOF)
	  {
	       printf("%.0f\n",floor(pow(p,1.0/n)+0.5));
	  }
return 0 ;
}
