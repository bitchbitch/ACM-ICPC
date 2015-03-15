// File Name: 9.c
// Author: darkdream
// Created Time: 2013年09月28日 星期六 12时59分53秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define LL long long
#define mod 95041567
//freopen("/home/plac/problem/input.txt","r",stdin);
//freopen("/home/plac/problem/output.txt","w",stdout);
int a[1000000];
int b[1000000];
int visit[mod];
int change1(int n)
{
  b[1] = a[n];
  for(int i= 2; i <= n+1;i ++)
	  b[i] = (b[i-1] + a[i-1]) % mod;
}
int change2(int n)
{
  a[1] = b[n];
  for(int i= 2; i <= n+1;i ++)
	  a[i] = (a[i-1] + b[i-1]) % mod;
}
int main(){
   int n;
   memset(visit,0,sizeof(visit));
   freopen("output.txt","w",stdout);
   a[1] = 1 ;
   scanf("%d",&n);
   printf("1\n");
   for(int i = 2; i <= 50;i ++)
   {
      if(i %2 == 0 )
	  {	  change1(i-1);
			 printf("%d\n",b[i]);
	  }
	  else{ change2(i-1);
			 printf("%d\n",a[i]);
	  }
   
   }

return 0 ;
}
