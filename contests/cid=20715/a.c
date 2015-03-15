// File Name: a.c
// Author: darkdream
// Created Time: 2013年03月19日 星期二 13时05分14秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <ctype.h>

int main(){

  // freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   char a,temp;
   temp = ' ';
   int sum = 0 ;
   while(scanf("%c",&a) != EOF)
   {
       if(!isalpha(temp) && isalpha(a))
		   printf("%c",a);
	   else if(isalpha(temp) && isalpha(a))
			 sum ++;
	   else if(!isalpha(a) && isalpha(temp))
	   {
		  if(sum >= 2)
	      printf("%d%c%c",sum -1,temp,a);
		  else if(sum == 0)
			  printf("%c",a);
		  else
			  printf("%c%c",temp,a);
		  sum = 0;
	   }
	   else
		   printf("%c",a);
     temp = a;
	
   }
return 0 ;
}
