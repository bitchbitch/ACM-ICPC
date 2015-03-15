// File Name: uva573.c
// Author: darkdream
// Created Time: 2013年02月05日 星期二 15时13分06秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   double  h ;
   while (scanf("%lf",&h))
   {
      double  u , d ,f ,th = 0, x , u1;
	  int i ;
	  scanf("%lf %lf %lf",&u,&d,&f);
	  if(!h && !u && !d && !f)
		  break;
	  x = u * f *1.0/100.0;
	  u = u+x;
	  
	  for(i = 1; ; i++)
	  {
		  
		u = u- x;
		if(u-x <= 0)
			u = 0 ;
			th += u;

		if(th > h)
		{
			 printf("success on day %d\n",i);
			 break;
		}
		th = th - d;
		if(th  <  0 )
		{
		 printf("failure on day %d\n",i);
		 break;
		}
	  }

   }
   
return 0 ;
}
