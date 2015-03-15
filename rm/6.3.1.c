// File Name: 6.3.1.c
// Author: darkdream
// Created Time: 2013年03月19日 星期二 18时12分30秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int n ;
   while (scanf("%d",&n) != EOF)
   {
      int now[100],last[100];
	  int top = 0 , a = 1, b = 1 , ok = 1;
	  for(int i =1;  i<= n ;i ++)
		  scanf("%d",&now[i]);
	  while(b <= n )
	  {
	    if(a == now[b]) {a++ ,b ++;}
		else if(top && last[top] == now[b])
		{top-- ;b++;}
		else if(a<= n) last[++top] = a++;
		else
		{ok = 0 ; break;}
	  }
	  printf("%s\n",ok? "yes":"no");
   }
return 0 ;
}
