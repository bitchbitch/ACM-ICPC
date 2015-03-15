// File Name: uva846.c
// Author: darkdream
// Created Time: 2013年02月04日 星期一 21时44分48秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
    int n ;
	scanf("%d",&n);
   while(n--)
   { long long int a ,b ;
	   
      scanf("%lld %lld",&a,&b);
	  if(a-b  < 0)
		  a = b- a;
	  else 
		  a = a -b;
	  if (a == 0)
		  printf("0\n");
	  else
	  {
	  for (b = 0; ;b++)
	  {
	     if (b*(b+1) >= a )
			 break;
	  }
	  if (a  > b*b)
		  printf("%lld\n",2*b);
	  else 
	  printf("%lld\n",2*b-1);
	  }
   }
return 0 ;
}
