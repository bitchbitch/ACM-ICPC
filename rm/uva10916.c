// File Name: uva10916.c
// Author: darkdream
// Created Time: 2013年02月19日 星期二 22时32分58秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  int n ; 
  while(scanf("%d",&n), n)
  {
     n = int(n/10.0)*10 - 1940;
	 n = n/10;
	 double t = pow(2.0,n)*log(2),sum = 0 ;
	 int i ;
	 for (i = 2;;i ++)
	 { sum +=log(i);
       if(t < sum)
		   break;
	   
	}
	 printf("%d\n",i-1);
		 
  }
    
return 0 ;
}
