// File Name: a.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 22时01分26秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
int n ;
int hs[10] = {0};
scanf("%d",&n);
char str[100];
   for(int i =1;i <= 4;i ++)
   {
     scanf("%s",str);
	 for(int j =0 ;j <4;j++)
	 {
	   if(str[j] != '.')
		   hs[str[j] -'0'] ++;
	 }
   }
   for(int i =1;i <= 9 ;i ++)
   {
     if(hs[i] > 2*n)
	 {
	  printf("NO\n");
	  return 0;
	 }
   }
   printf("YES\n");
return 0 ;
}
