// File Name: i.c
// Author: darkdream
// Created Time: 2013年05月18日 星期六 09时48分19秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char str[3000005];
int bi[100];
void print(int x)
{
   if (x < 10)
	   printf("0%d",x);
   else if(x < 16)
	   printf("0%c",'A'+(x-10));
   else
   {
	  if(x /16 <10)
		  printf("%d",x/16);
	  else if(x/16 < 16)
		  printf("%c",'A'+(x/16-10));
      if(x%16 < 10)
		  printf("%d",x%16);
	  else
		  printf("%c",'A'+(x%16-10));

   }

}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t; 
   scanf("%d",&t);
   getchar();
   while(t--)
   {
      gets(str);
	  int k = strlen(str);
	  int b = 2097152,c = 16384 , d= 128;
	 // scanf("%d",&k); 
	  if(k >= b)
	  {
	    print(k%d+d);
		print(k%c/d+d);
		print(k%b/c+d);
		print(k/b);
	  }
	  else if(k >= c)
	  {
		 print(k%d+d);
	     print(k%c/d+d);
		 print(k/c);
	  }
	  else if(k >= d)
	  {
	    print(k%d +d);
		print(k/d);
	  }
	  else print(k);
	  
	  for(int i = 0 ;i < k ;i ++)
		  if(str[i] < 16)
			  print(str[i]);
		  else 
			  print(str[i]);
	  printf("\n");
	  
   
   }
return 0 ;
}
