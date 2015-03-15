// File Name: duipai.c
// Author: darkdream
// Created Time: 2013年08月18日 星期日 16时56分30秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char str[1000];
char str1[1000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   FILE *p1 = fopen("output.txt","r");
   FILE *p2 = fopen("output1.txt","r");
   int t = 0 ; 
   while(fgets(str,1000,p1) && fgets(str1,1000,p2))
   {
	  t++;
      if(strcmp(str,str1) != 0 )
		  printf("%d\n",t);
   }
return 0 ;
}
