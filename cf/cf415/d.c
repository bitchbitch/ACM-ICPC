// File Name: d.c
// Author: darkdream
// Created Time: 2014年04月07日 星期一 01时29分35秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>
#define M 1000000007
long long  ans[2001][2001];
int a[2001][2001];
int num[2001];
int main(){

   //freopen("/home/darkdream/problem/input.txt","r",stdin);
   //freopen("/home/darkdream/problem/output.txt","w",stdout);
   int n , k ; 
   scanf("%d %d",&n,&k);
   memset(a,0,sizeof(a));
   memset(ans,0,sizeof(ans));
   memset(num,0,sizeof(num));
   for(int i = 1;i <= n; i ++)
   {
	  for(int j = 1;j <= i; j++)
	  {
	     if(i % j == 0 )
		 {	num[i] ++ ; 
		    a[i][num[i]] = j; 
		 }
	  }
   }
  for(int i = 1;i <= n;i ++)
	  ans[1][i] = 1; 
  for(int i = 2;i <= k;i ++)
     {
	   for(int j = 1;j <= n;j ++)
		   for(int s = 1; s <= num[j]; s++)
		   {	 ans[i][j] = ( ans[i][j]+ ans[i-1][a[j][s]]) % M;
		      //   printf("%I64d %d %d\n",ans[i-1][a[j][s]],i,j);
		   }
	 }
  long long rans = 0 ; 
  for(int i = 1; i <= n;i ++)
     rans = (rans + ans[k][i]) % M ; 
  printf("%I64d\n",rans);
return 0 ;
}
