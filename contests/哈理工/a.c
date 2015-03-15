// File Name: a.c
// Author: darkdream
// Created Time: 2013年02月17日 星期日 13时48分49秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char  c[120][120] ,temp[120];
void change(int i , int j )
{
    memcpy(temp,c[i],120);
	memcpy(c[i],c[j],120);
	memcpy(c[j],temp,120);


}
int main(){

   int n ;
   while(scanf("%d",&n) != EOF)
   {
       int i , j;
	   getchar();
	   for (i =1; i <= n ;i ++)
		   gets(c[i]);
	   for (i =1 ; i <= n; i++)
		   for(j = i +1 ; j<= n; j++)
		   {
		     if(strlen(c[i]) > strlen(c[j]))
				 change(i , j);
		     if (strlen(c[i]) == strlen(c[j]))
			 {
			  if (strcmp(c[i],c[j]) > 0)
				  change(i , j );
			 }


		   }
	   for (i = 1;i <= n; i ++)
		 printf("%s\n",c[i]);

   }
return 0 ;
}
