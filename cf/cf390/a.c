// File Name: a.c
// Author: darkdream
// Created Time: 2014年02月11日 星期二 23时28分28秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int hsx[100004];
int hsy[100005];
int main(){
  memset(hsx,0,sizeof(hsx));
  memset(hsy,0,sizeof(hsy));
  int n ; 
  scanf("%d",&n);
  int x, y ;
  x = y = 0 ; 
  for(int i = 1;i <= n;i ++)
  {
    int tx, ty ; 
	scanf("%d %d",&tx,&ty);
	if(!hsx[tx])
	 {
	   hsx[tx]  = 1 ; 
	   x ++;
	 }
	if(!hsy[ty])
	{
	  hsy[ty] = 1; 
	  y ++ ;
	}
  }
  if(x > y )
  {
    printf("%d",y);
  }else printf("%d",x);
return 0 ;
}
