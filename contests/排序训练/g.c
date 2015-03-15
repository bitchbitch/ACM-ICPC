// File Name: g.c
// Author: darkdream
// Created Time: 2014年03月05日 星期三 21时11分04秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node{
  int ta,tb;
  double j;
}a[10];
int  cmp(const void *a ,const void *b)
{
   
   if(fabs((*(node *)a).j - (*(node *)b).j )< 1e-8)
		   {
              if((*(node *)a).ta > (*(node *)b).ta)
		         return 1;
			  else return -1 ; 
		   }
     if( (*(node *)a).j > (*(node *)b).j)
		 return 1 ;
	 else return -1 ; 
}
double dabs(double a, double b)
{
    double t = a- b; 
	if(t <= 0 )
		t = -t;
	if(t >= 0.5)
		t = 1 - t;
	return t ; 

}
int main(){
  int t ; 
  scanf("%d",&t);
  while(t--)
  {
	for(int i =1 ;i <= 5;i ++)
	{
	  scanf("%d:%d",&a[i].ta,&a[i].tb);
      a[i].j = dabs((a[i].tb)*1.0/60,(a[i].ta%12)*1.0/12 + a[i].tb*1.0/720);
	}
	qsort(a+1,5,sizeof(node),cmp);
//	for(int i = 1;i <= 5;i ++)
	printf("%02d:%02d\n",a[3].ta,a[3].tb);
  }
return 0 ;
}
