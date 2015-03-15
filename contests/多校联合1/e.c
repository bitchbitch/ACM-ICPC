// File Name: e.c
// Author: darkdream
// Created Time: 2013年03月16日 星期六 15时27分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
double x = 0 ,y = 0;
double min(double a, double b)
{
    if(a > b)
		return b;
	else
		return a;
}
int  ispoint(double x1, double y1,double x2,double y2,double x3 ,double y3, double x4,double y4)
{
  double k1,k2;
	int	 is1 = 0,is2 = 0, is3 = 0, is4 = 0;
  double t1,t2,c1,c2;
	if(x2 - x1 == 0 )
	{
      is1 = 1 ;
	  t1 = x1;
	}
	else
	  k1 = (y1-y2)/(x1 - x2);
	if(k1 == 0)
		is3 =1;
	if(x3 - x4 == 0)
    {
     is2 = 1;
	 t2 = x3;
    }
	else
		k2 = (y3 - y4)/(x3 - x4);
	if(k2 == 0 )
		is4 = 1;
	if( is1 == 0)
	{
	  c1 = y1 - k1*x1;
	}
	if(is2 == 0)
	{
	  c2 = y3 - k2 *x3;
	}
	
	if( (is1 == 1 && is2 == 1))
		return 0 ;
	if( is1 == 0 && is2 == 0)
		if(k1 == k2)
			return 0;
	if(is1 == 1 && is2 == 0 )
	{
       x = t1;
	   if(is4)
		   y = c2;
	   else
	   y = k2*t1 + c2;
	   return 1;
	}
	if(is1 == 0 && is2 == 1 )
	{
		x = t2;
	   if(is3)
		   y = c1;
	   else
	    y = k1*t2 + c1;
	   return 1;
	}
    x = (c2-c1)/(k1-k2);
	y = k1*x+c1;
	return 1;


}


double dis(double a,double b,double c,double d)
{
   return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
	double x1,y1,x2,y2 ;
	int k = 1;
	while(scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2) != EOF)
	{
	   if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0 )
		   break;
	   double x3,y3,x4,y4,distance = dis(x1,y1,x2,y2);
	   scanf("%lf %lf %lf %lf",&x3,&y3,&x4,&y4);
	  if(ispoint(x1,y1,x2,y2,x3,y3,x4,y4))
	  {
		  if(fabs(dis(x,y,x1,y1) + dis(x,y,x2,y2) - dis (x1,y1,x2,y2)) < 1e-5 ) 
		  {
	         if(fabs(dis(x,y,x3,y3) + dis(x,y,x4,y4) - dis (x3,y3,x4,y4)) < 1e-5 ) 
               {      
				   distance = min(dis(x1,y1,x3,y3)+dis(x2,y2,x3,y3),dis(x1,y1,x4,y4)+dis(x2,y2,x4,y4)); 
                          		  
			   }
		  }
	  }
	  distance = distance /2.0;
      printf("Case %d: %.3lf\n",k,distance);
	  k++;
	}
return 0 ;
}
