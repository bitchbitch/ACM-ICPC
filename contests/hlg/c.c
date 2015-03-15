// File Name: c.c
// Author: darkdream
// Created Time: 2013年03月23日 星期六 13时10分31秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int comp(const void *a, const void *b)
{
  return *(char*)a - *(char*)b;
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    char a[1000];
	int n ;
     while(scanf("%s %d",a,&n) != EOF)
	 {
	   if(strlen(a)  == 0)
		   printf("0\n");
	   else
	   {
	      qsort(a,strlen(a),sizeof(char),comp);
		  puts(a);
	   }
	   

	 }
return 0 ;
}
