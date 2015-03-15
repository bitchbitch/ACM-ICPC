// File Name: e.c
// Author: darkdream
// Created Time: 2013年04月15日 星期一 20时08分27秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[100][100];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n , s;
   while(scanf("%d %d",&n,&s) != EOF)
   {
      getchar();
	  for(int i = 1 ;i <= n ;i ++)
		  gets(a[i]);
	  if(s >= 0)
	  s = s %4;
	  else
		s =  (4 - (-s)%4 )%4;
	  if(s == 0 )
	  {
	     for(int i = 1;i <= n;i ++)
			 puts(a[i]);

	  }
	  if(s == 1)
	  {
	     for(int i = 0 ;i < n ; i ++)
		 {
		   for(int j = n ;j >= 1; j --)
			   printf("%c",a[j][i]);
		   printf("\n");
		 }
	  }
	  if(s == 2)
	  {
	     for(int i = n ;i >= 1;i --)
		 { for(int j = n-1 ;j >=0; j --)
				 printf("%c",a[i][j]);
				 printf("\n");
	     }
	  
	  }
	  if(s == 3)
	  {
	     for(int i = n -1 ;i >= 0; i --)
		 {
		   for(int j = 1 ;j <= n; j ++)
			   printf("%c",a[j][i]);
		   printf("\n");
		 }
	  }
   }
return 0 ;
}
