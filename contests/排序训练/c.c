// File Name: c.c
// Author: darkdream
// Created Time: 2014年03月05日 星期三 19时22分18秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct node{
   int time ;
   int hs[30];
   int ok[30];
   int num ;
   int p ;
}a[2000];
int cmp(const void *a ,const void *b)
{
     if((*(node *)a).num == (*(node *)b).num)
		{
         if((*(node *)a).time == (*(node *)b).time)
			 return (*(node *)a).p - (*(node *)b).p;
		 return (*(node *)a).time - (*(node *)b).time;
		}
	 return (*(node *)b).num - (*(node *)a).num;
}
struct hehe {
	int ci , pi , ti , ri;
}b[2000];
int cmp1(const void * a,const void *b)
{
   return (*(hehe *)a).ti - (*(hehe*)b).ti;
}
int main(){ 
   int c,  n ;
   memset(a,0,sizeof(a));

   scanf("%d %d",&c,&n);
   for(int i = 1;i <= c ;i ++)
	   a[i].p = i ; 
   for(int i= 1 ;i<= n;i ++)
   {
      int ci,pi,ti,ri;
	  scanf("%d %d %d %d",&b[i].ci,&b[i].pi,&b[i].ti,&b[i].ri);
   }
   qsort(b+1,n,sizeof(hehe),cmp1);
   for(int i =1 ;i <= n ;i++)
   {
	  if(a[b[i].ci].ok[b[i].pi])
		  continue;
	  if(b[i].ri == 0 )
	  {
	    a[b[i].ci].hs[b[i].pi]-- ;
	  }else {
	     a[b[i].ci].time += b[i].ti - a[b[i].ci].hs[b[i].pi]* 20*60 ; 
		 a[b[i].ci].num ++;
		 a[b[i].ci].ok[b[i].pi] = 1;
	  }
   }
   qsort(a+1,c,sizeof(node),cmp);
  /* for(int i = 1;i <= c ;i++)
	    printf("%d ",a[i].time);
   printf("\n");*/
   for(int i = 1;i <= c ;i ++)
	   printf(i == 1?"%d":" %d",a[i].p);
  //printf("\n");
return 0 ;
}
