// File Name: 数字的个数.c
// Author: darkdream
// Created Time: 2014年05月15日 星期四 19时40分51秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int ans[1000005][10];
void solve(){
   memset(ans,0,sizeof(ans));
   for(int i = 1;i <= 1000000;i ++)
   {
      int temp = i;
	  for(int j = 0 ;j <= 9 ;j ++)
		  ans[i][j] = ans[i-1][j];
	  while(temp)
	  {
	     ans[i][temp%10] ++; 
		 temp = temp/10; 
	  }
   }
}
int main(){
	clock_t en,be;
	be = clock();
	freopen("数字的个数.in","r",stdin);
	freopen("数字的个数.out","w",stdout); 
	solve();	
     int t; 
	 scanf("%d",&t);
	 
	 for(int i = 1;i <= t;i ++)
	 {
	   int a, b, d; 
	   scanf("%d %d %d",&a,&b,&d);
	   printf("%d\n",ans[b][d] - ans[a-1][d]);
	 }
	 en = clock();
	 //printf("%lf\n",(en-be)*1.0/CLOCKS_PER_SEC);
return 0 ;
}
