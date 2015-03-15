// File Name: a.c
// Author: darkdream
// Created Time: 2014年05月02日 星期五 23时25分37秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  int n ; 
  scanf("%d",&n);
  int p = 0 ; 
  int sum =0  ; 
  for(int i = 1;i <= n;i ++)
  {
	   int temp ; 
	   scanf("%d",&temp);
       if(temp >= 0 )
		   p += temp ; 
	   else{ 
		if(p >= abs(temp))
		   p += temp;
		else {
		   temp =-temp - p ; 
		   sum += temp ;
		   p = 0 ; 
		 }
	   }
  }
  printf("%d\n",sum);
return 0 ;
}
