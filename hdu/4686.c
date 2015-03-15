// File Name: 4686.c
// Author: darkdream
// Created Time: 2013年08月17日 星期六 19时46分29秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
int a[2000];
int b[2000];
int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int n , m;  
   while(scanf("%d",&n) != EOF)
   {
      int sum = 0 ; 
	  for(int i =1 ;i<= n;i ++)
	  {
	      scanf("%d",&a[i]);
		  sum += a[i];
	  }
	  int temp ;
	  scanf("%d",&m);
	  for(int i= 1 ;i <= m;i ++)
		  scanf("%d",&temp);
	  if(sum == 0 )
		  printf("0.00\n");
	  else if(n == m)
		  printf("inf\n");
	  else printf("%.2lf\n",sum*1.0/(n-m));

   }
return 0 ;
}
