// File Name: uva10250.c
// Author: darkdream
// Created Time: 2013年03月03日 星期日 21时20分02秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  double x1,y1,x2,y2;
  while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2)!= EOF)
  {
     if(x1 == x2 && y1 == y2)
		 printf("Impossible.\n");
	 else
	 {
	 double x = (x1 + x2)/2 , y = (y1 + y2)/2;
	 printf("%.10lf %.10lf %.10lf %.10lf\n",(y1-y)+x,(x1-x)+y,(y2-y)+x,(x2-x)+y);
	 }
  }
return 0 ;
}
