// File Name: uva400.c
// Author: darkdream
// Created Time: 2013年02月25日 星期一 22时02分33秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char a[120][70];
int comp(const void *a,const void *b)
{
   return strcmp((char*)a,(char*)b);
}
void print(int i , int k)
{
   printf("%s",a[i]);
   for(int j  = 1; j <= k -strlen(a[i]); j++)
	   printf("*");
}
int main(){

  freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n ;
   while(scanf("%d",&n) != EOF)
   {
     getchar();
	 memset(a,0,sizeof(a));
	 int max = 0 , i , j , k , l ;
	 for(int i = 0 ;i < n ;i++)
	 {	 gets(a[i]);
         if(strlen(a[i]) > max)
			 max = strlen(a[i]);
	 }
	 qsort(a,n,sizeof(char)*70,comp);
	 printf("------------------------------------------------------------\n");
     if(max > 29)
	 {
	   for (int i = 0 ;i < n ;i++)
		   puts(a[i]);

	 }
	 else
	 {
	   if((60 -max) %(max+2) == 0)
	   {  
		   k =(60 - max)/(max+2) +1;
	       int t =(int)ceil(n*1.0/k);
           for(int i = 1 ;i <= t;i++)
		   {   for(int j = 1; j<= k ; j++)
			   {
				 if(i-1+(j-1)*t > n)
					 continue;
				  if( j == k )
					  print(i-1+(j-1)*t , max);
				  else 
			      print(i-1+(j-1)*t,max +2);
			   }
			   printf("\n");
		   }
	   }
	   else
	   {
	       k = 60 /(max +2);
	       int t =(int)ceil(n*1.0/k);
		   for(int i = 1 ;i <= t;i++)
		   {   for(int j = 1; j<= k ; j++)
			   {
				 if(i-1+(j-1)*t >= n)
					 continue;
			      print(i-1+(j-1)*t,max +2);
			   }
			   printf("\n");
		   }
	   }
	 }

   }
return 0 ;
}
