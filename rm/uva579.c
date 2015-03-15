// File Name: uva579.c
// Author: darkdream
// Created Time: 2013年03月04日 星期一 08时43分54秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  double  a,b,c;
  while(scanf("%lf:%1lf%1lf",&a,&b,&c) !=EOF	)
  {
      b = b*10 +c;
	  a = a*30 +b *0.5;
	  b = b * 6;
	  if(a == 0 && b ==0)
		  break;
	  while (a >= 360)
		  a = a- 360;
      c = fabs(a - b);
		  
		  
      if( c > 180)
		 c = 360 - c;
      printf("%.3lf\n",c);

  
  }
return 0 ;
}
