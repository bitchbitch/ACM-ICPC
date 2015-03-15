// File Name: uva107.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 11时32分15秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

	double  h , m ,n ,k ;
	while (scanf("%lf %lf",&h , &m) !=EOF,h,m)
	{
		if (h == 0 && m == 0)
			break;
		n = 2;
		int left = 1, right = 100000, mid;
	
		if (m== 1)
		{	k = 0.5+log(h)/log(2.0) ;
              printf("%d %d\n",int(k-1+0.5),int(2*h-1+0.5));
		}
	    else 
	   {
		while (left)
		{ 
			n=(left+right)/2;
			if (fabs(log(n)*log(h)-log(n+1)*log(m)) < 1e-8) break;
			if (log(n)*log(h)-log(n+1)*log(m)>0) right=n;
			else left=n;
		}
       k =floor( log(m)/log(n) +0.5);	
		printf("%d ", int((floor(pow(n,k)+0.5) -1)/(n -1 )+0.5) );
		int t ;
		long long  hi = 0 ;
		for (t =0 ;t <= k;t ++)
		{
			hi = hi +int( 0.5+floor(pow(n,k-t)+0.5)* floor(pow(n+1,t)+0.5)); 
		}
		printf("%lld\n", hi );
	   }
	}
	return 0; 
}
