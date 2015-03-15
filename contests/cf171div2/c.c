// File Name: c.c
// Author: darkdream
// Created Time: 2013年03月05日 星期二 00时25分54秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[100001];
int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int n , m ;
  scanf("%d %d", &n , &m)
  {
	   for (int i = 1;i <= n ; i ++)
		   scanf("%d",&a[i]);
	   int p = 1,q = 1 , t = 0 ,i;
	   long long  sum = a[1] ;
	   for( i = 2; i<= n; i++)
	   {
	        if(sum + a[i] > m)
				break;
	   }
	   sum = sum - a[i];
	   p = i -1;
	   int k = 0 ;
	   for ( ;  i <= n ; i++)
	   {
		   if(sum + a[i]  > m)
	         if(a[i] <= a[p])
			 {
			   sum = sum - a[i]+a[p];
			 }
			 else
			 {
			     t ++; 
			 
			 }
		   else
		    {	   q++;
                   sum = sum + a[i];
			}	
	   
	   }



  
  }
return 0 ;
}
