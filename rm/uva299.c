// File Name: uva299.c
// Author: darkdream
// Created Time: 2013年02月25日 星期一 17时23分46秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
   int a[60];
   int n ;
   scanf("%d",&n);
   while(n--)
   {
      int  t ;
	  scanf("%d",&t);
	  for (int i = 1;i <= t ;i++)
		  scanf("%d",&a[i]);
     int sum = 0 ;
	  for(int i = 1 ; i<= t;i++)
	  {
	     for(int j = i+1; j<= t;j++)
		 {
		   if (a[i] > a[j])
			   sum ++;
		 }
	  }
	  printf("Optimal train swapping takes %d swaps.\n",sum);
   }

return 0 ;
}
