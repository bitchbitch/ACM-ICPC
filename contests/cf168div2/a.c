// File Name: a.c
// Author: darkdream
// Created Time: 2013年02月20日 星期三 23时22分05秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
  int a[5][5] = {0},b[5][5] = {0};
  int i , j ;
  for (i =1 ;i<= 3 ;i++)
	  for (j =1 ;j<= 3; j++)
	  {
	    scanf("%d",&a[i][j]);
	  }
  for (i= 1;i <= 3; i++)
	  for (j =1 ;j<=3; j++)
	  {
	    b[i][j] = a[i][j]+a[i][j-1]+a[i][j+1]+a[i-1][j]+a[i+1][j];
	  }
  for(i =1 ;i <= 3; i++)
  {  for (j =1 ;j <=3 ;j++)
	  {
		  if (b[i][j]%2==0)
			  printf("1");
		  else
			  printf("0");

	  }
	  printf("\n");
  }
return 0 ;
}
