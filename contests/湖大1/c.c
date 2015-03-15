// File Name: c.c
// Author: darkdream
// Created Time: 2013年07月16日 星期二 12时39分11秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>

int main(){

   //freopen("/home/plac/problem/input.txt","r",stdin);
   //freopen("/home/plac/problem/output.txt","w",stdout);
  int n; 
  while(scanf("%d",&n) != EOF)
  {
     int a[1000] = {0};
	 int sum[1000] = {0};
	 int tsum =0 ;
	 for(int i =1 ;i <= n;i ++)
	 { scanf("%d",&a[i]);
	   if(a[i] == 1 )
		  tsum ++;
	   sum[i] = tsum;
	 }
	 int max = sum[n] ;
	 for(int i =1 ;i <= n;i ++)
		 for(int j= i +1 ;j <= n;j ++)
		 {
		   if(sum[i-1] + sum[n]- sum[j] + (j-i + 1 -(sum[j] - sum[i-1])) > max)
		   {
		     max = sum[i-1] + sum[n] - sum[j] + (j - i + 1 -(sum[j]-sum[i-1]));
		   }
		 }
	 printf("%d\n",max);

  }
return 0 ;
}
