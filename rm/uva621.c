// File Name: uva621.c
// Author: darkdream
// Created Time: 2013年02月04日 星期一 14时04分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int  n ;
   scanf("%d",&n);
   getchar();
   while(n--)
   {
     char a[100000];
	 gets(a);
	 if (strlen(a) <= 2)
	 { printf("+\n");
	   continue;
	 }
	 else
	 {
	   if(a[strlen(a)-1] == '5' && a[strlen(a)-2] =='3')
	   {
	     printf("-\n");
         continue;
	   }
	   if(a[strlen(a)-1] == '4' && a[0] == '9')
	   {
	    printf("*\n");
		continue;
	   }
	   if(a[0] == '1' && a[1] == '9' && a[2] == '0')
	   {
	     printf("?\n");
		 continue;
	   }


	 
	 }
	 
    
   }
return 0 ;
}
