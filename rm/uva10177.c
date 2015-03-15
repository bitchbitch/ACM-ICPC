// File Name: uva10177.c
// Author: darkdream
// Created Time: 2013年02月19日 星期二 20时38分26秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int n ;
   while (scanf("%d",&n)!=EOF)
   {
     long long  sum1 = 0,sum2 = 0 ,sum3 = 0;
     int i ;
	 for (i = 1;i <= n;i ++)
	 {
		 sum1 += i*i;
		 sum2 += i*i*i;
		 sum3 += i*i*i*i;
	 }
	 long long sum4 ,sum5,sum6;
	 sum4 = sum5=sum6 = 0;
	 int j ;
	 for (i =1 ;i <= n; i++)
	 { 
		long long int temp = (n+1)*n/2*(n+1-i);
	   sum4 += temp; 
	 }
	 for (i = 1;i <= n;i++)
	 {
	    sum5 += sum4*(n+1-i);
     }
	 for(i = 1;i <= n; i++)
	 {
	   sum6 += sum5*(n+1-i);
	 }
	 printf("%lld %lld %lld %lld %lld %lld\n",sum1,sum4-sum1,sum2,sum5-sum2,sum3,sum6-sum3);


    
   }
   
return 0 ;
}
