// File Name: uva10392.c
// Author: darkdream
// Created Time: 2013年03月02日 星期六 21时34分03秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define N 1000000
bool a[N+5] = {0} ;
int b[80000];
int main(){
	a[1] = 1 ;
	int t;
	for(int i = 2 ; i <= sqrt(N) ;i ++ )
	{
		if(a[i] == 0)
		{
			long long int k = i * i ;
			while(k <= N )
			{
				a[k] = 1;
				k = k + i ;
			}
		}
	}
	int p = 1;
	for(t = 1; t <= N ;t ++)
		if(a[t] == 0)
			b[p++] = t;
    long long int n ;
   while(scanf("%lld",&n) != EOF)
   {
     if(n < 0  )
		 break;
	 for(long long int i = 1; i < p ;i ++)
	 {
	    if (n % b[i] == 0 )
		{ 
			n = n / b[i];
			printf("    %d\n",b[i]);
		    i = i - 1;
		}
		if(n == 1)
			break;
	 
	 }
	 if(n == 1)
		 printf("\n");
	 else
		 printf("    %lld\n\n",n);

   }
	    

return 0 ;
}


