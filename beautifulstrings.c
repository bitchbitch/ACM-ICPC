// File Name: beautifulstrings.c
// Author: darkdream
// Created Time: 2013年01月26日 星期六 08时09分05秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int cmp(const void *a , const void *b)
{
 return *(int *)b - *(int *)a;
}

int main(){
    int n ,j;  
	char a[600];

	int b[26];
	FILE *p1;
	p1 = fopen("output.txt","w");
	scanf("%d",&n);
    getchar();
	for(j = 1; j<= n; j++)
	{
	  gets(a);
	  memset(b,0,sizeof(b));
	  int k , l, i ;
	  for (i = 0 ; i < strlen(a) ; i ++ )
		  a[i] = toupper(a[i]);
	  
	  for (i =  0  ;i <  strlen(a); i++)
		  if (a[i] >='A' && a[i]<= 'Z')
			  b[a[i]-'A'] ++;
       qsort(b,26,sizeof(int),cmp);
	   int sum = 0;
	   for (i = 0 ; i <26 ;i++  )
		   sum  += b[i]*(26-i);
	   fprintf(p1,"Case #%d:%d\n",j,sum);
    
	
	}fclose(p1);
return 0 ;
}
