// File Name: uva10878.c
// Author: darkdream
// Created Time: 2013年02月22日 星期五 19时33分40秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   char a[100];
   while(gets(a))
   {  
      if( strcmp(a,"___________") == 0)
		  continue;
	  if(strcmp(a,"|  o  .   |") == 0)
	  {
		  printf(" ");
		  continue;
	  }
	  if(strcmp(a,"|    o. o |") == 0)
	  {
	      printf("\n");
		  continue;
	  }
	  if(strcmp(a,"|  o o.oo |") == 0)
	  {
	      printf(".");
		  continue;
	  }
	  int p = 1 , t = 0;
	 for(int i = strlen(a) - 2 ; i>=4 ;i-- )
	 {
	    if(i == 6) continue;
		if(a[i] == 'o')
            t += p;
		p = p*2;		
	 }
	 if(a[3] == 'o')
	 printf("%c",'a'+ t - 1);
	else
		printf("%c",'A'+t-1);
   }
return 0 ;
}
