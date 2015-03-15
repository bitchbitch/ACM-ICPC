// File Name: b.c
// Author: darkdream
// Created Time: 2014年05月02日 星期五 23时42分24秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){
    int n ,t , c; 
	scanf("%d %d %d",&n,&t,&c);
	int sum = 0 ; 
	int ans = 0 ; 
	for(int i = 1;i<= n;i ++)
	{
	    int temp ; 
		scanf("%d",&temp);
		if(temp <= t)
			sum += 1; 
		else {
		  if(sum >= c)
			ans += (sum - c + 1);
		   sum = 0 ;
		   
		}
	}
		  if(sum >= c)
			ans += (sum - c + 1);

	printf("%d\n",ans);
return 0 ;
}
