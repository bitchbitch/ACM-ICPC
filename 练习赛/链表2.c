// File Name: 链表2.c
// Author: darkdream
// Created Time: 2013年03月12日 星期二 10时21分52秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct list
{
    int y;
	struct list  *last;
	struct list  *next;
};

int main(){
 //  freopen("input.txt","r",stdin);
 //  freopen("output.txt","w",stdout);
 long long  int  n , m ;
 struct list a[10005], h, *temp , *p;
 while(scanf("%lld %lld",&n,&m) != EOF)
 {
   memset(a,0,sizeof(a));
    temp = &a[1];
   for(int i = 1;i <= n; i ++)
	   a[i].y = i ;
   for(int i = 2;i <= n ; i++)
   {  a[i-1].next = &a[i];
      a[i].last = &a[i-1];
   }
   a[n].next = &a[1];
   a[1].last = &a[n];
   
  while(n != 1)
  {
  int t = m%n;
   if(t == 0)
	   t = n ;
   p = temp;
   for (int i = 1;i < t; i++)
      {
		  p = p->next;
	  }
   printf("%d\n",p->y);
   temp = p->next;
   p->last->next = temp;
   p->next->last = p->last;
   n = n -1 ;
  }
 printf("%d\n",temp->y);
 }
return 0 ;
}
