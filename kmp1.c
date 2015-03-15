// File Name: kmp1.c
// Author: darkdream
// Created Time: 2013年06月17日 星期一 19时26分40秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   char str[100];
   int i , j ;
   i = 0;
   j = -1;
   int next[100];
   scanf("%s",&str[1]);
   next[0] = strlen(&str[1]);
   next[1] = 0 ;
   while(i <= next[0]){
       if(j == 0 || str[i] == str[j]){
	    i ++;
		j ++;
		next[i] = j ;
	   }
	   else
		   j = next[j];
   }
   for(int i =1 ;i <= next[0]; i++)
	   printf("%d ",next[i]);
return 0 ;
}
