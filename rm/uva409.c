// File Name: uva409.c
// Author: darkdream
// Created Time: 2013年02月22日 星期五 17时15分14秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
char key[40][40];
char ex[40][100];
char ex1[40][100];
int a[100];
int main(){
  int n,m,t = 1;
  while(scanf("%d %d",&n,&m)!=EOF)
  {
	 getchar();
     for(int i =1 ;i <= n;i++)
		 gets(key[i]);
     for(int i =1 ;i <= m ;i++)
	 {	 gets(ex1[i]);
	    for(int j  = 0 ; j < strlen(ex1[i]);j++)
          ex[i][j] = tolower(ex1[i][j]);
	 }
	 memset(a,0,sizeof(a));
	 for(int i  = 1;i <= m ;i++)
	 {
	      for (int j = 1; j <= n; j++)
		  {
		    if(strstr(ex[i],key[j]))
			{
			  int p = strstr(ex[i],key[j]) - ex[i];
			  if(p == 0 && !islower(ex[i][p+strlen(key[j])]))
			  {	  a[i]++;
			     continue;
			  }
			  if(!islower(ex[i][p-1]) && !islower(ex[i][p+strlen(key[j])]) )
			  {
			    a[i]++;
				continue;
			  }
			}
		  }
	 }
	 printf("Excuse Set #%d\n",t);
	 t++;
   int max = 0 ;
   for (int i =1; i<= m ;i++ )
	   if(a[i] >max)
		   max = a[i];
   for(int i  = 1;i <= m ;i++)
	    if(a[i] == max)
			puts(ex1[i]);
   printf("\n");
  memset(a,0,sizeof(a)); 
  }
  
  

return 0 ;
}
