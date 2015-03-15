// File Name: a.c
// Author: darkdream
// Created Time: 2013年02月24日 星期日 23时27分30秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  int n , m;
  long long max = -10000000000000 ;
  scanf("%d %d",&n,&m);
  for (int i = 1; i<= n ;i++)
  {
     int a , b;
	 scanf("%d %d",&a,&b);
	 if(b > m )
		 a = a -(b -m );
	
	 if(a >max)
		 max = a;

  
  }
 printf("%I64d",max);
return 0 ;
}
