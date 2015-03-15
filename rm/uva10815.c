// File Name: uva10815.c
// Author: darkdream
// Created Time: 2013年02月22日 星期五 20时43分36秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char c[1000000][201] = {0};
int comp(const void *a , const void *b)
{
   return strcmp((char*)a,(char*)b);
}
int main(){
	int i = -1, j ,q , p;
	char t , temp = ' ' ;
	while(scanf("%c",&t) != EOF)
	{
	   if (isalpha(t)  && !isalpha(temp))
	   {
	       j = 0 ;
		   i = i+1;
		   c[i][j++] = tolower(t);
	   }
     else  if(isalpha(t) && isalpha(temp))
		       c[i][j++] = tolower(t);
	 temp  = t;
	   

	}
	qsort(c,i+1,sizeof(char)*201,comp);
	for(int j = 0; j<= i ;j++)
	{   if(j == 0 ) 
		printf("%s\n",c[j]);
	    else	if(strcmp(c[j-1],c[j]) != 0)
		printf("%s\n",c[j]);
	}
return 0 ;
}
