// File Name: uva11111.c
// Author: darkdream
// Created Time: 2013年05月16日 星期四 17时56分48秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node 
{
  int num;
  int temp ;
}nodes[100005];
int main(){
   
   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int temp ;
   while(scanf("%d",&temp) != EOF)
   {
        memset(nodes,0,sizeof(nodes));
       int j = 1 , ok = 1;	
		nodes[j].num = temp;
		nodes[j].temp = 0;
      while(getchar() != '\n')
		{
		   scanf("%d",&temp);
		   if(temp + nodes[j].num == 0)
		   {
		      if(abs(nodes[j].num) <= abs(nodes[j].temp))
			  { 
				  ok = 0;
			  }
			  j = j-1;
			  nodes[j].temp += abs(nodes[j+1].num) ;
			  nodes[j+1].temp =  nodes[j+1].num = 0 ;
		   }
		   else
		   {
			j++;
		    nodes[j].num = temp;
		    nodes[j].temp = 0;
		   
		   }
			
		}
	  if(nodes[1].num != 0 )
		  ok = 0;
	  if(ok == 1)
		  printf(":-) Matrioshka!\n");
	  else
		  printf(":-( Try again.\n");

   }
return 0 ;
}
