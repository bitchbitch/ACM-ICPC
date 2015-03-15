// File Name: uva10161.c
// Author: darkdream
// Created Time: 2013年01月30日 星期三 09时31分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   long long  int n ; 
	while(scanf("%lld",&n),n)
	{ long long int i , j , k , t;
	  k = sqrt(n);
	  t = k * k;
	  if (k % 2== 0)
	  {
	     if (n - t == 0)
			 printf("%lld 1\n",k);
		 else 
		 {
		    if (n <= t+k+1)
				printf("%lld %lld\n",k+1,n-t);
			else 
				printf("%lld %lld\n",(k+1)*(k+1) -n +1,k+1);
		 }
	  
	  }
	  else 
	  {
		  if (n-t == 0)
			  printf("1 %lld\n",k);
          else
          {
		     if (n <=  t+k+1)
				 printf("%lld %lld\n",n - t, k+1);
			 else
			  printf("%lld %lld" ,k+1,(k+1)*(k+1) - n +1);
		  }
	  
	  }
	
	}
return 0 ;
}
