// File Name: uva712.c
// Author: darkdream
// Created Time: 2013年05月21日 星期二 17时35分59秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int POW(int a,int p )
{
  int sum = 1; 
  for(int i = 1;i <= p; i ++)
  {
    sum = sum*a;
  }
  return sum;
}
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n,t = 0 ;
   while(scanf("%d",&n) != EOF,n)
   {
	  t ++;
	  getchar();
	  int b[10000];
	  char str[10000];
      for(int i =1; i <= n;i ++)
       {
		  getchar();
		  scanf("%d",&b[i]);
		  getchar();
	   }
	  scanf("%s",str);
	  
	  
	  int m;
	  char temp[1000];
	  scanf("%d",&m);
	  getchar(); 
	  
	  printf("S-Tree #%d:\n",t);
	  char ans[1000] = {0};
	  for(int i = 1;i <=m ; i ++)
	  {
	    scanf("%s",temp);
		int sum = 0 ;
	   for(int j = 0; j < strlen(temp) ;j++ )
	   {
	      if(temp[b[j+1]-1] == '1')
			sum += POW(2,n-j-1);
            
	   }
	   ans[i-1] = str[sum];
	  }
	  puts(ans);
	printf("\n");
   }
return 0 ;
}
