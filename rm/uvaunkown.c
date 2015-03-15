// File Name: uvaunkown.c
// Author: darkdream
// Created Time: 2013年02月26日 星期二 21时09分17秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char a[100001][100];
char b[100001][100];
int  c[100001];
int comp(const void *a, const void *b)
{
   return strcmp((char*)a,(char*)b);
}
int main(){
//	freopen("input.txt","r",stdin);
    int  t ;
	scanf("%d",&t);
	for (int r = 1; r <= t ; r++)
	{
	  memset(a,0,sizeof(a));
	  memset(b,0,sizeof(b));
	  memset(c,0,sizeof(c));
     if(r != 1)
		 putchar('\n');
	   int n ;
	   scanf("%d",&n);
	   getchar();
	   for(int i = 0 ; i < n ;i++)
	   {
	       gets(a[i]);
		   int j = 0 ;
		   for(int k = 0 ; k < strlen(a[i]); k++)
		   {
		      if(isdigit(a[i][k]))
				  b[i][j++] = a[i][k];
			  else if(isupper(a[i][k]))
			  {  int p ;
				  if(a[i][k] == 'A' ||a[i][k] == 'B' ||a[i][k] =='C')
					  p = 2 ;
				  if(a[i][k] == 'D' ||a[i][k] == 'E' ||a[i][k] =='F')
					  p =  3;
				  if(a[i][k] == 'G' ||a[i][k] == 'H' ||a[i][k] =='I')
					  p =  4;
				  if(a[i][k] == 'J' ||a[i][k] == 'K' ||a[i][k] == 'L')
					  p =  5;
				  if(a[i][k] == 'M' ||a[i][k] == 'N' ||a[i][k] == 'O')
					  p =  6;
				  if(a[i][k] == 'P' ||a[i][k] == 'R' ||a[i][k] == 'S')
					  p =  7;
				  if(a[i][k] == 'T' ||a[i][k] == 'U' ||a[i][k] == 'V')
					  p =  8;
				  if(a[i][k] == 'W' ||a[i][k] == 'X' ||a[i][k] == 'Y')
					  p =  9;
			     b[i][j++] = p + '0' ;
			  }
			  
		  }
		   
	   }
	  qsort(b,n,sizeof(char)*100,comp);
	  int k = 0 , p = 0;
	   for(int j = 1 ;j < n ;j++)
		 {
			if(strcmp(b[j],b[j-1]) == 0)
				k++;
			if(strcmp(b[j],b[j-1]) == 0 &&( j == n-1 || strcmp(b[j],b[j+1])!=0))
			{
			  for(int l = 0 ; l < strlen(b[j]); l++)
			  {
			   if (l==3)
				   printf("-");
			  printf("%c",b[j][l]);

			  }
			  printf(" %d\n", k+1);
             p = 1;

              k = 0;
			}
		 }
	   if(p == 0)
		   printf("No duplicates.\n");
	}
return 0 ;
}
