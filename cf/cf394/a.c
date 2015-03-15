// File Name: a.c
// Author: darkdream
// Created Time: 2014年02月20日 星期四 23时26分04秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[10000];
int main(){
  scanf("%s",str);
  int len = strlen(str);
  int a,b,c;
  int i ;
  for(i = 0 ;;i ++)
	  if(str[i] != '|')
	  {
	    a = i ;
		break;
	  }
  i ++;
  for(; ;i ++ )
  {
    if(str[i] != '|')
	{
	  b =  i - a - 1;
	  break;
	}		
  }
  c = len - i - 1;
  if(c -(a + b)  == 2)
  {
    for(int i = 1;i <= a+1; i ++)
		printf("|");
	printf("+");
	for(int i = 1;i <= b ;i ++)
	printf("|");
	printf("=");
	for(int i = 1;i <= c - 1; i ++)
		printf("|");
  }else 
  if(c -(a + b)  == -2)
  {
   if(a >= 2)
   {
    for(int i = 1;i <= a-1; i ++)
		printf("|");
	printf("+");
	for(int i = 1;i <= b ;i ++)
	printf("|");
	printf("=");
	for(int i = 1;i <= c + 1; i ++)
		printf("|");
   }else {
    for(int i = 1;i <= a; i ++)
		printf("|");
	printf("+");
	for(int i = 1;i <= b-1 ;i ++)
	printf("|");
	printf("=");
	for(int i = 1;i <= c + 1; i ++)
		printf("|");
   
   
   }
  }else if(c == a+b)
  {
    for(int i = 1;i <= a; i ++)
		printf("|");
	printf("+");
	for(int i = 1;i <= b ;i ++)
	printf("|");
	printf("=");
	for(int i = 1;i <= c ; i ++)
		printf("|");
    
  }else printf("Impossible\n");
  return 0 ;
}
