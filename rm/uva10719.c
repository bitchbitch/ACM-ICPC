// File Name: uva10719.c
// Author: darkdream
// Created Time: 2013年02月18日 星期一 22时09分56秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int  a[12000];
int  b[12000];
int main(){
  int  k ;
  while(scanf("%d",&k)!=EOF)
  { 
	  int n = 1 , i ,r;
	  while(1)
	  {
		char c;
	    scanf("%d",&a[n]);
		c = getchar();
        if(c == '\n' or c == EOF)
			break;
		n++;

		
	  }
	  b[1] = a[1];
	  for (i = 1;i <= n - 1; i++)
		  b[i] = a[i] + b[i-1]*k;
      r = a[n]+b[n-1]*k;
	  printf("q(x):");
	  for (i = 1; i<= n-1;i++)
		  printf(" %d",b[i]);
      printf("\nr = %d\n\n",r);
  }
    
return 0 ;
}
