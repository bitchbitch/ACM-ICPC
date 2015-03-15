// File Name: 链表1.c
// Author: darkdream
// Created Time: 2013年03月12日 星期二 09时00分01秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct t
{
 int date;
 struct t *next;
};

int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   struct t a[205];
   int n; 
   while(scanf("%d",&n) != EOF)
   {  int j , i ;
      for( j = 1; j <= n; j ++)
        scanf("%d",&a[j].date);
	  int m;
	  scanf("%d",&m);
	  for( j ;j <= n+m ; j ++)
		  scanf("%d",&a[j].date);
	  for(i = 2;i <= n+m ;i ++)
			a[i-1].next = &a[i];
	  a[i-1].next = NULL;
	  for( i = 1;i <= n+m; i ++)
		  for( int k = i+1 ; k <= n+m; k ++)
		  if(a[i].date < a[k].date)
		  {
		    int p = a[i].date;
			a[i].date = a[k].date;
			a[k].date = p;
		  }
	  struct t p = a[1];
	  while(p.next != NULL)
	  {
	    printf("%d ",p.date);
        p = *p.next;
	  }
	  printf("%d\n",p.date);
	 
   }
 return 0 ;
}
