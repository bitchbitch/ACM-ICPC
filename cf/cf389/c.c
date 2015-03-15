// File Name: c.c
// Author: darkdream
// Created Time: 2014年02月04日 星期二 00时06分24秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int hs[200];
int main(){
  int n ; 
  memset(hs,0,sizeof(hs));
  scanf("%d",&n);
  int temp;
  for(int i =1; i <= n;i ++)
  {scanf("%d",&temp);
   hs[temp]++;
  }

  int sum = 0 ;
  int ok = 0 ; 
  while(!ok)
  {
	ok = 1; 
    sum ++;
	int temp = 0;
	for(int i = 0 ;i <= 100; i ++ )
	{
	    if(hs[i] && i >= temp)
		{
		  hs[i]-- ; 
		  temp ++ ;
		  ok = 0 ; 
		i = temp - 1;
		}
	}
  }
  printf("%d\n",sum-1);
return 0 ;
}
