// File Name: uva10785.c
// Author: darkdream
// Created Time: 2013年02月26日 星期二 22时20分12秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
char  str[500];
char  str1[500];
char  str2[500];
int comp(const void *a,const void *b)
{
 return *(char*)a - *(char*)b;
}
int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   int n ;
   scanf("%d",&n);
   for(int s = 1; s <= n; s ++)
   {
	 memset(str,0,sizeof(str));
	 memset(str1,0,sizeof(str1));
	 memset(str2,0,sizeof(str2));

      int m ;
	  char a[5] = {'A','U','E','O','I'};
	  char b[21] = {'J','S','B','K','T','C','L','D','M','V','N','W','F','X','G','P','Y','H','Q','Z','R'};
	  int a1[5] = {0},b1[21] = {0};
	  scanf("%d",&m);
	  int k = 0;
	  for (int i = 0 ; i < m ; i= i+2)
	  { int j ;
	      for(j = 0 ;j < 5 ;j++)
		  {
		     if(a1[j] < 21)
			 {
			   str1[k++] = a[j];	 
			   a1[j]++;
			   break;
			 }

		  }
	  }
	  qsort(str1,k,sizeof(char),comp);
	  k = 0;
	  for(int i = 1 ; i < m ; i = i+2)
	  {
	    int j ;
		for(j = 0 ;j < 21 ;j++)
		{
		  if(b1[j] < 5 )
		  {
		   str2[k++] = b[j];
		    b1[j]++;
			break;
		  }
		}
	  }
	  qsort(str2,k,sizeof(char),comp);
	  printf("Case %d: ",s);
	  for(int i = 0 ;i < m ;i++ )
	  {
	    if(i %2 == 0)
			printf("%c",str1[i/2]);
		else
		  printf("%c",str2[i/2]);
	  }
    printf("\n");
   }
return 0 ;
}
