// File Name: uva10106.c
// Author: darkdream
// Created Time: 2013年01月25日 星期五 13时18分38秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char a[600];
char b[600];
int  c[600];
int  d[600];
int  e[600];

void change(char a[],int b[])
{
	int i ;
	for (i =0 ;i < strlen(a);  i++)
	  b[strlen(a) - i - 1 ] = a[i] -'0';

}
void mu()
{ 
	void print();
   int i ,j, k ,t ; 
   for (i =0 ;i < strlen(a) ;i ++)
   {
      int s = 0 ;
	 for (j = 0 ; j < strlen(b) ;j++)
	  {
	    t = c[i]*d[j] +s +e[i+j] ;
		s = t / 10 ;
        e[i+j] = t % 10 ;
	  }
	 for (j = i+j  ; j< 550 ; j++)
	 {
	   t = e[j] + s;
	   s = t /10 ;
	   e[j] = t %10 ;
	 }
    
   }

}
void print()
{
 int i ; 
 for (i = 550 ;i >= 0 ;i--)
	 if (e[i] != 0 )
		 break;
 if (i == -1 )
	 printf("0");

 for (; i >= 0 ; i--)
	 printf("%d",e[i]);
 
 printf("\n");
}
int main(){ 
    memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(c,0,sizeof(e));
	while (gets(a))
   {
     gets(b);
     change(a,c);
	 change(b,d);
     mu();
     print();
    memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(e,0,sizeof(e));
  
   }
return 0 ;
}
