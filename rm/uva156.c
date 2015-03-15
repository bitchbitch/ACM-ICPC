// File Name: uva156.c
// Author: darkdream
// Created Time: 2013年02月25日 星期一 20时17分25秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <ctype.h>
char b[10000][80] = {0};
struct k{
   char str[80];
   int t ;

};

int comp1(const void *a, const void *b)
{
   return *(char*)a - *(char*)b;
}

int comp2(const void *a, const void *b)
{

     return strcmp(((k*)a)->str,((k*)b)->str);
}
struct k a[10000];
int main(){

  freopen("input.txt","r",stdin);
  memset(a,0,sizeof(a));
//   freopen("output.txt","w",stdout);
   int n = 0 ;
   while(scanf("%s",a[n].str) !=EOF)
   {
        if (a[n].str[0] == '#')
			break;
		n++;
   }
   for(int i = 0 ;i < n ; i++)
   {   for(int  j = 0; j < strlen(a[i].str); j++)
	   {
	      b[i][j] = tolower(a[i].str[j]);
	   }
	 qsort(b[i],strlen(a[i].str),sizeof(char),comp1); 
   }
   for(int i = 0 ;i < n; i++)
   {
      a[i].t++;
      if(a[i].t != 1)
		  continue;
	   for (int j = i+1 ;j < n ;j++)
	   {
	     if (strcmp(b[i],b[j]) == 0)
		 {
		    a[i].t++;
			a[j].t++;
		 }
	   }
   
   }
   qsort(a,n,sizeof(k),comp2);
   for(int i = 0 ;i < n ; i++)
   {
    if(a[i].t == 1)
		puts(a[i].str);
   }

return 0 ;
}
