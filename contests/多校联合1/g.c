// File Name: g.c
// Author: darkdream
// Created Time: 2013年03月16日 星期六 14时15分31秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define k 1000000007
int a[100005];
long long int sum1[100005];
long long int sum2[100005];
int hehe(int i )
{
    
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n ;
   while(scanf("%d",&n),n)
   {
      for(int i = 1 ;i <= n; i++)
	  { scanf("%d",&a[i]);
      
	  }
	  sum1[1] = a[1];
	  for(int i = 2 ;i <= n; i ++ )
		{   	
		  sum1[i] = sum1[i-1]*a[i]%k;
		}
	  sum2[n] = a[n];
	  sum1[0] = 1;
	  sum1[n+1] = 1;
	  for(int i = n-1; i >= 1; i --)
	  {
	    sum2[i]  = sum2[i+1]*a[i]%k;
	  }
	  sum2[0] = 1;
	  sum2[n+1] = 1;
	 for(int i = 1; i <= n; i ++)
      {
	   if(i != 1)
		   printf(" ");
	    printf("%lld",sum1[i-1]*sum2[i+1]%k);
	  }
	 printf("\n");
   }
return 0 ;
}
