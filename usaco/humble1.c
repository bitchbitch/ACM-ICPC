// File Name: humble.c
// Author: darkdream
// Created Time: 2014年01月14日 星期二 15时51分00秒
/*
ID: dream.y1
PROG: humble
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
long long  num[100005];
int hs[104];
int a[104];
int main(){ 
   freopen("humble.in","r",stdin);
   freopen("humble.out","w",stdout);
  int n ,m; 
  scanf("%d %d",&n,&m);
  for(int i =1;i <= n;i ++)
	  scanf("%d",&a[i]);
  num[0] = 1; 
  for(int i =1;i <= m;i ++)
  {
	  long long min = num[i-1] * a[1];
	  for(int j =1; j <= n;j ++)
	  {

	    while(1ll* a[j] * num[hs[j]] <= 1ll*num[i-1])
		{
		    hs[j] = hs[j] + 1;
		}
		if(a[j] * num[hs[j]] <= min )
			min = a[j] * num[hs[j]];
	  }
	  num[i] = min;
  }
  printf("%lld\n",num[m]);
  return 0 ;
}
