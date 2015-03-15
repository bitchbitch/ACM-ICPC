// File Name: c.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 14时12分16秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <ctype.h>

int main(){

   int n  ; 
   char a[1000];
   scanf("%d",&n);
   getchar();
   while(n--);
   {
	 int i ;  
     gets(a);
	
	 for (i = 0 ;i <strlen(a) ; i++)
		{
		   if (i == 0 && a[0] != ' ')
			   printf("%c",toupper(a[0]));
		   if (a[i-1] == ' ' && a[i]!=' ')
			   printf("%c",toupper(a[i]));
		}
     printf("\n"); 
   }
return 0 ;

}
