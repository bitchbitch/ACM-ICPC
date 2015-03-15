// File Name: c.c
// Author: darkdream
// Created Time: 2013年09月07日 星期六 13时01分23秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long

//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
double dis(double x1,double y1, double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
struct node
{
  double  x, y ,r; 
}yuan[1000];
int main(){
   int t ;
   scanf("%d",&t);
   while(t--)
   {
     int n;
	 scanf("%d",&n);
	 int sum  = 1 ;
	 for(int i =1 ;i <= n;i ++)
	  {
	     scanf("%lf %lf %lf",&yuan[i].x,&yuan[i].y,&yuan[i].r);
		 for(int j = 1; j < i ;j ++)
		 {
		    if(fabs(dis(yuan[i].x,yuan[i].y,yuan[j].x,yuan[j].y)-(yuan[i].r+yuan[j].r)) > 1e-9)
                  sum++;
		 }
		 sum++;
	  }
	 printf("%d\n",sum);
   }

return 0 ;
}
