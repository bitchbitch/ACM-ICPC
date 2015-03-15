// File Name: b.c
// Author: darkdream
// Created Time: 2014年02月20日 星期四 23时59分40秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int a[1000005];
int main(){
  int p  , x ; 
  scanf("%d %d",&p ,&x);
  for(int i = 1;i <= 9; i ++)
  {
	  a[p] = i ;
	  int  temp  = 0 ; 
	  for(int j = p - 1;j >= 2;j --)
	  {
	    a[j] = a[j +1] * x + temp ; 
		temp = a[j] /10 ; 
		a[j] = a[j] % 10;
	  }
	  if(p != 1)
	    a[1] =  (a[2] * x + temp )% 10 ;
	  if(a[1] == 0 || a[1] >= 10 )
		  continue;


	  temp = 0 ; 
	  for(int j = p ;j >= 2; j --)
	  {
	     temp = (a[j]*x + temp )/10; 
	  }
	  temp = a[1]*x + temp ;
	  if(temp == a[p])
	  {
		for(int i = 1;i <= p ;i ++)
			printf("%d",a[i]);
        printf("\n");		
		return 0 ; 
	  }
  }
  printf("Impossible\n");
return 0 ;
}
