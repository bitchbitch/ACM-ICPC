// File Name: b.c
// Author: darkdream
// Created Time: 2013年03月13日 星期三 23时57分14秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char c[1000005];
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int n ;
	scanf("%d",&n);
	int i = 0 ;
	long long int suma = 0,sumb = 0;
	while(n--)
	{
	   int a, b;
	   scanf("%d %d",&a,&b);
	   if(suma <= sumb)
	   {
	     suma += a;
		 c[i++] = 'A';
	   }
	   else
	   {
	     sumb += b;
		 c[i++] = 'G';
	   }
	
	}
	
	c[i] = '\0';
	if(abs(suma - sumb) > 500)
	{ int t= 0;
	   if(suma  > sumb)
	   {
	       for(int j = i -1; j >= 0 ; j--)
		   {
		     if(c[j] == 'A')
			 {
				 c[j] =  'G';
				 t = 1;
				 break;
			 }
		   }
	   
	   }   
	   if(sumb  > suma)
	   {
	       for(int j = i -1; j >= 0 ; j--)
		   {
		     if(c[j] == 'G')
			 {
				 c[j] =  'A';
				 t = 1;
				 break;
			 }
		   }
	   
	   }   
      if(t == 1)
		  puts(c);
	  else
		  printf("-1");
	}
	else
		puts(c);
return 0 ;
}
