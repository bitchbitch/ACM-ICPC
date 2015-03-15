// File Name: uva10050.c
// Author: darkdream
// Created Time: 2013年05月16日 星期四 21时28分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
   int t ;
   scanf("%d",&t);
   while(t--)
   {
     int k ,n,temp;
	 int a[10000];
	 memset(a,0,sizeof(a));
	 scanf("%d %d",&k,&n);
	 for(int i = 1;i <= n;i ++)
	 {
	    scanf("%d",&temp);
		int t = temp ;
		while(temp <= k)
		{
		   a[temp] = 1 ;
		   temp = temp +t;

		}
	 }
	 int sum = 0;
	 for(int i = 1; i <= k;i ++)
	 {
	   if(i % 7 != 0 && i % 7 != 6)
		   if(a[i] == 1)
			   sum++;
	 }
	 printf("%d\n",sum);

   }
return 0 ;
}
