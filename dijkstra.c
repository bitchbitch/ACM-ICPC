// File Name: dijkstra.c
// Author: darkdream
// Created Time: 2013年06月18日 星期二 11时16分50秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   char c ;
  while(scanf("%c",&c) != EOF)
  { getchar();
	  if(islower(c))
   {
     printf("YES\n");
   }
   else
	printf("NO\n");
  }
return 0 ;
}
