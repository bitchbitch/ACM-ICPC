// File Name: uva550.c
// Author: darkdream
// Created Time: 2013年03月02日 星期六 17时02分28秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout); 
  int a, b ,c ;
  while(scanf("%d %d %d",&a,&b,&c) != EOF)
  { int i = 0  ,t = 0,k = b ,p ;
	 while(1)
	  { 
	   p = k*c+t;
	  k = p % a;
	  t = p / a;
	  if(k == b && p < a )
		  break;
	  i++;
	}
	printf("%d\n",i+1);
  }
return 0 ;
}
