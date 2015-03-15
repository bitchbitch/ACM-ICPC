// File Name: b.c
// Author: darkdream
// Created Time: 2013年03月01日 星期五 00时08分04秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char  a[100][40];
int n ;
int find(char b[])
{
  for(int i = 1;i <= n; i++)
	  if(strstr(a[i],b))
		  return 1;
  puts(b);
  return 0 ;
}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
	scanf("%d",&n);
	getchar();
	for(int i = 1 ; i<= n; i++)
		gets(a[i]);
    char b[100] = {0};
	for(int i = 'a' ; i <= 'z'; i++)
	{	b[0] = i;
		if(!find(b))
			return 0;
	}
	for(int i = 'a'; i <= 'z'; i++)
	{  b[0] = i ;
		
	   for(int j = 'a' ; j<= 'z'; j++ )
	   {   b[1] = j;
	      if(!find(b))
			  return 0;
	   
	   }
    }

	for(int i = 'a'; i <= 'z'; i++)
	{  b[0] = i ;
		
	   for(int j = 'a' ; j<= 'z'; j++ )
	   { b[1] = j;
	      for(int k  = 'a' ; k <= 'z' ; k++)
			  b[2] = k ;
		  if(!find(b))
			  return 0;
       }
	}
	for(int i = 'a'; i <= 'z'; i++)
	{  b[0] = i ;
		
	   for(int j = 'a' ; j<= 'z'; j++ )
	   { b[1] = j;
	      for(int k  = 'a' ; k <= 'z' ; k++)
		  {  b[2] = k ;
		    for(int l = 'a';  l <= 'z' ; l++)
				b[3] = l ;
			  if(!find(b))
			  return 0;
          }
	   }
	}
return 0 ;
}
