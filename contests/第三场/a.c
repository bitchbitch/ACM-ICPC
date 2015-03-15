// File Name: a.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 18时56分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   char a,str[300];
   while(scanf("%c %s",&a,str) != EOF)
   {
      a =  tolower(a);
	  int sum = 0 ;
	  for(int i =0 ;i < strlen(str); i ++)
	  {
	     str[i] = tolower(str[i]);
		 if(str[i] == a)
			 sum++;
	  }
	  getchar();
	  printf("%.5lf\n",sum*1.0/strlen(str));
   }
return 0 ;
}
