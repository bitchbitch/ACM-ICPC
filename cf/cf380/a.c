// File Name: a.c
// Author: darkdream
// Created Time: 2014年01月12日 星期日 23时07分08秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node{
 int st,a,b;
}list[10000005];
int a[10000005];
int main(){
  int n , m ; 
  scanf("%d",&m);
  for(int i=1 ;i <= m ;i ++)
  {
    scanf("%d",&list[i].st);
	if(list[i].st == 1)
	{
	    scanf("%d",&list[i].a);
	}else scanf("%d %d",&list[i].a,&list[i].b);
  }
  scanf("%d",&n);
  __int64 k  = 0 ;
  int num = 0; 
  for(int i = 1;i <= n;i ++)
  {
    __int64 temp;
    scanf("%I64d",&temp);
//	printf("\n*%I64d*\n",k);
    while(k < temp){

	   num ++ ;

	   if(list[num].st == 1)
	   {
	      k ++;
		  if(k <= 1000000)
		  {
			  a[k] = list[num].a; 
		  }
		  if(k == temp)
		  {	  
			  printf("%d ",list[num].a);
		  }
	   }
	   else {
		__int64 tp = k; 
		if(tp <= 1000000)
		 {
		   for(int  j = 1; j <= list[num].b;j ++)
		   {
			 for(int s = 1; s <= list[num].a ; s ++)
		     {
		      tp ++;
			  if(tp >= 1000000)
				  break;
			  a[tp] = a[s];
		     }
			 if(tp>= 1000000)
				 break;
		   }
		 }

		   
		 if(k + list[num].a *list[num].b >= temp)
		 {
			int he = (temp - k ) % list[num].a;
			if(he == 0)
				he = list[num].a;
		    printf("%d ",a[he]);
			num--;
			break;
		 }else k = k + list[num].a*list[num].b;
	   
	   }
	}
  }
  return 0 ; 
}
