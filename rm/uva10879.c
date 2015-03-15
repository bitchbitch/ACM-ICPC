// File Name: uva10879.c
// Author: darkdream
// Created Time: 2013年03月02日 星期六 20时29分24秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  int n ;
  scanf("%d",&n);
  for(int i = 1;i <= n ;i ++)
  {
    int a , j , k;
	scanf("%d",&a);
	printf("Case #%d: %d = ",i,a);
    for(j = 2; j <= sqrt(a) ;j ++)
		if(a %j == 0)
		{printf("%d * %d = ",j , a/j);
		 break;
		}
	for( k = j+1; k <= sqrt(a); k++)
		if(a % k == 0)
		{
		 printf("%d * %d\n",k, a/k);
		 break;
		}


  }
return 0 ;
}
