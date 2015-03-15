// File Name: uva152.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 19时48分46秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct pi
{
 double  a, b , c; 
};
struct pi x[5001];
double ji(double x1,double y1,double z1, double x2, double y2,double z2)
{
    return floor(sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2)));
}
int main(){

  //   freopen("input.txt","r",stdin);
	//   freopen("output.txt","w",stdout);
  int i, h[10] = {0}; 
  for( i = 1; ;i++)
   {   scanf("%lf %lf %lf",&x[i].a,&x[i].b,&x[i].c);
       if(x[i].a == 0 && x[i].b== 0 && x[i].c  == 0)
		    break;
   }
   
   for(int j = 1; j < i ;j++ )
   { int min = 10,p;
     for(int  t = 1 ;t < i ;t ++)
     {
      if(t == j )
		  continue;
      p = ji(x[j].a,x[j].b,x[j].c,x[t].a,x[t].b,x[t].c);
          if(p <= min)
			  min = p ;
	     
	 
	 }
	 if(min <= 9)
		h[min]++;
    
   }
   for(i = 0 ;i <= 9 ;i++)
	  printf("%4d",h[i]);
   printf("\n");
return 0 ;
}
