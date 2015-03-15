// File Name: uva10025.c
// Author: darkdream
// Created Time: 2013年02月04日 星期一 17时28分07秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
	int n , h;
	scanf("%d",&n);
	while (n--)
	{ 
	  long long  i  , j , k, l , m ;
	  scanf("%lld",&k);
	  if(k < 0 )
		 k = -k ;
	  for (i = 1;; i++)
		  if(i*(i+1)/2 >= k )
		  {
		    break;
		  }
	  if ((i*(i+1)/2 - k)%2 == 0)
		  printf("%lld\n",i);
	  else
	  {  if (i%2 == 0 )
             printf("%lld\n",i+1);
		 else 
			 printf("%lld\n",i+2);
	  }
	if(n)
		printf("\n");
	}
return 0 ;
}
