// File Name: g.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 19时32分12秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[300];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
    int n; 
	while(scanf("%s %d",a,&n) != EOF)
	//scanf("%s",a);
	//for(n = 0 ;n <= 7; n ++)
	{
	  getchar();
	  //printf("\n");
	  if(n > 0) 
	  n = n % 8;
	  else
		  n = (8-(-n)%8)%8;
	   
	   if(n == 0)
		   puts(a);
	   if(n == 1)
	   {
		   int k = strlen(a)-1;

	     for(int i = strlen(a)-1;i >= 0 ;i --)
		 {
		   for(int j = 1; j <= k ; j ++)
			   printf(" ");
		   printf("%c",a[i]);
		 printf("\n");
		 k--;
		 }
	   }
	   if(n == 2)
	   {
	     for(int i = strlen(a)-1 ;i >= 0 ;i --)
		 {	
			 for(int j = 1;j <= (strlen(a)-1)/2; j++)
				 printf(" ");
			 printf("%c\n",a[i]);
		    
		 }
	   }
	   if(n==3)
	   {
		   int k = 0;

	     for(int i = strlen(a)-1;i >= 0 ;i --)
		 {
		   for(int j = 1; j <= k ; j ++)
			   printf(" ");
		   printf("%c",a[i]);
		 printf("\n");
		 k++;
		 }
	   
	   }
	   if(n == 4)
	   {
	     for(int i = strlen(a)-1 ;i >= 0 ;i --)
			 printf("%c",a[i]);
		 printf("\n");
	   }
	   if(n == 5)
	   {
		   int k = strlen(a)-1;

	     for(int i = 0;i < strlen(a) ;i ++)
		 {
		   for(int j = 1; j <= k ; j ++)
			   printf(" ");
		   printf("%c",a[i]);
		 printf("\n");
		 k--;
		 }
	      
	   }
	   if(n==6)
	   {
	     for(int i = 0 ;i < strlen(a) ; i++)
		 {  for(int j = 1; j <= (strlen(a)-1)/2 ; j ++)
			   printf(" ");
			 printf("%c\n",a[i]);
		 }
	   }
	   if(n==7)
	   {
		   int k = 0;

	     for(int i = 0;i < strlen(a) ;i ++)
		 {
		   for(int j = 1; j <= k ; j ++)
			   printf(" ");
		   printf("%c",a[i]);
		 printf("\n");
		 k++;
		 }
	   
	   }
	   
	}
return 0 ;
}
