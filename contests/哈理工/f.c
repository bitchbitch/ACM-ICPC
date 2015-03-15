// File Name: f.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 14时22分34秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   int n ,j;
   scanf("%d",&n);
 getchar();
   for(j = 1; j<= n; j++)
   {
     char a[1000];
	 gets(a);
	 int i , t = 0 ;
	 
	printf("Case #%d: ",j);
	 for (i = 0 ; i< strlen(a); i ++)
	  {
	    if (a[i+1] == '/' && a[i] =='/')
			break;

	  }
	 i = i+2;
	 for (; i< strlen(a); i++)
		 if (a[i] ==':' || a[i] =='/')
			 break;
	      else 
			  printf("%c",a[i]);
	 printf("\n");

   }
return 0 ;
}
